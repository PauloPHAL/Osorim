cmake_minimum_required(VERSION 3.8)
project(osorinCpp)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclpy REQUIRED)

#Include cpp "Include" directorys
include_directories(include)

# create cpp executable
add_executable(cpp_exe src/cppNode.cpp)
ament_target_dependencies(cpp_exe rclcpp)

install(TARGETS
  cpp_exe
  DESTINATION lib/${PROJECT_NAME}
)

ament_python_install_package(${PROJECT_NAME})

install(PROGRAMS
  scripts/py_node.py
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
