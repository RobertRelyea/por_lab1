#include "diff_robot.h"

void robotSetup()
{
  motorSetup();
  pinMode(A0, INPUT_PULLUP); // For Sharp
}

float getDistance()
{
  float x = (float)analogRead(A0);
  float distance = (0.0003 * x * x) - (0.2345 * x) + 45.233;
  return distance;
}

void wander()
{
  moveState state = OBSTRUCTED;

  while(true)
  {
    if(getDistance() < 20)
    {
      if (state == MOVING)
      {
        MDecelerate(200, 200);
        state = OBSTRUCTED;
      }
      else
        turnRight();
    }
    else if(state == OBSTRUCTED)
    {
      state = FREE;
    }
    else if (state == FREE)
    {
      state = MOVING;
      MAccelerate(200, 200);
    }
  }
}

