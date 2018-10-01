#ifndef ROBOT_MOTORS_H
#define ROBOT_MOTORS_H

#include "DualMC33926MotorShield.h"

// Setup function for motor driver object
void motorSetup();

// Motor 1 specific acceleration functions
void M1Accelerate(int maxSpeed, int duration);
void M1Decelerate(int maxSpeed, int duration);

// Motor 2 specific acceleration functions
void M2Accelerate(int maxSpeed, int duration);
void M2Decelerate(int maxSpeed, int duration);

// Acceleration functions for both motors
void MAccelerate(int maxSpeed, int duration);
void MDecelerate(int maxSpeed, int duration);

void driveForTime(int maxSpeed, int rampSpeed, int driveTime);

void turnRight();

#endif
