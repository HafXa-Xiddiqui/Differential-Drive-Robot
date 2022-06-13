#include <Wire.h>
#include <Zumo32U4.h>
#include "TurnSensor.h"
Zumo32U4Motors motors;
Zumo32U4Encoders encoders;
Zumo32U4ButtonA buttonA;
Zumo32U4IMU imu;
int16_t countsLeft; 
int16_t countsRight; 
String val1;
String val2;
String data[3];
int goal[3];
float wheelDia=3.8;
float countsPerRevolution=617.40;
float trackWidth= 10;
float distancePerCount = (3.142*wheelDia)/countsPerRevolution;
float radPerCount = (3.142 * (wheelDia/trackWidth))/countsPerRevolution;
float deltaDistance=0;
double data1;
double m=0;
double m1=0;
double T=0;
double distance=0;
double T_dis=0;
float angle=0;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial1.flush();
  Serial.flush();
  turnSensorSetup();
  delay(500);
  turnSensorReset();
    while (!buttonA.getSingleDebouncedRelease())
  {
    turnSensorUpdate();
    Serial.println((((int32_t)turnAngle >> 16) * 360) >> 16);
  }

}
void loop() {
  readData();
motors.setSpeeds(goal[1], goal[2]);
turnSensorUpdate();
angle=((((int32_t)turnAngle >> 16) * 360) >> 16);
angle=angle*(3.142/180);
int16_t countsLeft = encoders.getCountsLeft();
int16_t countsRight = encoders.getCountsRight();
deltaDistance=((countsLeft+countsRight)/2)*distancePerCount;
deltaDistance=(deltaDistance/100);
 sendData(deltaDistance,angle);
}
void sendData (float a, float b)
{
  val1=String(a);
  val2=String(b);

  Serial1.print(","+val1+";"+"/"+val2+"]");
  
  }
void readData ()
  {
         while (Serial1.available()>0)
         {
for(int i=0;i<=2;i++)
{
  data[i]=Serial1.readStringUntil(' ');
  goal[i]=(data[i].toFloat());
}
         }
    }
  
