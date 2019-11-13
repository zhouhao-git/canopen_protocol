
/* File generated by gen_cfile.py. Should not be modified. */

#include "SlaveNode.h"
#include "stm32f10x_type.h"
#include "stm32f10x_Timebase.h"
#include "MC_Globals.h"
#include "stm32f10x_Timebase.h"
/**************************************************************************/
/* Declaration of mapped variables                                        */
/**************************************************************************/
Objdict_RWData_s RW_data_s, *RW_dataPtr_s = &RW_data_s;
 
 
/**************************************************************************/
/* Declaration of value range types                                       */
/**************************************************************************/

#define valueRange_EMC 0x9F /* Type for index 0x1003 subindex 0x00 (only set of value 0 is possible) */
UNS32 SlaveNode_valueRangeTest (UNS8 typeValue, void * value)
{
  switch (typeValue) {
    case valueRange_EMC:
      if (*(UNS8*)value != (UNS8)0) return OD_VALUE_RANGE_EXCEEDED;
      break;
  }
  return 0;
}

/**************************************************************************/
/* The node id                                                            */
/**************************************************************************/
/* node_id default value.*/
UNS8 SlaveNode_bDeviceNodeId = 0x00;

/**************************************************************************/
/* Array of message processing information */

const UNS8 SlaveNode_iam_a_slave = 1;

TIMER_HANDLE SlaveNode_heartBeatTimers[1];

/*
$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

                               OBJECT DICTIONARY

$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
*/

/* index 0x1000 :   Device Type. */
                    UNS32 SlaveNode_obj1000 = 0x0;	/* 0 */
                    subindex SlaveNode_Index1000[] = 
                     {
                       { RO, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1000, NULL }
                     };

/* index 0x1001 :   Error Register. */
                    UNS8 SlaveNode_obj1001 = 0x0;	/* 0 */
                    subindex SlaveNode_Index1001[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&SlaveNode_obj1001, NULL }
                     };

/* index 0x1003 :   Pre-defined Error Field */
                    UNS8 SlaveNode_highestSubIndex_obj1003 = 0; /* number of subindex - 1*/
                    UNS32 SlaveNode_obj1003[] = 
                    {
                      0x0	/* 0 */
                    };
                    subindex SlaveNode_Index1003[] = 
                     {
                       { RW, valueRange_EMC, sizeof (UNS8), (void*)&SlaveNode_highestSubIndex_obj1003, NULL },
                       { RO, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1003[0], NULL }
                     };

/* index 0x1005 :   SYNC COB ID */
                    UNS32 SlaveNode_obj1005 = 0x0;   /* 0 */

/* index 0x1006 :   Communication / Cycle Period */
                    UNS32 SlaveNode_obj1006 = 0x0;   /* 0 */

/* index 0x100C :   Guard Time */ 
                    UNS16 SlaveNode_obj100C = 0x0;   /* 0 */

/* index 0x100D :   Life Time Factor */ 
                    UNS8 SlaveNode_obj100D = 0x0;   /* 0 */

/* index 0x1014 :   Emergency COB ID */
                    UNS32 SlaveNode_obj1014 = 0x80 + 0x00;   /* 128 + NodeID */

/* index 0x1016 :   Consumer Heartbeat Time */
                    UNS8 SlaveNode_highestSubIndex_obj1016 = 0;
                    UNS32 SlaveNode_obj1016[]={0};

/* index 0x1017 :   Producer Heartbeat Time */ 
                    UNS16 SlaveNode_obj1017 = 0x07D0;   /* 1000 */
                    subindex TestSlave_Index1017[] = 
                     {
                       { RW, uint16, sizeof (UNS16), (void*)&TestSlave_Index1017, NULL }
                     };

