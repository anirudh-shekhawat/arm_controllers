
/* Author: Anirudh, Akash 
Path Planning experimentation code*/

#include <moveit/move_group_interface/move_group.h>	 //move_group_interface.h	is not a part of the move-it package for ROS-infigo			
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


  static const std::string PLANNING_GROUP = "manipulator"; //might vary for different arm models.
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
// current_pose_message=move_group.getCurrentPose(move_group.getEndEffectorLink() );
// home_pose_message = current_pose_message ;
// sleep(2.0);
// ROS_INFO("CURRENT_STATE_POSITION_X: %f",current_pose_message.pose.position.x);
// ROS_INFO("CURRENT_STATE_POSITION_Y: %f",current_pose_message.pose.position.y);
// ROS_INFO("CURRENT_STATE_POSITION_Z: %f",current_pose_message.pose.position.z);
// ROS_INFO("CURRENT_STATE_ORIENTATION_X: %f",current_pose_message.pose.orientation.x);
// ROS_INFO("CURRENT_STATE_ORIENTATION_y: %f",current_pose_message.pose.orientation.y);
// ROS_INFO("CURRENT_STATE_ORIENTATION_z: %f",current_pose_message.pose.orientation.z);
// ROS_INFO("CURRENT_STATE_ORIENTATION_w: %f",current_pose_message.pose.orientation.w);



move_group.setPlanningTime(60);
move_group.setGoalPositionTolerance(.10);
move_group.setPlannerId("RRTConnectkConfigDefault");  // changed to get better results compared to the default solver.

// move_group.setPositionTarget(current_pose_message.pose.position.x+0.1,current_pose_message.pose.position.y,
//   current_pose_message.pose.position.z,move_group.getEndEffectorLink());

// moveit::planning_interface::MoveGroup::Plan my_plan;

//   bool success = move_group.plan(my_plan);

//    ROS_INFO(" plan 1 (position goal) %s",success?"":"FAILED");

// move_group.move();
// sleep(2.0);

// geometry_msgs::PoseStamped pose_message;
// pose_message=move_group.getCurrentPose(move_group.getEndEffectorLink() );

// ROS_INFO("CURRENT_STATE_POSITION_X: %f",pose_message.pose.position.x);
// ROS_INFO("CURRENT_STATE_POSITION_Y: %f",pose_message.pose.position.y);
// ROS_INFO("CURRENT_STATE_POSITION_Z: %f",pose_message.pose.position.z);
// ROS_INFO("CURRENT_STATE_ORIENTATION_X: %f",pose_message.pose.orientation.x);
// ROS_INFO("CURRENT_STATE_ORIENTATION_y: %f",pose_message.pose.orientation.y);
// ROS_INFO("CURRENT_STATE_ORIENTATION_z: %f",pose_message.pose.orientation.z);
// ROS_INFO("CURRENT_STATE_ORIENTATION_w: %f",pose_message.pose.orientation.w);


 
//   move_group.setPositionTarget(pose_message.pose.position.x,pose_message.pose.position.y+0.5,
//     pose_message.pose.position.z,move_group.getEndEffectorLink());

//   moveit::planning_interface::MoveGroup::Plan my_plan_2;

//   success = move_group.plan(my_plan_2);

//   ROS_INFO(" plan 2(position goal) %s",success?"":"FAILED");


// move_group.move();
// sleep(2.0);
  
// geometry_msgs::PoseStamped pose_message_new;
// pose_message_new=move_group.getCurrentPose(move_group.getEndEffectorLink() );

// ROS_INFO("CURRENT_STATE_POSITION_X: %f",pose_message_new.pose.position.x);
// ROS_INFO("CURRENT_STATE_POSITION_Y: %f",pose_message_new.pose.position.y);
// ROS_INFO("CURRENT_STATE_POSITION_Z: %f",pose_message_new.pose.position.z);
// ROS_INFO("CURRENT_STATE_ORIENTATION_X: %f",pose_message_new.pose.orientation.x);
// ROS_INFO("CURRENT_STATE_ORIENTATION_y: %f",pose_message_new.pose.orientation.y);
// ROS_INFO("CURRENT_STATE_ORIENTATION_z: %f",pose_message_new.pose.orientation.z);
// ROS_INFO("CURRENT_STATE_ORIENTATION_w: %f",pose_message_new.pose.orientation.w);

