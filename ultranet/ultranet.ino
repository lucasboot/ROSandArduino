
#include <Ultrasonic.h>
#include <Servo.h>
#include <ros.h>
#include <std_msgs/Float64.h>

#define pino_trigger 4
#define pino_echo 5


ros::NodeHandle  nh;
std_msgs::Float64 str_msg;
ros::Publisher chatter("chatter", &str_msg);

//Inicializa o sensor nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger, pino_echo);

void setup()
{
  nh.initNode();
  nh.advertise (chatter);
  //Serial.begin(9600);
 //Serial.println("Lendo dados do sensor...");
}

void loop()
{
  //Le as informacoes do sensor, em cm e pol
  float cmMsec, inMsec;
  float microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  inMsec = ultrasonic.convert(microsec, Ultrasonic::IN);
  //Exibe informacoes no serial monitor
 // Serial.print("Distancia em cm: ");
 // Serial.print(cmMsec);
  str_msg.data = cmMsec;
  chatter.publish ( &str_msg );
  nh.spinOnce();
 // Serial.print(" - Distancia em polegadas: ");
//  Serial.println(inMsec);
  
}
