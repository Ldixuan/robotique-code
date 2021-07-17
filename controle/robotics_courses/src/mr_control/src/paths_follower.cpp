#include <dirent.h>
#include <sys/types.h>
#include <ostream>
#include <chrono>

#include <geometry_msgs/PoseArray.h>
#include <geometry_msgs/PoseStamped.h>
#include <std_msgs/Float64.h>
#include <nav_msgs/Path.h>
#include <tf/transform_datatypes.h>
#include <ros/package.h>
#include <angles/angles.h>
#include <math.h>

#include "mr_control/paths_follower.hpp"
#include "mr_control/csv_reader.hpp"


template <typename T1>
void yawToQuatRos(const double& yaw, T1& q) {
  q.x = 0.0;
  q.y = 0.0;
  q.z = sin(yaw * 0.5);
  q.w = cos(yaw * 0.5);
}

template <typename T1>
double quatRosToYaw(const T1& q) {
  // yaw (z-axis rotation)
  const double siny_cosp = 2.0 * (q.w * q.z + q.x * q.y);
  const double cosy_cosp = 1.0 - 2.0 * (q.y * q.y + q.z * q.z);
  return atan2(siny_cosp, cosy_cosp);
}


std::pair<nav_msgs::Path, geometry_msgs::PoseArray> rosPathConverter(const std::vector<coords>& data)
{
  nav_msgs::Path path_to_publish;
  geometry_msgs::PoseArray pose_array_to_publish;
  path_to_publish.header.frame_id = "map";
  pose_array_to_publish.header.frame_id = "map";
  for (auto &&d : data)
  {
    geometry_msgs::PoseStamped ps;
    ps.pose.position.x = std::get<0>(d);
    ps.pose.position.y = std::get<1>(d);
    ps.pose.position.z = 0.0;
    yawToQuatRos(std::get<2>(d), ps.pose.orientation);
    path_to_publish.poses.push_back(ps);
    pose_array_to_publish.poses.push_back(ps.pose);
  }
  return {path_to_publish, pose_array_to_publish};
}

std::vector<coords> pathConverter(const std::vector<std::vector<std::string>> &raw_data)
{
  std::vector<coords> res(raw_data.size());
  std::size_t i =0;
  for (auto&& line : raw_data)
    res[i++] = {stod(line[0]), stod(line[1]), stod(line[2])};
  return res;
}



PathsFollower::PathsFollower(ros::NodeHandle &nh, const ros::NodeHandle &nh_p)
  : nh_(nh)
  , nh_p_(nh_p)
  , path_("")
  , odom_to_map_listener_(tfBuffer_)
{ 
  timer_ = nh.createTimer(ros::Duration(0.1), &PathsFollower::controlLoop, this, false, false);
  srv_ = nh_p_.advertiseService("Goal", &PathsFollower::goalCB, this);
  stop_srv_ = nh_p_.advertiseService("Stop", &PathsFollower::stopCB, this);
  pub_left_ = nh_.advertise<std_msgs::Float64>("/gazebo/lwheel_traction_controller/command", 1);
  pub_right_ = nh_.advertise<std_msgs::Float64>("/gazebo/rwheel_traction_controller/command", 1);
  pub_point_ = nh_.advertise<geometry_msgs::PoseStamped>("/paths_follower/tracked_point", 1);
  pub_path_ = nh_.advertise<nav_msgs::Path>("/path", 1, true);
  pub_path_poses_ = nh_.advertise<geometry_msgs::PoseArray>("/path_poses", 1, true);
  loadPath();
}

void PathsFollower::updateControlPose()
{
  try
  {
    auto &&ts = tfBuffer_.lookupTransform("map", "base_link", ros::Time(0));
    pose_= {ts.transform.translation.x, ts.transform.translation.y, quatRosToYaw(ts.transform.rotation)};
  }
  catch (tf2::TransformException &ex)
  {
    ROS_WARN("%s", ex.what());
    ros::Duration(1.0).sleep();
    return;
  }
}


void PathsFollower::loadPath()
{
  auto path = ros::package::getPath("mr_control");
  std::ostringstream ss;
  ss << path << "/path/path_to_follow.path";
  ROS_INFO("Loading path from: %s", ss.str().c_str());
  path_ = ss.str();
  CSVReader reader{path_};
  path_to_follow_ = pathConverter(reader.getData());
  auto to_publish = rosPathConverter(path_to_follow_);
  pub_path_.publish(to_publish.first);
  pub_path_poses_.publish(to_publish.second);
}

