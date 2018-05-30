#!/usr/bin/env python
from callingall import Callingall
import rospy; 
from std_msgs.msg import Float64, Int32
class Ex1:
    node = Callingall()
    rate = rospy.Rate(2)
    while not rospy.is_shutdown:
        node.listener()
        rate.sleep()