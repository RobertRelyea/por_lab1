#ifndef DIFF_ROBOT_H
#define DIFF_ROBOT_H

#include "robot_motors.h"


typedef enum{
  OBSTRUCTED,
  FREE,
  MOVING
}moveState;

// Setup function for motor driver object
void robotSetup();

float getDistance();

void wander();

#endif
