#ifndef _DATAMANAGER_H
#define _DATAMANAGER_H
          
#include <stdint.h>

#include "lcd.h"
#include "sensor.h"
#include <stdio.h>

/************** Device Setup *************/

//Config
#define THERM_BUFFERSIZE 50
#define THERM_INVERSE 0.02

/*****************************************/

/* Public Functions */
int DATAMANAGER_Init(void);
int DATAMANAGER_Read(void);
int DATAMANAGER_Write(void);

/* Private Functions */
int store(float value);
float get_printable(void);
#endif
