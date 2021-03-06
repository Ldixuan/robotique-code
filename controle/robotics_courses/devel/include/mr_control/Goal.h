// Generated by gencpp from file mr_control/Goal.msg
// DO NOT EDIT!


#ifndef MR_CONTROL_MESSAGE_GOAL_H
#define MR_CONTROL_MESSAGE_GOAL_H

#include <ros/service_traits.h>


#include <mr_control/GoalRequest.h>
#include <mr_control/GoalResponse.h>


namespace mr_control
{

struct Goal
{

typedef GoalRequest Request;
typedef GoalResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct Goal
} // namespace mr_control


namespace ros
{
namespace service_traits
{


template<>
struct MD5Sum< ::mr_control::Goal > {
  static const char* value()
  {
    return "937c9679a518e3a18d831e57125ea522";
  }

  static const char* value(const ::mr_control::Goal&) { return value(); }
};

template<>
struct DataType< ::mr_control::Goal > {
  static const char* value()
  {
    return "mr_control/Goal";
  }

  static const char* value(const ::mr_control::Goal&) { return value(); }
};


// service_traits::MD5Sum< ::mr_control::GoalRequest> should match
// service_traits::MD5Sum< ::mr_control::Goal >
template<>
struct MD5Sum< ::mr_control::GoalRequest>
{
  static const char* value()
  {
    return MD5Sum< ::mr_control::Goal >::value();
  }
  static const char* value(const ::mr_control::GoalRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::mr_control::GoalRequest> should match
// service_traits::DataType< ::mr_control::Goal >
template<>
struct DataType< ::mr_control::GoalRequest>
{
  static const char* value()
  {
    return DataType< ::mr_control::Goal >::value();
  }
  static const char* value(const ::mr_control::GoalRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::mr_control::GoalResponse> should match
// service_traits::MD5Sum< ::mr_control::Goal >
template<>
struct MD5Sum< ::mr_control::GoalResponse>
{
  static const char* value()
  {
    return MD5Sum< ::mr_control::Goal >::value();
  }
  static const char* value(const ::mr_control::GoalResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::mr_control::GoalResponse> should match
// service_traits::DataType< ::mr_control::Goal >
template<>
struct DataType< ::mr_control::GoalResponse>
{
  static const char* value()
  {
    return DataType< ::mr_control::Goal >::value();
  }
  static const char* value(const ::mr_control::GoalResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace ros

#endif // MR_CONTROL_MESSAGE_GOAL_H
