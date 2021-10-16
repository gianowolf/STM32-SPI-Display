#include "seos.h"
#include "sensor.h"
#include "data_manager.h"

/* PUBLIC FLAGS */
volatile uint16_t Flag_read;
volatile uint16_t Flag_write;

/* PRIVATE */
static uint16_t counter_read;
static uint16_t counter_write;


void SysTick_Handler(void)
{
	SEOS_Schedule();
}



int seos_init(void)
{
	Flag_read  = 0;
	Flag_write = 0;

	counter_write = OVERF_WRITE - OOPH_WRITE;
	counter_read  = OVERF_READ - OOPH_READ;

	if (SysTick_Config(SystemCoreClock / 1000)){
		//error handling
	}

	return 0;
}



int SEOS_Boot(void)
{
	seos_init();

	//LCD_Init();
	SENSOR_Init();

	DATAMANAGER_Init();

	return 0;
}



int SEOS_Schedule(void)
{
	if(++counter_read == OVERF_READ)
	{
		Flag_read   = 1; 
		counter_read = 0;
	}
	if(++counter_write == OVERF_WRITE)
	{
		Flag_write    = 1;
		counter_write = 0; 
	}
	return 0;
}



int SEOS_Dispatch(void)
{
	if(Flag_read)
	{
		DATAMANAGER_Read();
		Flag_read = 0;
	}
	
	if(Flag_write)
	{
	    DATAMANAGER_Write();
		Flag_write = 0;
	}

	return 0;
}



int SEOS_Sleep(void)
{
	return 0;
}
