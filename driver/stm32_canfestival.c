#include "canfestival.h"
#include "MC_Globals.h"
#include "SlaveNode.h"
#include "TestMaster.h"


unsigned int TimeCNT = 0;//时间计数
unsigned int NextTime = 0;//下一次触发时间计数
unsigned int TIMER_MAX_COUNT = 70000;//最大时间计数
static TIMEVAL last_time_set = TIMEVAL_MAX;//上一次的时间计数


//源码用来定时的，时间到了就需要调用一下函数TimeDispatch()
void setTimer(TIMEVAL value)
{
	NextTime = (TimeCNT + value) % TIMER_MAX_COUNT;
}

//源码用来查询距离下一个定时触发还有多少时间
TIMEVAL getElapsedTime(void)
{
	
	int ret=0;
	ret = TimeCNT > last_time_set ? TimeCNT - last_time_set : TimeCNT + TIMER_MAX_COUNT - last_time_set;
	last_time_set = TimeCNT;
	return ret;
}

//源码用来发一个CAN包的，需要调用驱动来将一个CAN包发出去
unsigned char canSend(CAN_PORT notused, Message *m)
{
	u32  i;
    static CanTxMsg TxMessage;
    CanTxMsg *ptx_msg = &TxMessage;
    ptx_msg->StdId = m->cob_id;

    if(m->rtr)
		ptx_msg->RTR = CAN_RTR_REMOTE;
    else
		ptx_msg->RTR = CAN_RTR_DATA;

    ptx_msg->IDE = CAN_ID_STD;
    ptx_msg->DLC = m->len;
    for(i = 0; i < m->len; i++)
	{
		ptx_msg->Data[i] = m->data[i];
	}
    if( CAN_Transmit(ptx_msg) == CAN_NO_MB)
    {
        return 0xff;
    }
    else
    {
        return 0x00;
    }
}


void timerForCan(void)  //systick 1ms调用
{
	
	TimeCNT++;
	if (TimeCNT >= TIMER_MAX_COUNT)
	{
		TimeCNT = 0;
	}
	if (TimeCNT == NextTime)
	{
		TimeDispatch();
	}	
}


void USB_LP_CAN_RX0_IRQHandler(void)
{
	u8 i;
	
	CanRxMsg RxMessage;
	Message m;
	CAN_Receive(CAN_FIFO0, &RxMessage);
	m.cob_id = RxMessage.StdId;
	if(RxMessage.RTR == CAN_RTR_REMOTE)
	{
		m.rtr = 1;
	}
	else if(RxMessage.RTR == CAN_RTR_DATA)
	{
		m.rtr = 0;
	}
	m.len=RxMessage.DLC;
	for(i = 0; i < RxMessage.DLC; i++)
	{
		m.data[i] = (u8)RxMessage.Data[i];
	}
	canDispatch(&SlaveNode_Data, &m);
}




void Canpen_TestMaster_Demo(unsigned char MasterNodeID)
{
	setNodeId(&TestMaster_Data, MasterNodeID);
	setState(&TestMaster_Data, Initialisation);
	setState(&TestMaster_Data, Operational);
}

void CanOpen_TestSlave_Demo(unsigned char SlaveNodeID)
{
	setNodeId(&SlaveNode_Data, SlaveNodeID);
	setState(&SlaveNode_Data, Initialisation);
	setState(&SlaveNode_Data, Operational);
}

