#include "my_package/Node.hpp"

MyNode::MyNode()
{
    // Initialize the publisher
    example_publisher_ = nh_.advertise<std_msgs::Int32>("output_topic", 1000);

    // Initialize the subscriber
    example_subscriber_ = nh_.subscribe("input_topic", 1000, &MyNode::exampleCallback, this);
}

MyNode::~MyNode()
{
    // Cleanup can be handled here
}

void MyNode::run()
{
    ros::Rate loop_rate(10);  // 10 Hz
    while (ros::ok())
    {
        ros::spinOnce();
        loop_rate.sleep();
    }
}

void MyNode::exampleCallback(const std_msgs::Int32::ConstPtr& msg)
{
    int result = processData(msg->data);
    std_msgs::Int32 output_msg;
    output_msg.data = result;
    example_publisher_.publish(output_msg);

    ROS_INFO("Received: %d, Published: %d", msg->data, output_msg.data);
}

int MyNode::processData(int input)
{
    // Simple calculation, e.g., adding 10
    return input + 10;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "my_node");
    MyNode node;
    node.run();
    return 0;
}
