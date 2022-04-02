/*
    Author: Chandler Stubbs
    Date: Apr 1, 2022
    Description:
        Template for _ros file that hadles high level ros initiation and callback spinning.
*/

#include <memory>
#include "template/template_node.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv); 
  rclcpp::Node::SharedPtr nh_ = rclcpp::Node::make_shared("template_node");
  TemplateNode pid(nh_);
  rclcpp::spin(nh_);
  rclcpp::shutdown();
  return 0;
}