#!/usr/bin/env python
import rospy
from std_msgs.msg import Float64


class Listening:
    def __init__(self, force, distance):
        self.frce = force
        self.dsta = distance

    def wheretomove(self):
        if self.dsta < 2.0:
            self.frce = 125.0
        else:
            self.fc = 0
        return self.fc
