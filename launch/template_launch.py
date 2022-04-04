from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="roscpp_template",
            executable="template_node",
            name="template_node",
            output="screen",
            emulate_tty=True,
            parameters=[
                {"timer_period": 5.0}
            ]
        )
    ])
