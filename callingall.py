#!/usr/bin/env python
import rospy
from std_msgs.msg import Float64
from std_msgs.msg import Int32
import rospy
class Callingall:
    def __init__(self):
        self.distancia = 100.0
        self.velocidade = 100

    def common_callback(self, msg):
        input_message_type = str(msg._type)
        rospy.logdebug("msg._type ==>"+input_message_type)
        if input_message_type == "std_msg/Float64":
            rospy.loginfo("Distancia foi recebida, salvando...==>"+input_message_type)
            self.distancia = msg
        if input_message_type == "std_msg/Int32":
            rospy.loginfo("Calculando velocidade adequada..."+input_message_type)
            if self.distancia < 2.0:
                self.velocidade = 125
            else:
                self.velocidade = 0
        pub = rospy.Publisher ('velocidade', Int32)
        pub.publish(self.velocidade)

    def listener(self):
        rospy.init_node('listener', anonymous=True)
        rospy.Subscriber("Distance", Float64, self.common_callback)
        rospy.Subscriber("Speed", Int32, self.common_callback)
        rospy.spin()