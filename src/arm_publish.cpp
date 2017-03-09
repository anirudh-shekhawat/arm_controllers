 #include <ros/ros.h>
 #include <trajectory_msgs/JointTrajectory.h>
 #include <trajectory_msgs/JointTrajectoryPoint.h>
 #include <std_msgs/Bool.h>




int main(int argc, char **argv)
{

ros::init(argc, argv, "arm_publish");

ros::NodeHandle n;
ros::Publisher pb=n.advertise<trajectory_msgs::JointTrajectory>("/arm_controller/command", 10);

trajectory_msgs::JointTrajectory Control_message;

Control_message.header.stamp = ros::Time::now();

Control_message.header.seq=1;

  	Control_message.joint_names.push_back("shoulder_pan_joint");
  	Control_message.joint_names.push_back("shoulder_lift_joint");
  	Control_message.joint_names.push_back("elbow_joint");
        Control_message.joint_names.push_back("wrist_1_joint");
  	Control_message.joint_names.push_back("wrist_2_joint");
  	Control_message.joint_names.push_back("wrist_3_joint");

trajectory_msgs::JointTrajectoryPoint p1;
  	p1.positions.push_back(1.57075);
  	p1.positions.push_back(1.57075);
  	p1.positions.push_back(1.57075);
  	p1.positions.push_back(1.57075);
  	p1.positions.push_back(1.57075);
  	p1.positions.push_back(1.57075);
  
  	p1.velocities.push_back(.25);
  	p1.velocities.push_back(.25);
  	p1.velocities.push_back(.25);
  	p1.velocities.push_back(.25);
  	p1.velocities.push_back(.25);
  	p1.velocities.push_back(.25);
  
  	p1.time_from_start = ros::Duration(20);
  
trajectory_msgs::JointTrajectoryPoint p2;
  	p2.positions.push_back(-1.57075);
  	p2.positions.push_back(-1.57075);
  	p2.positions.push_back(-1.57075);
  	p2.positions.push_back(-1.57075);
  	p2.positions.push_back(-1.57075);
  	p2.positions.push_back(-1.57075);
  
  	p2.velocities.push_back(-.25);
  	p2.velocities.push_back(-.25);
  	p2.velocities.push_back(-.25);
  	p2.velocities.push_back(-.25);
  	p2.velocities.push_back(-.25);
  	p2.velocities.push_back(-.25);
  
  	p2.time_from_start = ros::Duration(40);
  
  	Control_message.points.push_back(p1);
  	Control_message.points.push_back(p2);

pb.publish(Control_message);

if(!pb){
ROS_ERROR("MESSAGE PUBLISH FAILED");
}

else{

ROS_INFO("MESSAGE PUBLISH DONE");
}


return 0;
}
