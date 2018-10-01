#include "robot_motors.h"

void setup() {
  // put your setup code here, to run once:
  motorSetup();
  Serial.begin(9600);
  pinMode(A0, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
//  driveForTime(250, 250, 1000);
//  turnRight();
//  delay(3000);
  Serial.println(getDistance());  
}

float getDistance()
{
  float x = (float)analogRead(A0);
  float distance = (0.0003 * x * x) - (0.2345 * x) + 45.233;
  return distance;
}

void wander()
{
  if(getDistance() < 12)
    
  //else
    
}

