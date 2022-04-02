/*
    Author: Chandler Stubbs
    Date: Apr 1, 2022
    Description:
        Template node file. Handles the callback functions and other do-somethings as necessary.
*/

#include <chrono>

#include "template/template_node.hpp"
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

TemplateNode::TemplateNode(rclcpp::Node::SharedPtr nh)
    : nh_(nh) , count_(0)
{
  publisher_ = nh_->create_publisher<std_msgs::msg::String>("topic", 10);
  timer_ = nh_->create_wall_timer(100ms, std::bind(&TemplateNode::step, nh_));
}

void TemplateNode::step()
{
  auto message = std_msgs::msg::String();
  message.data = "Hello, world! " + std::to_string(count_++);
  RCLCPP_INFO(nh_->get_logger(), "Publisher: '%s'", message.data.c_str());
  publisher_->publish(message);
}
