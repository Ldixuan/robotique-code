#pragma once

#include <memory>
#include <vector>

#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <std_srvs/Trigger.h>
#include <tf2_ros/transform_listener.h>

#include "mr_control/Goal.h"
#include "../src/PID.cpp"

using coords = std::tuple<float, float, float>;
using err = std::tuple<double, double>;

class PathsFollower
{
public:
  PathsFollower(ros::NodeHandle &nh, const ros::NodeHandle &nh_p);

private:
  void loadPath();
  void controlLoop(const ros::TimerEvent &event);
  bool goalCB(std_srvs::Trigger::Request& req, std_srvs::Trigger::Response& resp);
  bool stopCB(std_srvs::Trigger::Request& req, std_srvs::Trigger::Response& resp);
  void updateControlPose();
  void cb_speed_ratio(const geometry_msgs::Twist::ConstPtr &msg);

  double computeLateralError();
  double computeAngleError();
  float computeDistance(coords pose_target);
  coords findClosestPoint();

  ros::NodeHandle nh_;
  ros::NodeHandle nh_p_;

  float max_tolerance_goal_norm_;
  float max_tolerance_goal_angle_;

  float speed_ratio_;

  // full filename and starting point
  std::string path_;
  std::vector<coords> path_to_follow_;

  ros::ServiceServer srv_;
  ros::ServiceServer stop_srv_;

  ros::Timer timer_;

  ros::Publisher pub_left_;
  ros::Publisher pub_right_;
  ros::Publisher pub_point_;
  ros::Publisher pub_path_;
  ros::Publisher pub_path_poses_;

  tf2_ros::Buffer tfBuffer_;
  tf2_ros::TransformListener odom_to_map_listener_;

  coords pose_;
  coords pose_target_;
  int index_target;

  PID pid_lateral{0.1, 0.01, 0.1};
  PID pid_angle{4.3, 0.01, 0.01};
};
