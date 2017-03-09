 #include <ros/ros.h>
 #include <trajectory_msgs/JointTrajectory.h>
 #include <trajectory_msgs/JointTrajectoryPoint.h>
 #include <std_msgs/Bool.h>




int main(int argc, char **argv)
{

	ros::init(argc, argv, "arm_publish");

	ros::NodeHandle n;
	ros::Publisher pb = n.advertise<trajectory_msgs::JointTrajectory>("arm_controller/command", 100);

	trajectory_msgs::JointTrajectory Control_message;
	
	Control_message.header.seq = 1 ;
	Control_message.header.stamp = ros::Time::now() ;

	Control_message.joint_names.push_back("shoulder_pan_joint");
	Control_message.joint_names.push_back("shoulder_lift_joint");
	Control_message.joint_names.push_back("elbow_joint");
        Control_message.joint_names.push_back("wrist_1_joint");
  	Control_message.joint_names.push_back("wrist_2_joint");
  	Control_message.joint_names.push_back("wrist_3_joint");

	trajectory_msgs::JointTrajectoryPoint p1;

	//p1.positions.resize(6);
	//p1.positions[0] = 1.5 ;
  	//p1.positions[1] = 0.5 ;
  	//p1.positions[2] = 0.0 ;
  	//p1.positions[3] = 0.0 ;
  	//p1.positions[4] = 0.0 ;
  	//p1.positions[5] = 0.0 ;
	
	p1.positions.resize(6);
  	p1.positions[0] = 1.5 ;
  	p1.positions[1] = 0.0 ;
  	p1.positions[2] = 0.0 ;
  	p1.positions[3] = 0.0 ;
  	p1.positions[4] = 0.0 ;
  	p1.positions[5] = 0.0 ;
  
	p1.velocities.resize(6);
  	p1.velocities[0] = 0.25 ;
  	p1.velocities[1] = 0.0;
  	p1.velocities[2] = 0.0 ;
  	p1.velocities[3] = 0.0 ;
  	p1.velocities[4] = 0.0 ;
  	p1.velocities[5] = 0.0;
  
  	p1.time_from_start = ros::Duration(3);
  
	trajectory_msgs::JointTrajectoryPoint p2;

	//p2.positions.resize(6);
  	//p2.positions[0] = -1.5 ;
  	//p2.positions[1] = -0.5 ;
  	//p2.positions[2] = 0.0 ;
  	//p2.positions[3] = 0.0 ;
  	//p2.positions[4] = 0.0 ;
  	//p2.positions[5] = 0.0 ;

	p2.positions.resize(6);
  	p2.positions[0] = 1.5 ;
  	p2.positions[1] = 0.0 ;
  	p2.positions[2] = -0.8 ;
  	p2.positions[3] = 0.0 ;
  	p2.positions[4] = 0.0 ;
  	p2.positions[5] = 0.0 ;
  
	p2.velocities.resize(6);
  	p2.velocities[0] = 0.0 ;
  	p2.velocities[1] = 0.0;
  	p2.velocities[2] = 0.25 ;
  	p2.velocities[3] = 0 ;
  	p2.velocities[4] = 0 ;
  	p2.velocities[5] = 0 ;
  
  	p2.time_from_start = ros::Duration(6);
  
  	Control_message.points.push_back(p1);
  	Control_message.points.push_back(p2);

	while(n.ok())
	{		
		pb.publish(Control_message);
		ros::spinOnce();
		ros::Duration(10).sleep();
		if(!pb){
			ROS_ERROR("MESSAGE PUBLISH FAILED");
		}
		else{
			ROS_INFO("MESSAGE PUBLISH DONE");
			
		}
	}

	return 0;
}
