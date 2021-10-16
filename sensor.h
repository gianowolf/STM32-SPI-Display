#ifndef _SENSOR_H
#define _SENSOR_H
          
#include <stdint.h>
#include <inttypes.h>

#include "lcd.h"
#include "sensor.h"


/* Public Functions */
int SENSOR_Init(void);
float SENSOR_GetTemperature(void);

/* Private Functions */
#endif
