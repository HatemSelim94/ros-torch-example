#ifndef EXMP_NODE_H
#define EXMP_NODE_H

// ROS includes
#include <ros/ros.h>
#include <ros/time.h>
#include <std_msgs/UInt8.h>

class NodeExample
{
    private:
    ros::Publisher pub;
    ros::NodeHandle nh;
    uint8_t a;
    ros::Timer t;
    public:
    // Constructor
    NodeExample();
    // Destructor
    //~NodeExample();
    void publishMessage(const ros::TimerEvent&);
    
};

#endif // EXMP_NODE_H