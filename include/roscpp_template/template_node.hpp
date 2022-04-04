/*
    Author: Chandler Stubbs
    Date: Apr 1, 2022
    Description:
        Template header file.
*/

#ifndef TEMPLATE_NODE_HPP
#define TEMPLATE_NODE_HPP

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include <std_srvs/srv/empty.hpp>
#include <roscpp_template/srv/example_service.hpp>

class TemplateNode
{
public:
    // Header for the node
    TemplateNode(rclcpp::Node::SharedPtr nh);

private:
    // Declaration of the class functions and variables
    void step();
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Service<roscpp_template::srv::ExampleService>::SharedPtr service_;
    rclcpp::Node::SharedPtr nh_;
    int64_t count_;
    bool serviceCallback(const roscpp_template::srv::ExampleService::Request::SharedPtr, roscpp_template::srv::ExampleService::Response::SharedPtr);
};

#endif // TEMPLATE_NODE_HPP