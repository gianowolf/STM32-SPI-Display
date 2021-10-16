#include "data_manager.h"

/* Private Functions */

static float therm_buffer[THERM_BUFFERSIZE];
static uint8_t therm_pointer;

int store(float value)
{
		therm_buffer[therm_pointer++] = value;
		therm_pointer = therm_pointer % THERM_BUFFERSIZE;
	printf("\n stored %d:%f",therm_pointer,value);
	return 0;
}

float get_printable()
{
    float average = 0;
	  int i;
	
    for(i = 0 ; i < THERM_BUFFERSIZE ; i++ ){
        average+=therm_buffer[i];
    }
		//average*=THERM_INVERSE;
		average=average/50.0f;
    return average;
}

/* Public Functions */

int DATAMANAGER_Init()
{
    for(uint8_t i = 0 ; i < THERM_BUFFERSIZE ; i++ ){
        therm_buffer[i]=0;
    }
    therm_pointer = 0;

    return 0;
}

int DATAMANAGER_Read()
{
    store(SENSOR_GetTemperature());
    return 0;
}

int DATAMANAGER_Write()
{
		 float value = get_printable();
     printf("\nTEMPERATURA:  %f C \n", value);
	
	//LCD_sendString();

    return 0;
}
