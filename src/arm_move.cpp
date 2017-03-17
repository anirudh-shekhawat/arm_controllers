
/* Author: Sachin Chitta, Dave Coleman */

#include <moveit/move_group_interface/move_group.h>	 //Changed from move_group_interface.h					
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <moveit_visual_tools/moveit_visual_tools.h>

#include <ros/console.h>
#include <ros/console.h>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "move_arm_interface");
  ros::NodeHandle node_handle;
  ros::AsyncSpinner spinner(1);
  spinner.start();


 if( ros::console::set_logger_level(ROSCONSOLE_DEFAULT_NAME, ros::console::levels::Debug) )
    ros::console::notifyLoggerLevelsChanged();


  static const std::string PLANNING_GROUP = "manipulator"; //Changed from right_arm
  ROS_INFO_NAMED("arm_move","STARTING MOVEMENT SCRIPT");
         
  moveit::planning_interface::MoveGroup move_group(PLANNING_GROUP);

  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;  

  ros::Publisher display_publisher = node_handle.advertise<moveit_msgs::DisplayTrajectory>("/move_group/display_planned_path", 1, true);
  moveit_msgs::DisplayTrajectory display_trajectory;
  
  ROS_INFO("Reference frame: %s", move_group.getPlanningFrame().c_str());

  ROS_INFO("End effector link: %s", move_group.getEndEffectorLink().c_str());

  const robot_state::JointModelGroup *joint_model_group =
  move_group.getCurrentState()->getJointModelGroup(PLANNING_GROUP);

geometry_msgs::PoseStamped current_pose_message , home_pose_message ;
current_pose_message=move_group.getCurrentPose(move_group.getEndEffectorLink() );
home_pose_message = current_pose_message ;
sleep(2.0);
ROS_INFO("CURRENT_STATE_POSITION_X: %f",current_pose_message.pose.position.x);
ROS_INFO("CURRENT_STATE_POSITION_Y: %f",current_pose_message.pose.position.y);
ROS_INFO("CURRENT_STATE_POSITION_Z: %f",current_pose_message.pose.position.z);
ROS_INFO("CURRENT_STATE_ORIENTATION_X: %f",current_pose_message.pose.orientation.x);
ROS_INFO("CURRENT_STATE_ORIENTATION_y: %f",current_pose_message.pose.orientation.y);
ROS_INFO("CURRENT_STATE_ORIENTATION_z: %f",current_pose_message.pose.orientation.z);
ROS_INFO("CURRENT_STATE_ORIENTATION_w: %f",current_pose_message.pose.orientation.w);



move_group.setPlanningTime(60*5);
move_group.setGoalTolerance(.001);

move_group.setPositionTarget(0.28,0.7,0.8,move_group.getEndEffectorLink());

moveit::planning_interface::MoveGroup::Plan my_plan;

  bool success = move_group.plan(my_plan);

   ROS_INFO(" plan 1 (position goal) %s",success?"":"FAILED");

move_group.move();
sleep(2.0);

geometry_msgs::PoseStamped pose_message;
pose_message=move_group.getCurrentPose(move_group.getEndEffectorLink() );

ROS_INFO("CURRENT_STATE_POSITION_X: %f",pose_message.pose.position.x);
ROS_INFO("CURRENT_STATE_POSITION_Y: %f",pose_message.pose.position.y);
ROS_INFO("CURRENT_STATE_POSITION_Z: %f",pose_message.pose.position.z);
ROS_INFO("CURRENT_STATE_ORIENTATION_X: %f",pose_message.pose.orientation.x);
ROS_INFO("CURRENT_STATE_ORIENTATION_y: %f",pose_message.pose.orientation.y);
ROS_INFO("CURRENT_STATE_ORIENTATION_z: %f",pose_message.pose.orientation.z);
ROS_INFO("CURRENT_STATE_ORIENTATION_w: %f",pose_message.pose.orientation.w);


 
  move_group.setPositionTarget(0.58,0.28,0.48,move_group.getEndEffectorLink());

  moveit::planning_interface::MoveGroup::Plan my_plan_2;

  success = move_group.plan(my_plan_2);

  ROS_INFO(" plan 2(position goal) %s",success?"":"FAILED");


move_group.move();
sleep(2.0);
  
geometry_msgs::PoseStamped pose_message_new;
pose_message_new=move_group.getCurrentPose(move_group.getEndEffectorLink() );

ROS_INFO("CURRENT_STATE_POSITION_X: %f",pose_message_new.pose.position.x);
ROS_INFO("CURRENT_STATE_POSITION_Y: %f",pose_message_new.pose.position.y);
ROS_INFO("CURRENT_STATE_POSITION_Z: %f",pose_message_new.pose.position.z);
ROS_INFO("CURRENT_STATE_ORIENTATION_X: %f",pose_message_new.pose.orientation.x);
ROS_INFO("CURRENT_STATE_ORIENTATION_y: %f",pose_message_new.pose.orientation.y);
ROS_INFO("CURRENT_STATE_ORIENTATION_z: %f",pose_message_new.pose.orientation.z);
ROS_INFO("CURRENT_STATE_ORIENTATION_w: %f",pose_message_new.pose.orientation.w);



