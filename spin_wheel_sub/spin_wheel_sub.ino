/*
 * rosserial PubSub Example
 * Prints "hello world!" and toggles led
 */
 
#include <Ultrasonic.h>
#include <Servo.h>
#include <ros.h>
#include <std_msgs/Float64.h>
#define pino_trigger A5
#define pino_echo A4

Servo myservo;

ros::NodeHandle  nh;
std_msgs::Float64 str_msg;
std_msgs::Float64 strr_msg;
ros::Publisher chatter("chatter", &str_msg);
ros::Publisher chatter2("chatter2", &str_msg);

Ultrasonic ultrasonic(pino_trigger, pino_echo);


void spin( const std_msgs::Float64& force){

 if ( force.data == 88.0 ){
      if ( myservo.attached() ){
        myservo.detach();
      }     
 }

 if (! myservo.attached() )
      myservo.attach(11);
 myservo.write(force.data);
}

ros::Subscriber<std_msgs::Float64> sub("force", spin );
//ros::Subscriber<std_msgs::Float64> sub2("ultra", distancia );

void setup()
{
  myservo.attach(11);
  nh.initNode();
  nh.advertise(chatter);
  nh.subscribe(sub);
}

void loop()
{
  float cmMsec;
  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
   strr_msg.data = cmMsec;
   
  chatter.publish ( &str_msg ); //wheel
  
  chatter2.publish( &strr_msg ); //ultra
  
 // nh.spinOnce();
}