// //move_group.setOrientationTarget (0,0,0,1.0,move_group.getEndEffectorLink());
//   move_group.setPositionTarget(pose_message_new.pose.orientation.x,pose_message_new.pose.orientation.y,
//    pose_message_new.pose.position.z+0.3,move_group.getEndEffectorLink());

//   moveit::planning_interface::MoveGroup::Plan my_plan_3;

//   success = move_group.plan(my_plan_3);

//   ROS_INFO(" plan 3(Position goal) %s",success?"":"FAILED");


// move_group.move();
// sleep(2.0);

// geometry_msgs::PoseStamped pose_message_or;
// pose_message_or=move_group.getCurrentPose(move_group.getEndEffectorLink() );

// ROS_INFO("CURRENT_STATE_POSITION_X: %f",pose_message_or.pose.position.x);
// ROS_INFO("CURRENT_STATE_POSITION_Y: %f",pose_message_or.pose.position.y);
// ROS_INFO("CURRENT_STATE_POSITION_Z: %f",pose_message_or.pose.position.z);
// ROS_INFO("CURRENT_STATE_ORIENTATION_X: %f",pose_message_or.pose.orientation.x);
// ROS_INFO("CURRENT_STATE_ORIENTATION_y: %f",pose_message_or.pose.orientation.y);
// ROS_INFO("CURRENT_STATE_ORIENTATION_z: %f",pose_message_or.pose.orientation.z);
// ROS_INFO("CURRENT_STATE_ORIENTATION_w: %f",pose_message_or.pose.orientation.w);

// move_group.setPositionTarget(home_pose_message.pose.position.x,home_pose_message.pose.position.y,home_pose_message.pose.position.z,move_group.getEndEffectorLink());
//   moveit::planning_interface::MoveGroup::Plan my_plan_4;

//   success = move_group.plan(my_plan_4);

//   ROS_INFO(" plan 4(Position goal) %s",success?"":"FAILED");


// move_group.move();
// sleep(2.0);

// pose_message_or=move_group.getCurrentPose(move_group.getEndEffectorLink() );

// ROS_INFO("CURRENT_STATE_POSITION_X: %f",pose_message_or.pose.position.x);
// ROS_INFO("CURRENT_STATE_POSITION_Y: %f",pose_message_or.pose.position.y);
// ROS_INFO("CURRENT_STATE_POSITION_Z: %f",pose_message_or.pose.position.z);
// ROS_INFO("CURRENT_STATE_ORIENTATION_X: %f",pose_message_or.pose.orientation.x);
// ROS_INFO("CURRENT_STATE_ORIENTATION_y: %f",pose_message_or.pose.orientation.y);
// ROS_INFO("CURRENT_STATE_ORIENTATION_z: %f",pose_message_or.pose.orientation.z);
// ROS_INFO("CURRENT_STATE_ORIENTATION_w: %f",pose_message_or.pose.orientation.w);

geometry_msgs::Pose home_target ;
home_target.position.x = 0.94;
home_target.position.y = 0;
home_target.position.z = 1.0;

move_group.setPositionTarget(home_target.position.x,home_target.position.y ,
  home_target.position.z,move_group.getEndEffectorLink());

moveit::planning_interface::MoveGroup::Plan my_plan;

  bool success = move_group.plan(my_plan);

   ROS_INFO(" SETTING START POSITION(planning) %s",success?"":"FAILED");

move_group.move();
sleep(2.0);
  ROS_INFO("REACHED STARTING POSE");

  current_pose_message=move_group.getCurrentPose(move_group.getEndEffectorLink() );
