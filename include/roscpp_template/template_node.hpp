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
#include "roscpp_template/srv/reset_count.hpp"

#include "rcl_interfaces/msg/parameter_event.hpp"
#include "rcl_interfaces/msg/set_parameters_result.hpp"

class TemplateNode
{
public:
    // Header for the node
    TemplateNode(rclcpp::Node::SharedPtr nh);

private:
    // Declaration of the class functions and variables
    void step();
    bool resetCountSrvCallback(const roscpp_template::srv::ResetCount::Request::SharedPtr, roscpp_template::srv::ResetCount::Response::SharedPtr);
    void dyncfgSetup();
    void declareDynamicParameters();

private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Service<roscpp_template::srv::ResetCount>::SharedPtr reset_count_srv_;
    rclcpp::Node::SharedPtr nh_;

    rcl_interfaces::msg::SetParametersResult parameterUpdate(const std::vector<rclcpp::Parameter> &parameters);
    rclcpp::AsyncParametersClient::SharedPtr priv_parameters_client_;
    rclcpp::node_interfaces::OnSetParametersCallbackHandle::SharedPtr param_cb_;
    rclcpp::Subscription<rcl_interfaces::msg::ParameterEvent>::SharedPtr parameter_event_sub_;

    int64_t count_ = 0;
    int64_t increment_ = 1;
    bool paused_ = false;
};

#endif // TEMPLATE_NODE_HPP