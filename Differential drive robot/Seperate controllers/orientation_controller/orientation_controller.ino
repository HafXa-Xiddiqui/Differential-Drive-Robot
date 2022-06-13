
const float DEG2RAD = PI / 180.0f;
const float RAD2DEG = 180.0f / PI;

#include <Wire.h>
#include <Zumo32U4.h>
#include "TurnSensor.h"

// This is the maximum speed the motors will be allowed to turn.
// A maxSpeed of 400 lets the motors go at top speed.  Decrease
// this value to impose a speed limit.
const int16_t maxSpeed = 400;

Zumo32U4LCD lcd;
Zumo32U4ButtonA buttonA;
Zumo32U4IMU imu;
Zumo32U4Motors motors;
Zumo32U4Encoders encoders;
float angle=0;
String val;
int16_t countsLeft; 
int16_t countsRight; 
String val1;
String val2;
String data[3];
float  wheelDia=3.8;
float countsPerRevolution=909.7;
float trackWidth= 10;
float distancePerCount = (3.142*wheelDia)/countsPerRevolution;
float radPerCount = (3.142 * (wheelDia/trackWidth))/countsPerRevolution;
float goal[3];
double x=0;
double y=0;

void setup()
{
   Wire.begin();
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial1.flush();
  Serial.flush();
  turnSensorSetup();
  delay(500);
  turnSensorReset();
  buttonA.waitForButton();
}

void loop()
{
  readData();
  motors.setSpeeds(goal[1],goal[2]);
  //read current angle
turnSensorUpdate();
angle=((((int32_t)turnAngle >> 16) * 360) >> 16);
angle=angle*DEG2RAD;
  sendData(angle);
  }
void sendData (float a)
{
  val=String(a);

  Serial1.print(","+val+";");
  
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
  