/* index 0x1018 :   Identity. */
                    UNS8 SlaveNode_highestSubIndex_obj1018 = 4; /* number of subindex - 1*/
                    UNS32 SlaveNode_obj1018_Vendor_ID = 0x0;	/* 0 */
                    UNS32 SlaveNode_obj1018_Product_Code = 0x0;	/* 0 */
                    UNS32 SlaveNode_obj1018_Revision_Number = 0x0;	/* 0 */
                    UNS32 SlaveNode_obj1018_Serial_Number = 0x0;	/* 0 */
                    subindex SlaveNode_Index1018[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&SlaveNode_highestSubIndex_obj1018, NULL },
                       { RO, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1018_Vendor_ID, NULL },
                       { RO, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1018_Product_Code, NULL },
                       { RO, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1018_Revision_Number, NULL },
                       { RO, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1018_Serial_Number, NULL }
                     };

/* index 0x1200 :   Server SDO Parameter. */
                    UNS8 SlaveNode_highestSubIndex_obj1200 = 2; /* number of subindex - 1*/
                    UNS32 SlaveNode_obj1200_COB_ID_Client_to_Server_Receive_SDO = 0x600;	/* 1536 */
                    UNS32 SlaveNode_obj1200_COB_ID_Server_to_Client_Transmit_SDO = 0x580;	/* 1408 */
                    subindex SlaveNode_Index1200[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&SlaveNode_highestSubIndex_obj1200, NULL },
                       { RO, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1200_COB_ID_Client_to_Server_Receive_SDO, NULL },
                       { RO, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1200_COB_ID_Server_to_Client_Transmit_SDO, NULL }
                     };

/* index 0x1400 :   Receive PDO 1 Parameter. */
                    UNS8 SlaveNode_highestSubIndex_obj1400 = 6; /* number of subindex - 1*/
                    UNS32 SlaveNode_obj1400_COB_ID_used_by_PDO = 0x200;	/* 512 */
                    UNS8 SlaveNode_obj1400_Transmission_Type = 0x0;	/* 0 */
                    UNS16 SlaveNode_obj1400_Inhibit_Time = 0x0;	/* 0 */
                    UNS8 SlaveNode_obj1400_Compatibility_Entry = 0x0;	/* 0 */
                    UNS16 SlaveNode_obj1400_Event_Timer = 0x0;	/* 0 */
                    UNS8 SlaveNode_obj1400_SYNC_start_value = 0x0;	/* 0 */
                    subindex SlaveNode_Index1400[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&SlaveNode_highestSubIndex_obj1400, NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1400_COB_ID_used_by_PDO, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_obj1400_Transmission_Type, NULL },
                       { RW, uint16, sizeof (UNS16), (void*)&SlaveNode_obj1400_Inhibit_Time, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_obj1400_Compatibility_Entry, NULL },
                       { RW, uint16, sizeof (UNS16), (void*)&SlaveNode_obj1400_Event_Timer, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_obj1400_SYNC_start_value, NULL }
                     };

/* index 0x1401 :   Receive PDO 2 Parameter. */
                    UNS8 SlaveNode_highestSubIndex_obj1401 = 6; /* number of subindex - 1*/
                    UNS32 SlaveNode_obj1401_COB_ID_used_by_PDO = 0x300;	/* 768 */
                    UNS8 SlaveNode_obj1401_Transmission_Type = 0x0;	/* 0 */
                    UNS16 SlaveNode_obj1401_Inhibit_Time = 0x0;	/* 0 */
                    UNS8 SlaveNode_obj1401_Compatibility_Entry = 0x0;	/* 0 */
                    UNS16 SlaveNode_obj1401_Event_Timer = 0x0;	/* 0 */
                    UNS8 SlaveNode_obj1401_SYNC_start_value = 0x0;	/* 0 */
                    subindex SlaveNode_Index1401[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&SlaveNode_highestSubIndex_obj1401, NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1401_COB_ID_used_by_PDO, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_obj1401_Transmission_Type, NULL },
                       { RW, uint16, sizeof (UNS16), (void*)&SlaveNode_obj1401_Inhibit_Time, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_obj1401_Compatibility_Entry, NULL },
                       { RW, uint16, sizeof (UNS16), (void*)&SlaveNode_obj1401_Event_Timer, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_obj1401_SYNC_start_value, NULL }
                     };

