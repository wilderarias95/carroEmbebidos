#include "MKL27Z644.h"
#include "fsl_debug_console.h"
#include <time.h>
#include <stdio.h>

void InitDriver(int MotorKV, float WheelR, float MaxFwSpeed, float MinFwSpeed, float MaxBwSpeed, float MinBwSpeed);
void InitPit(void);
void ConfigTimePit(int time);
void SetDuty(int delay, int duty);
int SetBackwardSpeed(float Speed);
int SetFordwardSpeed(float Speed);
void Stop(void);
float GetForwardSpeed(float WheelR, float duty);
float GetBackwardSpeed(float WheelR, float duty);
int GetForwardDuty(float WheelR, float speed);
int GetBackwardDuty(float WheelR, float speed);
