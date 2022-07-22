#include "ros/ros.h"
#include "std_srvs/SetBool.h"
#include <iostream>

#include "gripper_control/grip.h"

int main(int argc, char **argv)
{
  // Initialise ROS node
  ros::init(argc, argv, "ez_gripper_test");
  ROS_INFO("Please enter settings for gripper control");

  // Initialize node
  ros::NodeHandle n;

  // Start (looking for) service
  ros::ServiceClient client_request = n.serviceClient<gripper_control::grip>("gripper");
  gripper_control::grip srv1; // Provide coordinates and then receive confirmation whether it is possible

  while(true)
  {
    int dec1 = 10;
    
    while(dec1 != 0 && dec1 != 1 && dec1 != 2)
    {
        std::cout << "Enter 0 to close, 1 to open, and 2 to calibrate: ";
        std::cin >> dec1;
    }

    srv1.request.decision = dec1;

    if(dec1 == 2)
    {
      std::cout << "Calibrating\n";
    }

    if (client_request.call(srv1)) // Ensure that first service call is successful, also "executes" the call
    {
        ROS_INFO("Gripper command completed");
    }
    else // If unable to connect to both services, return an error message
    {
        ROS_ERROR("Failed to call service grip to gripper");
        return 1;
    }

  }

  return 0;
}