/* index 0x1402 :   Receive PDO 3 Parameter. */
                    UNS8 SlaveNode_highestSubIndex_obj1402 = 6; /* number of subindex - 1*/
                    UNS32 SlaveNode_obj1402_COB_ID_used_by_PDO = 0x400;	/* 1024 */
                    UNS8 SlaveNode_obj1402_Transmission_Type = 0x0;	/* 0 */
                    UNS16 SlaveNode_obj1402_Inhibit_Time = 0x0;	/* 0 */
                    UNS8 SlaveNode_obj1402_Compatibility_Entry = 0x0;	/* 0 */
                    UNS16 SlaveNode_obj1402_Event_Timer = 0x0;	/* 0 */
                    UNS8 SlaveNode_obj1402_SYNC_start_value = 0x0;	/* 0 */
                    subindex SlaveNode_Index1402[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&SlaveNode_highestSubIndex_obj1402, NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1402_COB_ID_used_by_PDO, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_obj1402_Transmission_Type, NULL },
                       { RW, uint16, sizeof (UNS16), (void*)&SlaveNode_obj1402_Inhibit_Time, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_obj1402_Compatibility_Entry, NULL },
                       { RW, uint16, sizeof (UNS16), (void*)&SlaveNode_obj1402_Event_Timer, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_obj1402_SYNC_start_value, NULL }
                     };

/* index 0x1403 :   Receive PDO 4 Parameter. */
                    UNS8 SlaveNode_highestSubIndex_obj1403 = 6; /* number of subindex - 1*/
                    UNS32 SlaveNode_obj1403_COB_ID_used_by_PDO = 0x500;	/* 1280 */
                    UNS8 SlaveNode_obj1403_Transmission_Type = 0x0;	/* 0 */
                    UNS16 SlaveNode_obj1403_Inhibit_Time = 0x0;	/* 0 */
                    UNS8 SlaveNode_obj1403_Compatibility_Entry = 0x0;	/* 0 */
                    UNS16 SlaveNode_obj1403_Event_Timer = 0x0;	/* 0 */
                    UNS8 SlaveNode_obj1403_SYNC_start_value = 0x0;	/* 0 */
                    subindex SlaveNode_Index1403[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&SlaveNode_highestSubIndex_obj1403, NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1403_COB_ID_used_by_PDO, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_obj1403_Transmission_Type, NULL },
                       { RW, uint16, sizeof (UNS16), (void*)&SlaveNode_obj1403_Inhibit_Time, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_obj1403_Compatibility_Entry, NULL },
                       { RW, uint16, sizeof (UNS16), (void*)&SlaveNode_obj1403_Event_Timer, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_obj1403_SYNC_start_value, NULL }
                     };

/* index 0x1600 :   Receive PDO 1 Mapping. */
                    UNS8 SlaveNode_highestSubIndex_obj1600 = 8; /* number of subindex - 1*/
                    UNS32 SlaveNode_obj1600[] = 
                    {
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0	/* 0 */
                    };
                    subindex SlaveNode_Index1600[] = 
                     {
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_highestSubIndex_obj1600, NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1600[0], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1600[1], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1600[2], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1600[3], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1600[4], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1600[5], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1600[6], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1600[7], NULL }
                     };

/* index 0x1601 :   Receive PDO 2 Mapping. */
                    UNS8 SlaveNode_highestSubIndex_obj1601 = 8; /* number of subindex - 1*/
                    UNS32 SlaveNode_obj1601[] = 
                    {
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0	/* 0 */
                    };
                    subindex SlaveNode_Index1601[] = 
                     {
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_highestSubIndex_obj1601, NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1601[0], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1601[1], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1601[2], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1601[3], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1601[4], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1601[5], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1601[6], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1601[7], NULL }
                     };

