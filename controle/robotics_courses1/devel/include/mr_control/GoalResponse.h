// Generated by gencpp from file mr_control/GoalResponse.msg
// DO NOT EDIT!


#ifndef MR_CONTROL_MESSAGE_GOALRESPONSE_H
#define MR_CONTROL_MESSAGE_GOALRESPONSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace mr_control
{
template <class ContainerAllocator>
struct GoalResponse_
{
  typedef GoalResponse_<ContainerAllocator> Type;

  GoalResponse_()
    : success(false)
    , message()  {
    }
  GoalResponse_(const ContainerAllocator& _alloc)
    : success(false)
    , message(_alloc)  {
  (void)_alloc;
    }



   typedef uint8_t _success_type;
  _success_type success;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _message_type;
  _message_type message;





  typedef boost::shared_ptr< ::mr_control::GoalResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::mr_control::GoalResponse_<ContainerAllocator> const> ConstPtr;

}; // struct GoalResponse_

typedef ::mr_control::GoalResponse_<std::allocator<void> > GoalResponse;

typedef boost::shared_ptr< ::mr_control::GoalResponse > GoalResponsePtr;
typedef boost::shared_ptr< ::mr_control::GoalResponse const> GoalResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::mr_control::GoalResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::mr_control::GoalResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::mr_control::GoalResponse_<ContainerAllocator1> & lhs, const ::mr_control::GoalResponse_<ContainerAllocator2> & rhs)
{
  return lhs.success == rhs.success &&
    lhs.message == rhs.message;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::mr_control::GoalResponse_<ContainerAllocator1> & lhs, const ::mr_control::GoalResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace mr_control

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::mr_control::GoalResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::mr_control::GoalResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mr_control::GoalResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::mr_control::GoalResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mr_control::GoalResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::mr_control::GoalResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::mr_control::GoalResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "937c9679a518e3a18d831e57125ea522";
  }

  static const char* value(const ::mr_control::GoalResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x937c9679a518e3a1ULL;
  static const uint64_t static_value2 = 0x8d831e57125ea522ULL;
};

template<class ContainerAllocator>
struct DataType< ::mr_control::GoalResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "mr_control/GoalResponse";
  }

  static const char* value(const ::mr_control::GoalResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::mr_control::GoalResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "bool success\n"
"string message\n"
"\n"
;
  }

  static const char* value(const ::mr_control::GoalResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::mr_control::GoalResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.success);
      stream.next(m.message);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct GoalResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::mr_control::GoalResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::mr_control::GoalResponse_<ContainerAllocator>& v)
  {
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
    s << indent << "message: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.message);
  }
};

} // namespace message_operations
} // namespace ros

#endif // MR_CONTROL_MESSAGE_GOALRESPONSE_H
