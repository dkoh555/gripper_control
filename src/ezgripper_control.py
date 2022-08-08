#!/usr/bin/python3
# -*- coding: utf-8 -*-

import rospy
import sys
from libezgripper import create_connection, Gripper

from gripper_control.srv import grip
from gripper_control.srv import gripResponse

#connection = create_connection(dev_name='/dev/ttyUSB0', baudrate= 57600)
connection = create_connection(dev_name='hwgrep://0403:6015', baudrate=57600)

gripper = Gripper(connection, 'gripper1', [1])

def control_gripper(req):
    if req.decision == 0:
        gripper.goto_position(0, 50)
    elif req.decision == 1:
        gripper.goto_position(75, 50)
    elif req.decision == 2:
        gripper.calibrate()

    print("\n")
    return gripResponse(True)

def gripper_server():
    rospy.init_node('ezgripper_control')
    s = rospy.Service('gripper', grip, control_gripper)
    print ("Gripper is operational")
    rospy.spin()
    
if __name__ == "__main__":
    gripper.calibrate()
    gripper_server()