/* index 0x1602 :   Receive PDO 3 Mapping. */
                    UNS8 SlaveNode_highestSubIndex_obj1602 = 8; /* number of subindex - 1*/
                    UNS32 SlaveNode_obj1602[] = 
                    {
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0	/* 0 */
                    };
                    subindex SlaveNode_Index1602[] = 
                     {
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_highestSubIndex_obj1602, NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1602[0], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1602[1], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1602[2], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1602[3], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1602[4], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1602[5], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1602[6], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1602[7], NULL }
                     };

/* index 0x1603 :   Receive PDO 4 Mapping. */
                    UNS8 SlaveNode_highestSubIndex_obj1603 = 8; /* number of subindex - 1*/
                    UNS32 SlaveNode_obj1603[] = 
                    {
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0	/* 0 */
                    };
                    subindex SlaveNode_Index1603[] = 
                     {
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_highestSubIndex_obj1603, NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1603[0], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1603[1], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1603[2], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1603[3], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1603[4], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1603[5], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1603[6], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1603[7], NULL }
                     };

					 
/* index 0x1800 :   Transmit PDO 1 Parameter. */
                    UNS8 SlaveNode_highestSubIndex_obj1800 = 6; /* number of subindex - 1*/
                    UNS32 SlaveNode_obj1800_COB_ID_used_by_PDO = 0x180;	/* 384 */
                    UNS8 SlaveNode_obj1800_Transmission_Type = 0x0;	/* 0 */
                    UNS16 SlaveNode_obj1800_Inhibit_Time = 0x0;	/* 0 */
                    UNS8 SlaveNode_obj1800_Compatibility_Entry = 0x0;	/* 0 */
                    UNS16 SlaveNode_obj1800_Event_Timer = 0x0;	/* 0 */
                    UNS8 SlaveNode_obj1800_SYNC_start_value = 0x0;	/* 0 */
                    subindex SlaveNode_Index1800[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&SlaveNode_highestSubIndex_obj1800, NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1800_COB_ID_used_by_PDO, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_obj1800_Transmission_Type, NULL },
                       { RW, uint16, sizeof (UNS16), (void*)&SlaveNode_obj1800_Inhibit_Time, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_obj1800_Compatibility_Entry, NULL },
                       { RW, uint16, sizeof (UNS16), (void*)&SlaveNode_obj1800_Event_Timer, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_obj1800_SYNC_start_value, NULL }
                     };

/* index 0x1801 :   Transmit PDO 2 Parameter. */
                    UNS8 SlaveNode_highestSubIndex_obj1801 = 6; /* number of subindex - 1*/
                    UNS32 SlaveNode_obj1801_COB_ID_used_by_PDO = 0x280;	/* 640 */
                    UNS8 SlaveNode_obj1801_Transmission_Type = 0x0;	/* 0 */
                    UNS16 SlaveNode_obj1801_Inhibit_Time = 0x0;	/* 0 */
                    UNS8 SlaveNode_obj1801_Compatibility_Entry = 0x0;	/* 0 */
                    UNS16 SlaveNode_obj1801_Event_Timer = 0x0;	/* 0 */
                    UNS8 SlaveNode_obj1801_SYNC_start_value = 0x0;	/* 0 */
                    subindex SlaveNode_Index1801[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&SlaveNode_highestSubIndex_obj1801, NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1801_COB_ID_used_by_PDO, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_obj1801_Transmission_Type, NULL },
                       { RW, uint16, sizeof (UNS16), (void*)&SlaveNode_obj1801_Inhibit_Time, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_obj1801_Compatibility_Entry, NULL },
                       { RW, uint16, sizeof (UNS16), (void*)&SlaveNode_obj1801_Event_Timer, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_obj1801_SYNC_start_value, NULL }
                     };

