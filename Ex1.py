#!/usr/bin/env python
from .listening import Listening
from .callingall import Callingall
import rospy
from std_msgs.msg import Float64

node = Callingall()
node.listener()
a = node.callback
b = node.callback2
listen = Listening(a, b)
listen.wheretomove()

if __name__ == '__main__':
    node.listener()
