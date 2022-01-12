#include <exmp/exmp_node.hpp>
#include <torch/torch.h>
#include <iostream>
NodeExample::NodeExample()
{
    this->a = 0;
    float rate = 5;
    auto duration = ros::Duration(1/rate);
    this->pub =  this->nh.advertise<std_msgs::UInt8>("/exmp/num",20);
    this->t = this->nh.createTimer(duration, &NodeExample::publishMessage,this);

}
void NodeExample::publishMessage(const ros::TimerEvent& event)
{
    std_msgs::UInt8 new_msg;
    new_msg.data = this->a;
    this->a ++;
    this->pub.publish(new_msg);
    if (this->a >= 255)
    {
        this->a = 0;
    }
    torch::Tensor tensor = torch::rand({1, 2});
    std::cout << tensor << std::endl;
}



int main(int argc, char **argv)
{
    ros::init(argc, argv, "exmp_node");
    NodeExample nd_ex;
    ros::spin();
    return EXIT_SUCCESS;

}

