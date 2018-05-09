#!/usr/bin/env python
import rospy
from listening import Listening
from std_msgs.msg import Float64
class Callingall:
    def __init__(self, x=0, y=0, z=0):
        self.x = x
        self.y = y
        self.z = z

    def callback(self, data):
        rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)
        forca = data.data
        return forca

    def callback2(self, data):
        rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)
        distancia = data.data
        return distancia

    def listener(self):
        rospy.init_node('listener', anonymous=True)
        rospy.Subscriber("chatter", Float64, self.callback)
        rospy.Subscriber("chatter2", Float64, self.callback2)
        rospy.spin()