/* index 0x1802 :   Transmit PDO 3 Parameter. */
                    UNS8 SlaveNode_highestSubIndex_obj1802 = 6; /* number of subindex - 1*/
                    UNS32 SlaveNode_obj1802_COB_ID_used_by_PDO = 0x380;	/* 896 */
                    UNS8 SlaveNode_obj1802_Transmission_Type = 0x0;	/* 0 */
                    UNS16 SlaveNode_obj1802_Inhibit_Time = 0x0;	/* 0 */
                    UNS8 SlaveNode_obj1802_Compatibility_Entry = 0x0;	/* 0 */
                    UNS16 SlaveNode_obj1802_Event_Timer = 0x0;	/* 0 */
                    UNS8 SlaveNode_obj1802_SYNC_start_value = 0x0;	/* 0 */
                    subindex SlaveNode_Index1802[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&SlaveNode_highestSubIndex_obj1802, NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1802_COB_ID_used_by_PDO, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_obj1802_Transmission_Type, NULL },
                       { RW, uint16, sizeof (UNS16), (void*)&SlaveNode_obj1802_Inhibit_Time, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_obj1802_Compatibility_Entry, NULL },
                       { RW, uint16, sizeof (UNS16), (void*)&SlaveNode_obj1802_Event_Timer, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_obj1802_SYNC_start_value, NULL }
                     };

/* index 0x1803 :   Transmit PDO 4 Parameter. */
                    UNS8 SlaveNode_highestSubIndex_obj1803 = 6; /* number of subindex - 1*/
                    UNS32 SlaveNode_obj1803_COB_ID_used_by_PDO = 0x480;	/* 1152 */
                    UNS8 SlaveNode_obj1803_Transmission_Type = 0x0;	/* 0 */
                    UNS16 SlaveNode_obj1803_Inhibit_Time = 0x0;	/* 0 */
                    UNS8 SlaveNode_obj1803_Compatibility_Entry = 0x0;	/* 0 */
                    UNS16 SlaveNode_obj1803_Event_Timer = 0x0;	/* 0 */
                    UNS8 SlaveNode_obj1803_SYNC_start_value = 0x0;	/* 0 */
                    subindex SlaveNode_Index1803[] = 
                     {
                       { RO, uint8, sizeof (UNS8), (void*)&SlaveNode_highestSubIndex_obj1803, NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1803_COB_ID_used_by_PDO, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_obj1803_Transmission_Type, NULL },
                       { RW, uint16, sizeof (UNS16), (void*)&SlaveNode_obj1803_Inhibit_Time, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_obj1803_Compatibility_Entry, NULL },
                       { RW, uint16, sizeof (UNS16), (void*)&SlaveNode_obj1803_Event_Timer, NULL },
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_obj1803_SYNC_start_value, NULL }
                     };

/* index 0x1A00 :   Transmit PDO 1 Mapping. */
                    UNS8 SlaveNode_highestSubIndex_obj1A00 = 8; /* number of subindex - 1*/
                    UNS32 SlaveNode_obj1A00[] = 
                    {
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0	/* 0 */
                    };
                    subindex SlaveNode_Index1A00[] = 
                     {
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_highestSubIndex_obj1A00, NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A00[0], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A00[1], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A00[2], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A00[3], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A00[4], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A00[5], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A00[6], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A00[7], NULL }
                     };

/* index 0x1A01 :   Transmit PDO 2 Mapping. */
                    UNS8 SlaveNode_highestSubIndex_obj1A01 = 8; /* number of subindex - 1*/
                    UNS32 SlaveNode_obj1A01[] = 
                    {
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0	/* 0 */
                    };
                    subindex SlaveNode_Index1A01[] = 
                     {
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_highestSubIndex_obj1A01, NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A01[0], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A01[1], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A01[2], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A01[3], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A01[4], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A01[5], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A01[6], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A01[7], NULL }
                     };

