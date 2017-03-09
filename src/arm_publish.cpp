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
  
  	p1.time_from_start = ros::Duration(2);
  
	trajectory_msgs::JointTrajectoryPoint p2;
	
	p2.positions.resize(6);
  	p2.positions[0] = 1.5 ;
  	p2.positions[1] = -1.0 ;
  	p2.positions[2] = 0.0 ;
  	p2.positions[3] = 0.0 ;
  	p2.positions[4] = 0.0 ;
  	p2.positions[5] = 0.0 ;
  
	p2.velocities.resize(6);
  	p2.velocities[0] = 0.0 ;
  	p2.velocities[1] = 0.25;
  	p2.velocities[2] = 0.0 ;
  	p2.velocities[3] = 0.0 ;
  	p2.velocities[4] = 0.0 ;
  	p2.velocities[5] = 0.0;


	trajectory_msgs::JointTrajectoryPoint p3;

	p3.positions.resize(6);
  	p3.positions[0] = 1.5 ;
  	p3.positions[1] = -1.0 ;
  	p3.positions[2] = 0.8 ;
  	p3.positions[3] = 0.0 ;
  	p3.positions[4] = 0.0 ;
  	p3.positions[5] = 0.0 ;
  
	p3.velocities.resize(6);
  	p3.velocities[0] = 0.0 ;
  	p3.velocities[1] = 0.0;
  	p3.velocities[2] = 0.25 ;
  	p3.velocities[3] = 0 ;
  	p3.velocities[4] = 0 ;
  	p3.velocities[5] = 0 ;
  

        trajectory_msgs::JointTrajectoryPoint p4;

	p4.positions.resize(6);
  	p4.positions[0] = 1.5 ;
  	p4.positions[1] = -1.0 ;
  	p4.positions[2] = 0.8 ;
  	p4.positions[3] = -1.25 ;
  	p4.positions[4] = 0.0 ;
  	p4.positions[5] = 0.0 ;
  
	p4.velocities.resize(6);
  	p4.velocities[0] = 0.0 ;
  	p4.velocities[1] = 0.0;
  	p4.velocities[2] = 0.0 ;
  	p4.velocities[3] = 0.25;
  	p4.velocities[4] = 0.0 ;
  	p4.velocities[5] = 0.0 ;

	
	trajectory_msgs::JointTrajectoryPoint p5;

	p5.positions.resize(6);
  	p5.positions[0] = 1.5 ;
  	p5.positions[1] = -1.0 ;
  	p5.positions[2] = 0.8 ;
  	p5.positions[3] = -1.25 ;
  	p5.positions[4] = 1.25 ;
  	p5.positions[5] = 0.0 ;
  
	p5.velocities.resize(6);
  	p5.velocities[0] = 0.0 ;
  	p5.velocities[1] = 0.0;
  	p5.velocities[2] = 0.0 ;
  	p5.velocities[3] = 0.0 ;
  	p5.velocities[4] = 0.25 ;
  	p5.velocities[5] = 0.0 ;

	trajectory_msgs::JointTrajectoryPoint p6;

	p6.positions.resize(6);
  	p6.positions[0] = 1.5 ;
  	p6.positions[1] = -1.0 ;
  	p6.positions[2] = 0.8 ;
  	p6.positions[3] = -1.25 ;
  	p6.positions[4] = 1.25 ;
  	p6.positions[5] = -1.25 ;
  
	p6.velocities.resize(6);
  	p6.velocities[0] = 0.0 ;
  	p6.velocities[1] = 0.0;
  	p6.velocities[2] = 0.0 ;
  	p6.velocities[3] = 0.0 ;
  	p6.velocities[4] = 0.0 ;
  	p6.velocities[5] = 0.25 ;

        
	trajectory_msgs::JointTrajectoryPoint p7;

	p7.positions.resize(6);
  	p7.positions[0] = 1.5 ;
  	p7.positions[1] = -1.0 ;
  	p7.positions[2] =  0.8 ;
  	p7.positions[3] = -1.25 ;
  	p7.positions[4] = 1.25 ;
  	p7.positions[5] = 0.0 ;
  
	p7.velocities.resize(6);
    	p7.velocities[0] = 0.0 ;
  	p7.velocities[1] = 0.0;
  	p7.velocities[2] = 0.0 ;
  	p7.velocities[3] = 0.0 ;
  	p7.velocities[4] = 0.0 ;
  	p7.velocities[5] = 0.25 ;

	trajectory_msgs::JointTrajectoryPoint p8;

	p8.positions.resize(6);
  	p8.positions[0] = 1.5 ;
  	p8.positions[1] = -1.0 ;
  	p8.positions[2] = 0.8 ;
  	p8.positions[3] = -1.25 ;
  	p8.positions[4] = 0.0 ;
  	p8.positions[5] = 0.0 ;
  
	p5.velocities.resize(6);
  	p5.velocities[0] = 0.0 ;
  	p5.velocities[1] = 0.0;
  	p5.velocities[2] = 0.0 ;
  	p5.velocities[3] = 0 ;
  	p5.velocities[4] = 0.25 ;
  	p5.velocities[5] = 0 ;

	trajectory_msgs::JointTrajectoryPoint p9;
	
	p9.positions.resize(6);
  	p9.positions[0] = 1.5 ;
  	p9.positions[1] = -1.0 ;
  	p9.positions[2] = 0.8 ;
  	p9.positions[3] = 0.0 ;
  	p9.positions[4] = 0.0 ;
  	p9.positions[5] = 0.0 ;
  
	p9.velocities.resize(6);
  	p9.velocities[0] = 0.0 ;
  	p9.velocities[1] = 0.0;
  	p9.velocities[2] = 0.0 ;
  	p9.velocities[3] = 0.25 ;
  	p9.velocities[4] = 0.0 ;
  	p9.velocities[5] = 0.0;


	trajectory_msgs::JointTrajectoryPoint p10;
	
	p10.positions.resize(6);
  	p10.positions[0] = 1.5 ;
  	p10.positions[1] = -1.0 ;
  	p10.positions[2] = 0.0 ;
  	p10.positions[3] = 0.0 ;
  	p10.positions[4] = 0.0 ;
  	p10.positions[5] = 0.0 ;
  
	p10.velocities.resize(6);
  	p10.velocities[0] = 0.0 ;
  	p10.velocities[1] = 0.0;
  	p10.velocities[2] = 0.25 ;
  	p10.velocities[3] = 0.0 ;
  	p10.velocities[4] = 0.0 ;
  	p10.velocities[5] = 0.0;


	trajectory_msgs::JointTrajectoryPoint p11;
	
	p11.positions.resize(6);
  	p11.positions[0] = 1.5 ;
  	p11.positions[1] = 0.0 ;
  	p11.positions[2] = 0.0 ;
  	p11.positions[3] = 0.0 ;
  	p11.positions[4] = 0.0 ;
  	p11.positions[5] = 0.0 ;
  
	p11.velocities.resize(6);
  	p11.velocities[0] = 0.0 ;
  	p11.velocities[1] = 0.25;
  	p11.velocities[2] = 0.0 ;
  	p11.velocities[3] = 0.0 ;
  	p11.velocities[4] = 0.0 ;
  	p11.velocities[5] = 0.0;


	trajectory_msgs::JointTrajectoryPoint p12;
	
	p12.positions.resize(6);
  	p12.positions[0] = 0.0 ;
  	p12.positions[1] = 0.0 ;
  	p12.positions[2] = 0.0 ;
  	p12.positions[3] = 0.0 ;
  	p12.positions[4] = 0.0 ;
  	p12.positions[5] = 0.0 ;
  
	p12.velocities.resize(6);
  	p12.velocities[0] = 0.25 ;
  	p12.velocities[1] = 0.0;
  	p12.velocities[2] = 0.0 ;
  	p12.velocities[3] = 0.0 ;
  	p12.velocities[4] = 0.0 ;
  	p12.velocities[5] = 0.0;
  
	

  	p2.time_from_start = ros::Duration(5);

        p3.time_from_start = ros::Duration(7);

	p4.time_from_start = ros::Duration(10);
	
	p5.time_from_start = ros::Duration(12);

	p6.time_from_start = ros::Duration(15);

        p7.time_from_start = ros::Duration(17);
 
        p8.time_from_start = ros::Duration(19);
        p9.time_from_start = ros::Duration(21);
        p10.time_from_start = ros::Duration(23);
        p11.time_from_start = ros::Duration(25);
        p12.time_from_start = ros::Duration(27);

  
  	Control_message.points.push_back(p1);
  	Control_message.points.push_back(p2);
	Control_message.points.push_back(p3);
	Control_message.points.push_back(p4);
	Control_message.points.push_back(p5);
	Control_message.points.push_back(p6);
        Control_message.points.push_back(p7);
        Control_message.points.push_back(p8);
        Control_message.points.push_back(p9);
        Control_message.points.push_back(p10);
        Control_message.points.push_back(p11);
        Control_message.points.push_back(p12);


	while(n.ok())
	{		
		pb.publish(Control_message);
		ros::spinOnce();
		
		if(!pb){
			ROS_ERROR("MESSAGE PUBLISH FAILED");
		}
		else{
			ROS_INFO("MESSAGE PUBLISH DONE");
			
		}
            ros::Duration(29).sleep();
	}

	return 0;
}
