

#include <Servo.h>
#include <ros.h>
//#include <std_msgs/int.h>
#include <std_msgs/Float64.h>


ros::NodeHandle  nh;
std_msgs::Float64 str_msg;
ros::Publisher chatter("chatter", &str_msg);
//ros::Subscriber s("your_topic", &str_msg, &messageCb);

Servo myservo;  
//int pos = 0;    // variable to store the servo position

void setup() {
  nh.initNode();
  nh.advertise (chatter);
//  nh.subscribe(sub);
  myservo.attach(11);  
 // nh.subscribe(s);
 // myservo.write(force); 
}

void loop() {
  float force = 86;
  myservo.write (force);
  str_msg.data = force;
  chatter.publish ( &str_msg );
  nh.spinOnce();
           
                      
}