/* index 0x1A02 :   Transmit PDO 3 Mapping. */
                    UNS8 SlaveNode_highestSubIndex_obj1A02 = 8; /* number of subindex - 1*/
                    UNS32 SlaveNode_obj1A02[] = 
                    {
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0	/* 0 */
                    };
                    subindex SlaveNode_Index1A02[] = 
                     {
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_highestSubIndex_obj1A02, NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A02[0], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A02[1], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A02[2], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A02[3], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A02[4], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A02[5], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A02[6], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A02[7], NULL }
                     };

/* index 0x1A03 :   Transmit PDO 4 Mapping. */
                    UNS8 SlaveNode_highestSubIndex_obj1A03 = 8; /* number of subindex - 1*/
                    UNS32 SlaveNode_obj1A03[] = 
                    {
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0,	/* 0 */
                      0x0	/* 0 */
                    };
                    subindex SlaveNode_Index1A03[] = 
                     {
                       { RW, uint8, sizeof (UNS8), (void*)&SlaveNode_highestSubIndex_obj1A03, NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A03[0], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A03[1], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A03[2], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A03[3], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A03[4], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A03[5], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A03[6], NULL },
                       { RW, uint32, sizeof (UNS32), (void*)&SlaveNode_obj1A03[7], NULL }
                     };

					 
/****************user defined***************/
/* index 0x6003 :    RW MotorEnable\WorkMode\D\R*/											
					 UNS8 SlaveNode_highestSubIndex_obj6003 = 0; //������Ϊ��1������0��ʼ������
					 subindex SlaveNode_Index6003[] = 
					 {
						{RW, uint32, sizeof(UNS32), (void *)&RW_data_s.Gears_Status, NULL}, 
						//{RW, uint32, sizeof(UNS16), (void *)&hBusV_Percent_F}
					 };//���������Ķ�д���ԡ��������͡����ݴ�С����������
					 
/* index 0x6040 :    Motor speedcmd*/	
					 UNS8 SlaveNode_highestSubIndex_obj6040 = 2;
					 subindex SlaveNode_Index6040[]=
					 {
						 {RW, int16, sizeof(s16), (void*)&RW_data_s.SpeedCmdVal, NULL},
						 {RW, int16, sizeof(s16), (void*)&RW_data_s.TorqueCmdVal, NULL},
						 {RW, int16, sizeof(s16), (void*)&RW_data_s.testval, NULL},
					 };

/* index 0x6041 :    Read BusVoltage and speed */	
					 UNS8 SlaveNode_highestSubIndex_obj6041 = 1;
					 subindex SlaveNode_Index6041[]=
					 {
						 {RO, uint16, sizeof(UNS16), (void*)&RW_data_s.BusVoltage, NULL},
						 {RO, int16, sizeof(s16), (void*)&RW_data_s.Speedingrpm, NULL},
					 };
/* index 0x6064 :		Read Iqref/Iqact/maxIq */
					 UNS8 SloveNode_highestSubindex_obj6064 = 2;
					 subindex SlaveNode_Index6064[]=
					 {
						{RO, uint16, sizeof(UNS16), (void*)&RW_data_s.Iqref_peak, NULL},
						{RO, uint16, sizeof(UNS16), (void*)&RW_data_s.Iqactual_peak, NULL},
						{RO, uint16, sizeof(UNS16), (void*)&RW_data_s.PhaseCurrent_MaxPeak, NULL},
					 };
/**************************************************************************/
/* Declaration of pointed variables                                       */
/**************************************************************************/

