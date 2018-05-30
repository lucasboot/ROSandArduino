#include <ros.h>
#include <Ultrasonic.h>
#include <Servo.h>
#include <ros.h>
#include <ros/time.h>
#include <std_msgs/Float64.h>
#include <std_msgs/Int32.h>
#define pino_trigger A5
#define pino_echo A4

Servo myservo;

ros::NodeHandle  nh;
std_msgs::Float64 str_msg;
std_msgs::Float64 strr_msg;
ros::Publisher pubdist("Distance", &str_msg);


Ultrasonic ultrasonic(pino_trigger, pino_echo);


/*void spin( const std_msgs::Int32& force){
 if ( force.data == 88.0 ){
      if ( myservo.attached() ){
        myservo.detach();
      }     
 }

 if (! myservo.attached() )
      myservo.attach(11);
 myservo.write(force.data);
}#


ros::Subscriber<std_msgs::Int32> sub("chatter", spin);
*/
void rodando( const std_msgs::Int32& valor){
 myservo.write(valor.data);
}
void setup()
{
  nh.initNode();
  myservo.attach(11);
  nh.advertise(pubdist);
}
void loop()
{
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
   strr_msg.data = cmMsec;
  pubdist.publish(&strr_msg); 
  ros::Subscriber<std_msgs::Int32> sub1("velocidade", rodando);
  nh.spinOnce();
}
