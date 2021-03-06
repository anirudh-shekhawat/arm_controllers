cmake_minimum_required(VERSION 2.8.3)
project(test_controller)


find_package(cmake_modules REQUIRED)
find_package(Eigen REQUIRED)
include_directories(SYSTEM ${Boost_INCLUDE_DIR} ${EIGEN_INCLUDE_DIRS})

## Add support for C++11, supported in ROS Kinetic and newer
# add_definitions(-std=c++11)
## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  moveit_core
  moveit_ros_planning
  moveit_ros_planning_interface
  std_msgs
  trajectory_msgs
)


###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if you package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
#catkin_package(
#  INCLUDE_DIRS include
#  LIBRARIES test_controller
#  CATKIN_DEPENDS roscpp rospy std_msgs
#  DEPENDS system_lib
#)

catkin_package(
  #INCLUDE_DIRS include
  #LIBRARIES test_controller
  CATKIN_DEPENDS moveit_core roscpp
  DEPENDS system_lib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
# include_directories(include)
include_directories(
  ${catkin_INCLUDE_DIRS}
)


add_executable(test_client  src/test_client.cpp)
target_link_libraries(test_client ${catkin_LIBRARIES})
add_dependencies(test_client test_controller_gencpp)

add_executable(arm_publish  src/arm_publish.cpp)
target_link_libraries(arm_publish ${catkin_LIBRARIES})
add_dependencies(arm_publish test_controller_gencpp)

add_executable(arm_move  src/arm_move.cpp)
target_link_libraries(arm_move ${catkin_LIBRARIES})
add_dependencies(arm_move test_controller_gencpp)

