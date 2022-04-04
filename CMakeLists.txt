cmake_minimum_required(VERSION 3.5)
project(roscpp_template)

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()


# find dependencies
find_package(ament_cmake REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(roscpp_template REQUIRED)
find_package(std_srvs REQUIRED)

# set a variable "dependencies" to call later
set(dependencies "rclcpp" "std_srvs" "std_msgs" "rosidl_default_generators" "roscpp_template")

# set a variable "template_node_SRC" to call later in place of the src files needed for the template pkg
set(template_node_SRCS
  src/template_ros.cpp
  src/template_node.cpp
)

rosidl_generate_interfaces(${PROJECT_NAME}
  "srv/ExampleService.srv"
)
# Add the executable object for the template pkg sources
add_executable(template_node ${template_node_SRCS})

# Target the dependencies
ament_target_dependencies(template_node ${dependencies})

# Find the include directory where headers are located
target_include_directories(template_node
  PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Actually build and install the package
install(TARGETS template_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
