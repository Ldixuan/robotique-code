#include <dirent.h>
#include <sys/types.h>
#include <ostream>
#include <chrono>

#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <std_srvs/Trigger.h>
#include <tf2_ros/transform_listener.h>

#include "mr_control/Goal.h"

#include <geometry_msgs/PoseArray.h>
#include <geometry_msgs/PoseStamped.h>
#include <std_msgs/Float64.h>
#include <nav_msgs/Path.h>
#include <tf/transform_datatypes.h>
#include <ros/package.h>
#include <angles/angles.h>

#include "mr_control/csv_reader.hpp"

using coords = std::tuple<float, float, float>;
using error = std::tuple<float, float>;

class ComputerError {
  public:
    ComputerError(ros::NodeHandle &nh, const ros::NodeHandle &nh_p);
    error computer();

  private:
    void loadPath();
    void updateControlPose();
    void updateTargetPose();
    void displayError(const ros::TimerEvent &event);
    bool goalCB(std_srvs::Trigger::Request& req, std_srvs::Trigger::Response& resp);
    bool stopCB(std_srvs::Trigger::Request& req, std_srvs::Trigger::Response& resp);

    double computeLateralError();
    double computeAngleError();

    ros::NodeHandle nh_;
    ros::NodeHandle nh_p_;

    ros::ServiceServer srv_;
    ros::ServiceServer stop_srv_;

    ros::Timer timer_;

    std::string path_;
    std::vector<coords> path_to_follow_;

    tf2_ros::Buffer tfBuffer_;
    tf2_ros::TransformListener odom_to_map_listener_;
    coords pose_;
    coords pose_target_;

    int index_target_pose;
};

ComputerError::ComputerError(ros::NodeHandle &nh, const ros::NodeHandle &nh_p )
  : nh_(nh)
  , nh_p_(nh_p)
  , path_("")
  , odom_to_map_listener_(tfBuffer_)
{ 
  timer_ = nh.createTimer(ros::Duration(0.1), &ComputerError::displayError, this, false, false);

  srv_ = nh_p_.advertiseService("Goal", &ComputerError::goalCB, this);
  stop_srv_ = nh_p_.advertiseService("Stop", &ComputerError::stopCB, this);

  loadPath();
}

template <typename T1>
void yawToQuatRosCopy(const double& yaw, T1& q) {
  q.x = 0.0;
  q.y = 0.0;
  q.z = sin(yaw * 0.5);
  q.w = cos(yaw * 0.5);
}

template <typename T1>
double quatRosToYawCopy(const T1& q) {
  // yaw (z-axis rotation)
  const double siny_cosp = 2.0 * (q.w * q.z + q.x * q.y);
  const double cosy_cosp = 1.0 - 2.0 * (q.y * q.y + q.z * q.z);
  return atan2(siny_cosp, cosy_cosp);
}


std::pair<nav_msgs::Path, geometry_msgs::PoseArray> rosPathConverterCopy(const std::vector<coords>& data)
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
    yawToQuatRosCopy(std::get<2>(d), ps.pose.orientation);
    path_to_publish.poses.push_back(ps);
    pose_array_to_publish.poses.push_back(ps.pose);
  }
  return {path_to_publish, pose_array_to_publish};
}

std::vector<coords> pathConverterCopy(const std::vector<std::vector<std::string>> &raw_data)
{
  std::vector<coords> res(raw_data.size());
  std::size_t i =0;
  for (auto&& line : raw_data)
    res[i++] = {stod(line[0]), stod(line[1]), stod(line[2])};
  return res;
}

void ComputerError::updateControlPose()
{
  try
  {
    auto &&ts = tfBuffer_.lookupTransform("map", "base_link", ros::Time(0));
    pose_= {ts.transform.translation.x, ts.transform.translation.y, quatRosToYawCopy(ts.transform.rotation)};
  }
  catch (tf2::TransformException &ex)
  {
    ROS_WARN("%s", ex.what());
    ros::Duration(1.0).sleep();
    return;
  }
}

void ComputerError::updateTargetPose(){
  
  
  if(index_target_pose < path_to_follow_.size() - 1){
    pose_target_ = path_to_follow_[index_target_pose];
  }
  
}

void ComputerError::loadPath()
{
  auto path = ros::package::getPath("mr_control");
  std::ostringstream ss;
  ss << path << "/path/path_to_follow.path";
  ROS_INFO("Loading path from: %s", ss.str().c_str());
  path_ = ss.str();
  CSVReader reader{path_};
  path_to_follow_ = pathConverterCopy(reader.getData());
}

void ComputerError::displayError(const ros::TimerEvent &event){
  error current_error = computer();

  ROS_INFO_STREAM("lateral error : " << std::get<0>(current_error) << ", angle error : " << std::get<1>(current_error));
}

bool ComputerError::goalCB(std_srvs::Trigger::Request& req, std_srvs::Trigger::Response& resp){
  timer_.start();

  return true;
}

bool ComputerError::stopCB(std_srvs::Trigger::Request& req, std_srvs::Trigger::Response& resp){
  timer_.stop();

  return true;
}

error ComputerError::computer(){
  updateControlPose();
  updateTargetPose();

  double error_lat = computeLateralError();
  double error_theta = computeAngleError();

  return {error_lat, error_theta};


} 

double ComputerError::computeLateralError(){
  float path_x = std::get<0>(pose_target_);
  float path_y = std::get<1>(pose_target_);
  float path_yaw_angle = std::get<2>(pose_target_);

  float pose_x = std::get<0>(pose_);
  float pose_y = std::get<1>(pose_);

  const double c_yaw = std::cos(path_yaw_angle);
  const double s_yaw = std::sin(path_yaw_angle);

  const double dx = pose_x - path_x;
  const double dy = pose_y - path_y;

  return (dx * s_yaw) - (dy * c_yaw);

}

double ComputerError::computeAngleError(){
  float pose_yaw = std::get<2>(pose_);
  float path_yaw = std::get<2>(pose_target_);

  return  angles::normalize_angle(pose_yaw - path_yaw);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "computer_error");
  ros::NodeHandle nh;
  ros::NodeHandle nh_p("~");
  ComputerError ComputerError(nh, nh_p);

  ros::spin();

  return 0;
}