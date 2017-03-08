#include <ros/ros.h>
#include "gazebo_msgs/SetModelState.h"

using namespace std;

int main(int argc,char **argv)
{

ros::init(argc,argv,"test_control");
ros::NodeHandle n;


geometry_msgs::Pose start_pose;
start_pose.position.x = 0.0;
start_pose.position.y = 0.0;
start_pose.position.z = 0.1;
start_pose.orientation.x = 0.0;
start_pose.orientation.y = 0.0;
start_pose.orientation.z = 0.0;
start_pose.orientation.w = 0.0;

geometry_msgs::Twist start_twist;
start_twist.linear.x = 0.0;
start_twist.linear.y = 0.0;
start_twist.linear.z = 0.0;
start_twist.angular.x = 0.0;
start_twist.angular.y = 0.0;
start_twist.angular.z = 0.0;

gazebo_msgs::ModelState modelstate;
modelstate.model_name = (std::string) "rrbot";
modelstate.reference_frame = (std::string) "world";
modelstate.pose = start_pose;
modelstate.twist = start_twist;

ros::ServiceClient client = n.serviceClient<gazebo_msgs::SetModelState>
("/gazebo/set_model_state");
gazebo_msgs::SetModelState setmodelstate;
setmodelstate.request.model_state = modelstate;
        if(client.call(setmodelstate)){

              ROS_INFO("ARM  moving success!!");

         }


       else{
              ROS_ERROR("Failed to magic move PR2! Error msg:%s",setmodelstate.response.status_message.c_str());
 
         }

return 0;

}
