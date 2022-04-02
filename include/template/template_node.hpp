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

class TemplateNode
{
public:
  TemplateNode(rclcpp::Node::SharedPtr nh);

private:
  void step();
  size_t count_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Node::SharedPtr nh_;
};

#endif  // TEMPLATE_NODE_HPP