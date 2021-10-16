#ifndef _SEOS_H
#define _SEOS_H

#include "stm32f10x.h" 
#include <inttypes.h>
#include <stdio.h>

/* Overflow */
/* nro de tick del sistema en el que se debe ejecutar la tarea y reiniciar el contador */
#define OVERF_READ 20  //  0.2s
#define OVERF_WRITE 500  // 5 s

/* Out of Phase */
/* Configuracion para evitar que las tareas se deban ejecutar en el mismo tick del sistema */
#define OOPH_WRITE 499
#define OOPH_READ 1 

/* Public Functions */
int SEOS_Boot(void);

int SEOS_Schedule(void);

int SEOS_Dispatch(void);

int SEOS_Sleep(void);

/* Private Functions */
int seos_init(void);

#endif
