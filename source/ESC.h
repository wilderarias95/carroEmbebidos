#include "MKL27Z644.h"
#include "fsl_debug_console.h"

void InitDriver(int MotorKV, float WheelR, float MaxFwSpeed, float MinFwSpeed, float MaxBwSpeed, float MinBwSpeed);
void SetSpeed(int delay, float speed);
int SetBackwardSpeed(float Speed);
int SetFordwardSpeed(float Speed);
void Stop(void);