const indextable SlaveNode_objdict[] = 
{
  { (subindex*)SlaveNode_Index1000,sizeof(SlaveNode_Index1000)/sizeof(SlaveNode_Index1000[0]), 0x1000},
  { (subindex*)SlaveNode_Index1001,sizeof(SlaveNode_Index1001)/sizeof(SlaveNode_Index1001[0]), 0x1001},
  { (subindex*)SlaveNode_Index1018,sizeof(SlaveNode_Index1018)/sizeof(SlaveNode_Index1018[0]), 0x1018},
  { (subindex*)SlaveNode_Index1200,sizeof(SlaveNode_Index1200)/sizeof(SlaveNode_Index1200[0]), 0x1200},
  { (subindex*)SlaveNode_Index1400,sizeof(SlaveNode_Index1400)/sizeof(SlaveNode_Index1400[0]), 0x1400},
  { (subindex*)SlaveNode_Index1401,sizeof(SlaveNode_Index1401)/sizeof(SlaveNode_Index1401[0]), 0x1401},
  { (subindex*)SlaveNode_Index1402,sizeof(SlaveNode_Index1402)/sizeof(SlaveNode_Index1402[0]), 0x1402},
  { (subindex*)SlaveNode_Index1403,sizeof(SlaveNode_Index1403)/sizeof(SlaveNode_Index1403[0]), 0x1403},
  { (subindex*)SlaveNode_Index1600,sizeof(SlaveNode_Index1600)/sizeof(SlaveNode_Index1600[0]), 0x1600},
  { (subindex*)SlaveNode_Index1601,sizeof(SlaveNode_Index1601)/sizeof(SlaveNode_Index1601[0]), 0x1601},
  { (subindex*)SlaveNode_Index1602,sizeof(SlaveNode_Index1602)/sizeof(SlaveNode_Index1602[0]), 0x1602},
  { (subindex*)SlaveNode_Index1603,sizeof(SlaveNode_Index1603)/sizeof(SlaveNode_Index1603[0]), 0x1603},
  { (subindex*)SlaveNode_Index1800,sizeof(SlaveNode_Index1800)/sizeof(SlaveNode_Index1800[0]), 0x1800},
  { (subindex*)SlaveNode_Index1801,sizeof(SlaveNode_Index1801)/sizeof(SlaveNode_Index1801[0]), 0x1801},
  { (subindex*)SlaveNode_Index1802,sizeof(SlaveNode_Index1802)/sizeof(SlaveNode_Index1802[0]), 0x1802},
  { (subindex*)SlaveNode_Index1803,sizeof(SlaveNode_Index1803)/sizeof(SlaveNode_Index1803[0]), 0x1803},
  { (subindex*)SlaveNode_Index1A00,sizeof(SlaveNode_Index1A00)/sizeof(SlaveNode_Index1A00[0]), 0x1A00},
  { (subindex*)SlaveNode_Index1A01,sizeof(SlaveNode_Index1A01)/sizeof(SlaveNode_Index1A01[0]), 0x1A01},
  { (subindex*)SlaveNode_Index1A02,sizeof(SlaveNode_Index1A02)/sizeof(SlaveNode_Index1A02[0]), 0x1A02},
  { (subindex*)SlaveNode_Index1A03,sizeof(SlaveNode_Index1A03)/sizeof(SlaveNode_Index1A03[0]), 0x1A03},
  { (subindex*)SlaveNode_Index6003,sizeof(SlaveNode_Index6003)/sizeof(SlaveNode_Index6003[0]), 0x6003},
  { (subindex*)SlaveNode_Index6040,sizeof(SlaveNode_Index6040)/sizeof(SlaveNode_Index6040[0]), 0x6040},
  { (subindex*)SlaveNode_Index6041,sizeof(SlaveNode_Index6041)/sizeof(SlaveNode_Index6041[0]), 0x6041},
  { (subindex*)SlaveNode_Index6064,sizeof(SlaveNode_Index6064)/sizeof(SlaveNode_Index6064[0]), 0x6064},
};