//move_group.setOrientationTarget (0,0,0,1.0,move_group.getEndEffectorLink());
  move_group.setPositionTarget(0.28,0.7,0.8,move_group.getEndEffectorLink());
  moveit::planning_interface::MoveGroup::Plan my_plan_3;

  success = move_group.plan(my_plan_3);

  ROS_INFO(" plan 3(Position goal) %s",success?"":"FAILED");


move_group.move();
sleep(2.0);

geometry_msgs::PoseStamped pose_message_or;
pose_message_or=move_group.getCurrentPose(move_group.getEndEffectorLink() );

ROS_INFO("CURRENT_STATE_POSITION_X: %f",pose_message_or.pose.position.x);
ROS_INFO("CURRENT_STATE_POSITION_Y: %f",pose_message_or.pose.position.y);
ROS_INFO("CURRENT_STATE_POSITION_Z: %f",pose_message_or.pose.position.z);
ROS_INFO("CURRENT_STATE_ORIENTATION_X: %f",pose_message_or.pose.orientation.x);
ROS_INFO("CURRENT_STATE_ORIENTATION_y: %f",pose_message_or.pose.orientation.y);
ROS_INFO("CURRENT_STATE_ORIENTATION_z: %f",pose_message_or.pose.orientation.z);
ROS_INFO("CURRENT_STATE_ORIENTATION_w: %f",pose_message_or.pose.orientation.w);

move_group.setPositionTarget(home_pose_message.pose.position.x,home_pose_message.pose.position.y,home_pose_message.pose.position.z,move_group.getEndEffectorLink());
  moveit::planning_interface::MoveGroup::Plan my_plan_4;

  success = move_group.plan(my_plan_4);

  ROS_INFO(" plan 4(Position goal) %s",success?"":"FAILED");


move_group.move();
sleep(2.0);

pose_message_or=move_group.getCurrentPose(move_group.getEndEffectorLink() );

ROS_INFO("CURRENT_STATE_POSITION_X: %f",pose_message_or.pose.position.x);
ROS_INFO("CURRENT_STATE_POSITION_Y: %f",pose_message_or.pose.position.y);
ROS_INFO("CURRENT_STATE_POSITION_Z: %f",pose_message_or.pose.position.z);
ROS_INFO("CURRENT_STATE_ORIENTATION_X: %f",pose_message_or.pose.orientation.x);
ROS_INFO("CURRENT_STATE_ORIENTATION_y: %f",pose_message_or.pose.orientation.y);
ROS_INFO("CURRENT_STATE_ORIENTATION_z: %f",pose_message_or.pose.orientation.z);
ROS_INFO("CURRENT_STATE_ORIENTATION_w: %f",pose_message_or.pose.orientation.w);

  // robot_state::RobotState start_state(*move_group.getCurrentState());
  // geometry_msgs::Pose start_pose2;
  // start_pose2.orientation.w = 1.0;
  // start_pose2.position.x = 0.55;
  // start_pose2.position.y = -0.05;
  // start_pose2.position.z = 0.8;
  
  // start_state.setFromIK(joint_model_group, start_pose2);
  // move_group.setStartState(start_state);
  
  // // Now we will plan to the earlier pose target from the new 
  // // start state that we have just created.
  // move_group.setPoseTarget(target_pose1);
  // success = move_group.plan(my_plan);

  // ROS_INFO("Visualizing plan 3 (constraints) %s",success?"":"FAILED");
  // /* Sleep to give Rviz time to visualize the plan. */
  // sleep(10.0);

  // // When done with the path constraint be sure to clear it.
  // move_group.clearPathConstraints();

  // Cartesian Paths
  // ^^^^^^^^^^^^^^^
  // You can plan a cartesian path directly by specifying a list of waypoints 
  // for the end-effector to go through. Note that we are starting 
  // from the new start state above.  The initial pose (start state) does not
  // need to be added to the waypoint list.
  // std::vector<geometry_msgs::Pose> waypoints;

  // geometry_msgs::Pose target_pose3 = start_pose2;
  // target_pose3.position.x += 0.2;
  // target_pose3.position.z += 0.2;
  // waypoints.push_back(target_pose3);  // up and out

  // target_pose3.position.y -= 0.2;
  // waypoints.push_back(target_pose3);  // left

  // target_pose3.position.z -= 0.2;
  // target_pose3.position.y += 0.2;
  // target_pose3.position.x -= 0.2;
  // waypoints.push_back(target_pose3);  // down and right (back to start)

  // We want the cartesian path to be interpolated at a resolution of 1 cm
  // which is why we will specify 0.01 as the max step in cartesian
  // translation.  We will specify the jump threshold as 0.0, effectively
  // disabling it.
  // moveit_msgs::RobotTrajectory trajectory;
  // double fraction = move_group.computeCartesianPath(waypoints,
  //                                              0.01,  // eef_step
  //                                              0.0,   // jump_threshold
  //                                              trajectory);

  // ROS_INFO("Visualizing plan 4 (cartesian path) (%.2f%% acheived)",
  //       fraction * 100.0);    
  /* Sleep to give Rviz time to visualize the plan. */
  //sleep(15.0);


  

  ros::shutdown();
  return 0;
}
