#ifndef NODE_HPP
#define NODE_HPP

#include <ros/ros.h>
#include <std_msgs/Int32.h>

class MyNode
{
public:
    // Constructor
    MyNode();

    // Destructor
    ~MyNode();

    // Main loop function
    void run();

private:
    ros::NodeHandle nh_;

    // Publisher
    ros::Publisher example_publisher_;

    // Subscriber
    ros::Subscriber example_subscriber_;

    // Subscriber callback
    void exampleCallback(const std_msgs::Int32::ConstPtr& msg);

    // Helper method to perform calculations
    int processData(int input);
};

#endif // NODE_HPP
