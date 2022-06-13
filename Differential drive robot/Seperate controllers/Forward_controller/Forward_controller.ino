#include <Wire.h>
#include <Zumo32U4.h>
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

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial1.flush();
  Serial.flush();
  Wire.begin();

    buttonA.waitForButton();
   
}
void loop() {
  readData();
motors.setSpeeds(goal[1], goal[2]);
int16_t countsLeft = encoders.getCountsLeft();
int16_t countsRight = encoders.getCountsRight();
deltaDistance=((countsLeft+countsRight)/2)*distancePerCount;
deltaDistance=(deltaDistance/100);
  sendData(deltaDistance);
}
void sendData (float a)
{
  val1=String(a);

  Serial1.print(","+val1+";");
  
  }
void readData ()
  {
         if (Serial1.available()>0)
         {
for(int i=0;i<=2;i++)
{
  data[i]=Serial1.readStringUntil(' ');
  goal[i]=(data[i].toFloat());
}
         }
    }
  
