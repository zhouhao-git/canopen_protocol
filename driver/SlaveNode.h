
/* File generated by gen_cfile.py. Should not be modified. */

#ifndef SLAVENODE_H
#define SLAVENODE_H

#include "data.h"
#include "stm32f10x_MClib.h"
#include "stdlib.h"


#define SPEEDMODE  0X01
#define TORQUEMODE 0X02
#define POSMODE    0X03

typedef struct 
{
volatile UNS32 Gears_Status;
volatile UNS16 BusVoltage;
volatile s16   Speedingrpm;
		 u8    MotorEnable;
		 u8    MotorWorkMode;
		 s16   SpeedCmdVal;
		 s16   TorqueCmdVal;
		 s16   testval;
		 u16   Iqref_peak;;
		 u16   Iqactual_peak;
		 u16   PhaseCurrent_MaxPeak;
}Objdict_RWData_s;

/* Prototypes of function provided by object dictionnary */
UNS32 SlaveNode_valueRangeTest (UNS8 typeValue, void * value);
const indextable * SlaveNode_scanIndexOD (CO_Data *d, UNS16 wIndex, UNS32 * errorCode);

void ReadWrite_ObjdictData(Objdict_RWData_s *data);

/* Master node data struct */
extern CO_Data SlaveNode_Data;

#endif // SLAVENODE_H
