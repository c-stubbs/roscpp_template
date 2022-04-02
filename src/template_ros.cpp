/*
    Author: Chandler Stubbs
    Date: Apr 1, 2022
    Description:
        Template for _ros file that hadles high level ros initiation and callback spinning.
*/

#include <memory>
#include "roscpp_template/template_node.hpp"
#include "rclcpp/rclcpp.hpp"

int main(int argc, char *argv[])
{
    // rclcpp::init initializes ros
    rclcpp::init(argc, argv);

    // This creates a pointer to the node_handle which can be passed through to the _node file
    // to be used for ros specific functions such as nh->get_logger()
    rclcpp::Node::SharedPtr nh_ = rclcpp::Node::make_shared("template_node");

    // Creates and instance of the TemplateNode class, named "node". This references the template_node.cpp file
    // which sets up all ros functionality such as publishers, subscribers, services, actions, timers, etc.
    // The node handle is passed through to the class so that it can be used in the class functions.
    TemplateNode node(nh_);

    // Spin tells ros to trigger all the callback functions that need to be called. For example, if a function was
    // bound to a timer of 0.5 seconds, spin(nh) would loop until the 0.5 seconds is up and then trigger the function,
    // then wait until the next 0.5 second interval.
    rclcpp::spin(nh_);

    // If something triggers ros to abort, such as a ctrl+c from the user, the program comes out of spin and then meets
    // shutdown() which makes everything shutdown nicely.
    rclcpp::shutdown();
    return 0;
}