const indextable * SlaveNode_scanIndexOD (CO_Data *d, UNS16 wIndex, UNS32 * errorCode)
{
	int i;
	switch(wIndex){
		case 0x1000: i = 0;break;
		case 0x1001: i = 1;break;
		case 0x1018: i = 2;break;
		case 0x1200: i = 3;break;
		case 0x1400: i = 4;break;
		case 0x1401: i = 5;break;
		case 0x1402: i = 6;break;
		case 0x1403: i = 7;break;
		case 0x1600: i = 8;break;
		case 0x1601: i = 9;break;
		case 0x1602: i = 10;break;
		case 0x1603: i = 11;break;
		case 0x1800: i = 12;break;
		case 0x1801: i = 13;break;
		case 0x1802: i = 14;break;
		case 0x1803: i = 15;break;
		case 0x1A00: i = 16;break;
		case 0x1A01: i = 17;break;
		case 0x1A02: i = 18;break;
		case 0x1A03: i = 19;break;
		case 0x6003: i = 20;break;
		case 0x6040: i = 21;break;
		case 0x6041: i = 22;break;
		case 0x6064: i = 23;break;
		default:
			*errorCode = OD_NO_SUCH_OBJECT;
			return NULL;
	}
	*errorCode = OD_SUCCESSFUL;
	return &SlaveNode_objdict[i];
}

/* 
 * To count at which received SYNC a PDO must be sent.
 * Even if no pdoTransmit are defined, at least one entry is computed
 * for compilations issues.
 */
s_PDO_status SlaveNode_PDO_status[4] = {s_PDO_status_Initializer,s_PDO_status_Initializer,s_PDO_status_Initializer,s_PDO_status_Initializer};

const quick_index SlaveNode_firstIndex = {
  3, /* SDO_SVR */
  0, /* SDO_CLT */
  4, /* PDO_RCV */
  8, /* PDO_RCV_MAP */
  12, /* PDO_TRS */
  16 /* PDO_TRS_MAP */
};

const quick_index SlaveNode_lastIndex = {
  3, /* SDO_SVR */
  0, /* SDO_CLT */
  7, /* PDO_RCV */
  11, /* PDO_RCV_MAP */
  15, /* PDO_TRS */
  19 /* PDO_TRS_MAP */
};

const UNS16 SlaveNode_ObjdictSize = sizeof(SlaveNode_objdict)/sizeof(SlaveNode_objdict[0]); 

CO_Data SlaveNode_Data = CANOPEN_NODE_DATA_INITIALIZER(SlaveNode);
volatile s16 test;
inline void ReadWrite_ObjdictData(Objdict_RWData_s *data)
{
	/* ����/��ȡ�����λ��Ϣ */
	if((data->Gears_Status & 0x03) == 0x1)
	{
		if( ((Forward_trigger = TRUE) && !(FR_trigger = FALSE)) )
		{
			data->Gears_Status |= 0x01;
		}
	}
	else if((data->Gears_Status & 0x03) == 0x02)
	{
		if( (!(Forward_trigger = FALSE) && (FR_trigger = TRUE)) )
		{
			data->Gears_Status |= 0x02;
		}
	}
	else 
	{
		Forward_trigger = FALSE;
		FR_trigger = FALSE;
	}
	
	/* ����/��ȡ���ʹ���ź� */
	if(((data->Gears_Status >> 24) & 0x01) == 0x01)
	{
		data->MotorEnable = 1;
	}
	else
	{
		data->MotorEnable = 0;
	}	
	if(data->MotorEnable)
	{
		data->Gears_Status |= 0x01000000;
	}

	/* ����/��ȡ����Ĺ���ģʽ */
	if(((data->Gears_Status >> 8) & 0x03) == 0x01)
	{
		if((data->MotorWorkMode = SPEEDMODE) == 0x01)
		{
			data->Gears_Status |= 0x0100;
		}
	}
	else if(((data->Gears_Status >> 8) & 0x03) == 0x02)
	{
		if((data->MotorWorkMode = TORQUEMODE) == 0x02)
		{
			data->Gears_Status |= 0x0200;
		}
	}
	else
	{
		data->MotorWorkMode = POSMODE;
	}
				
	data->BusVoltage = hBusV_Percent_F;
	data->Speedingrpm = speedinrpm_filter;	
	data->Iqref_peak = iqreference;
	data->Iqactual_peak = iqactual_filter;
	
}