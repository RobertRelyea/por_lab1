#include "robot_motors.h"

DualMC33926MotorShield motorShield;

void motorSetup()
{
  motorShield.init();
}

void M1Accelerate(int maxSpeed, int duration)
{
  for(int i = 0; i < maxSpeed; ++i)
  {
    motorShield.setM1Speed(i);
    delay(duration / maxSpeed);
  }
}

void M1Decelerate(int maxSpeed, int duration)
{
  for(int i = maxSpeed; i > 0; --i)
  {
    motorShield.setM1Speed(i);
    delay(duration / maxSpeed);
  }
}

void M2Accelerate(int maxSpeed, int duration)
{
  for(int i = 0; i < maxSpeed; ++i)
  {
    motorShield.setM2Speed(i);
    delay(duration / maxSpeed);
  }
}

void M2Decelerate(int maxSpeed, int duration)
{
  for(int i = maxSpeed; i > 0; --i)
  {
    motorShield.setM2Speed(i);
    delay(duration / maxSpeed);
  }
}

void turnRight()
{
  // Accelerate
  for(int i = 0; i <= 250; ++i)
  {
    motorShield.setM1Speed(-i);
    motorShield.setM2Speed(i);
    delay(3);
  }
  // Sustain speed
  delay(325);
  // Decelerate
  for(int i = 200; i >= 0; --i)
  {
    motorShield.setM1Speed(-i);
    motorShield.setM2Speed(i);
    delay(3);
  }
}

void MAccelerate(int maxSpeed, int duration)
{

  if (maxSpeed >= 0)
  {
    for(int i = 0; i < maxSpeed; ++i)
    {
      motorShield.setM1Speed(i);
      motorShield.setM2Speed(i);
      delay(duration / maxSpeed);
    }
  }
  else
  {
    for(int i = 0; i > maxSpeed; --i)
    {
      motorShield.setM1Speed(i);
      motorShield.setM2Speed(i);
      delay(duration / abs(maxSpeed));
    }
  }
  
}

void MDecelerate(int maxSpeed, int duration)
{
  if (maxSpeed >= 0)
  {
    for(int i = maxSpeed; i > 0; --i)
    {
      motorShield.setM1Speed(i);
      motorShield.setM2Speed(i);
      delay(duration / maxSpeed);
    }
  }
  else
  {
    for(int i = maxSpeed; i <= 0; ++i)
    {
      motorShield.setM1Speed(i);
      motorShield.setM2Speed(i);
      delay(duration /  abs(maxSpeed));
    }
  }
}

void driveForTime(int maxSpeed, int rampSpeed, int driveTime)
{
  MAccelerate(maxSpeed, rampSpeed);
  delay(driveTime);
  MDecelerate(maxSpeed, rampSpeed);
}

void driveForDistance(int driveDistance)
{
  int distanceTime=(driveDistance * 41.901) + 449.65;
  MAccelerate(250, 200);
  delay(distanceTime-400);
  MDecelerate(250, 200);
}


