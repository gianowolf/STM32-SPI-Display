#include "sensor.h"

static float temp;


int SENSOR_Init(void)
{
	temp = 20.0;
	return 0;
}

float SENSOR_GetTemperature(void)
{
	temp+=0.01f;
	return temp;
}
