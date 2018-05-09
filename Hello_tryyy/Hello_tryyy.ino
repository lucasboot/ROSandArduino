
   8 
   9 #include <ros.h>
  10 #include <std_msgs/String.h>
  11 
  12 ros::NodeHandle nh;
  13 
  14 std_msgs::String str_msg;
  15 ros::Publisher chatter("chatter", &str_msg);
  16 
  17 char hello[13] = "hello world!";
  18 
  19 void setup()
  20 {
  21   nh.initNode();
  22   nh.advertise(chatter);
  23 }
  24 
  25 void loop()
  26 {
  27   str_msg.data = hello;
  28   chatter.publish( &str_msg );
  29   nh.spinOnce();
  30   delay(1000);
  31 }