ROS_INFO("CURRENT_STATE_POSITION_X: %f",current_pose_message.pose.position.x);
ROS_INFO("CURRENT_STATE POSITION_Y: %f",current_pose_message.pose.position.y);
ROS_INFO("CURRENT_STATE_POSITION_Z: %f",current_pose_message.pose.position.z);





  std::vector<geometry_msgs::Pose> waypoints;

  geometry_msgs::Pose target_point_1 ;
  target_point_1.position.x = 1.5;
  target_point_1.position.y = -0.5;
  target_point_1.position.z = 1.2;
  waypoints.push_back(target_point_1);  // P1

  geometry_msgs::Pose target_point_2 ;
  target_point_2.position.x = 1.5;
  target_point_2.position.y = 0.5;
  target_point_2.position.z = 1.2;
  waypoints.push_back(target_point_2);  // P2

    geometry_msgs::Pose target_point_3 ;
  target_point_3.position.x = 1.5;
  target_point_3.position.y = -0.5;
  target_point_3.position.z = 1;
  waypoints.push_back(target_point_3);  // P3

    geometry_msgs::Pose target_point_4 ;
  target_point_4.position.x = 1.5;
  target_point_4.position.y = 0.5;
  target_point_4.position.z = 1;
  waypoints.push_back(target_point_4);  // P4

    geometry_msgs::Pose target_point_5 ;
  target_point_2.position.x = 1.5;
  target_point_2.position.y = -0.5;
  target_point_2.position.z = 0.33;
  waypoints.push_back(target_point_2);  // P5

    geometry_msgs::Pose target_point_6 ;
  target_point_6.position.x = 1.5;
  target_point_6.position.y = 0.5;
  target_point_6.position.z = 0.33;
  waypoints.push_back(target_point_6);  // P6


  for(int i=0;i<6;i++){

  move_group.setPositionTarget(waypoints[i].position.x,waypoints[i].position.y ,
  waypoints[i].position.z,move_group.getEndEffectorLink());

   moveit::planning_interface::MoveGroup::Plan my_plan_target;
  bool success = move_group.plan(my_plan_target);
  ROS_INFO("POSE planning for MSU-%d, -%s",i+1,success?"":"FAILED");

   move_group.move();
   sleep(2.0);

  ROS_INFO("REACHED MSU-%d",i+1);

current_pose_message=move_group.getCurrentPose(move_group.getEndEffectorLink() );
ROS_INFO("CURRENT_STATE-MSU-%d_POSITION_X: %f",i+1,current_pose_message.pose.position.x);
ROS_INFO("CURRENT_STATE-MSU-%d_POSITION_Y: %f",i+1,current_pose_message.pose.position.y);
ROS_INFO("CURRENT_STATE-MSU-%d_POSITION_Z: %f",i+1,current_pose_message.pose.position.z);


  move_group.setPositionTarget(home_target.position.x,home_target.position.y ,
  home_target.position.z,move_group.getEndEffectorLink());

  moveit::planning_interface::MoveGroup::Plan my_plan_home;

  bool success_home = move_group.plan(my_plan_home);
  ROS_INFO("POSE planning for HOME %s",success_home?"":"FAILED");

  move_group.move();
  sleep(2.0);
  ROS_INFO("REACHED HOME POSE");

current_pose_message=move_group.getCurrentPose(move_group.getEndEffectorLink() );
ROS_INFO("CURRENT_STATE-HOME_POSITION_X: %f",current_pose_message.pose.position.x);
ROS_INFO("CURRENT_STATE-HOME_POSITION_Y: %f",current_pose_message.pose.position.y);
ROS_INFO("CURRENT_STATE-HOME_POSITION_Z: %f",current_pose_message.pose.position.z);

  }

  // We want the cartesian path to be interpolated at a resolution of 1 cm
  // which is why we will specify 0.01 as the max step in cartesian
  // translation.  We will specify the jump threshold as 0.0, effectively
  // disabling it.
  ros::shutdown();
  return 0;
}
