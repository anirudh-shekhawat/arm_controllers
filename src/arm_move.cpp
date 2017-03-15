
/* Author: Sachin Chitta, Dave Coleman */

#include <moveit/move_group_interface/move_group.h>	 //Changed from move_group_interface.h					
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <moveit_visual_tools/moveit_visual_tools.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "move_group_interface_tutorial");
  ros::NodeHandle node_handle;
  ros::AsyncSpinner spinner(1);
  spinner.start();

  static const std::string PLANNING_GROUP = "manipulator"; //Changed from right_arm
ROS_INFO_NAMED("arm_move","STARTING MOVEMENT SCRIPT");
  // The :move_group_interface:`MoveGroup` class can be easily
  // setup using just the name of the planning group you would like to control and plan for.		         
  moveit::planning_interface::MoveGroup move_group(PLANNING_GROUP);

  const robot_state::JointModelGroup *joint_model_group =
  move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);

  ROS_INFO_NAMED("arm_move", "Reference frame: %s", move_group.getPlanningFrame().c_str());
  ROS_INFO_NAMED("arm_move", "End effector link: %s", move_group.getEndEffectorLink().c_str());

    geometry_msgs::Pose target_pose1;
  target_pose1.orientation.w = 1.0;
  target_pose1.position.x = 0.28;
  target_pose1.position.y = -0.7;
  target_pose1.position.z = 1.0;
  move_group.setPoseTarget(target_pose1);

moveit::planning_interface::MoveGroup::Plan my_plan;

bool success = move_group.plan(my_plan);

ROS_INFO_NAMED("arm_move", " plan 1 (pose goal) %s", success ? "" : "FAILED");

  move_group.move();

  ros::shutdown();
  return 0;
}