bool PathsFollower::goalCB(std_srvs::Trigger::Request& req, std_srvs::Trigger::Response& resp)
{
  updateControlPose();
  pid_angle.init(ros::Time::now());
  pid_lateral.init(ros::Time::now());
  // TODO start to follow the path
  timer_.start();

  std_msgs::Float64 start;
  start.data = 1.0;
  pub_left_.publish(start);
  pub_right_.publish(start);


  return true;
}

bool PathsFollower::stopCB(std_srvs::Trigger::Request& req, std_srvs::Trigger::Response& resp)
{
  path_ = "";
  timer_.stop();
  std_msgs::Float64 stop;
  stop.data = 0.0;
  pub_left_.publish(stop);
  pub_right_.publish(stop);
  ROS_ERROR("aborting current path");
  return true;
}

//Summary:  compute the error of lateral

//Return : the error of lateral current.
double PathsFollower::computeLateralError(){
  float path_x = std::get<0>(pose_target_);
  float path_y = std::get<1>(pose_target_);
  float path_yaw_angle = angles::normalize_angle(std::get<2>(pose_target_));

  float pose_x = std::get<0>(pose_);
  float pose_y = std::get<1>(pose_);

  const double c_yaw = std::cos(path_yaw_angle);
  const double s_yaw = std::sin(path_yaw_angle);

  const double dx = pose_x - path_x;
  const double dy = pose_y - path_y;

  return (dx * s_yaw) - (dy * c_yaw);

}

//Summary:  compute the error of angle

//Return : the error of angle current.
double PathsFollower::computeAngleError(){
  float pose_yaw = angles::normalize_angle(std::get<2>(pose_));
  float path_yaw = angles::normalize_angle(std::get<2>(pose_target_));

  return  angles::normalize_angle(pose_yaw - path_yaw);
}

//Summary:  compute the distance of point current and point target

//Parameters:

//  pose_target : position of point target

//Return : the distance of position current and position target
float PathsFollower::computeDistance(coords pose_target){
  float distance_x = std::get<0>(pose_) - std::get<0>(pose_target);
  float distance_y = std::get<1>(pose_) - std::get<1>(pose_target);

  return sqrt(pow(distance_x, 2) + pow(distance_y, 2));
}

//Summary:  find the closest point

//Return : the position of closest point
coords PathsFollower::findClosestPoint(){
  coords closest_point;
  float closest_distance = INTMAX_MAX;

  for(auto point : path_to_follow_){
    auto d = computeDistance(point);
    if(d < closest_distance){
      closest_distance = d;
      closest_point = point;
    }
  }

  return closest_point;
}
void PathsFollower::controlLoop(const ros::TimerEvent &event)
{
  updateControlPose();
  pose_target_ = findClosestPoint();

  //std::tuple<double, double> e = computer();
  double e_angle = computeAngleError();
  double e_lateral = computeLateralError();
  
  double value_pid_angle = pid_angle.compute(e_angle, ros::Time::now());
  double value_pid_lateral = pid_lateral.compute(e_lateral, ros::Time::now());

  ROS_INFO_STREAM("possition x: " << std::get<0>(pose_) 
                    << " y: " << std::get<1>(pose_) 
                    << " yaw: " << std::get<2>(pose_)
                    << " target possitoon : (" << std::get<0>(pose_target_) << ", " << std::get<1>(pose_target_) << ", " << std::get<2>(pose_target_) << ")"
                    << " lateral error : " << e_lateral
                    << " angle error : " << e_angle);

  auto v = 0.5;
  auto w = value_pid_angle + value_pid_lateral;

  if(pose_target_ == path_to_follow_.back()){
    w = 0;
  }

  float radius_ = 0.1;
  float length_ = 0.46;

  auto phi1 = (2*v + length_ * w)/(2 * radius_);
  auto phi2 = (2*v - length_ * w)/(2 * radius_);

  std_msgs::Float64 data_left;
  data_left.data = phi1;
  std_msgs::Float64 data_right;
  data_right.data = phi2;
  pub_left_.publish(data_left);
  pub_right_.publish(data_right);
}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "path_follower");
  ros::NodeHandle nh;
  ros::NodeHandle nh_p("~");
  PathsFollower PathsFollower(nh, nh_p);

  ros::spin();

  return 0;
}
