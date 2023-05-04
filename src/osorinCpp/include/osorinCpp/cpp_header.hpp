#include "rclcpp/rclcpp.hpp"

class MyNode : public rclcpp::Node{
    public:
        MyNode(): Node("My_node"){
            RCLCPP_INFO(this->get_logger(),"Test cpp node");
        }
    private:
};