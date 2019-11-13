#include "canfestival.h"
#include "MC_Globals.h"
#include "SlaveNode.h"
#include "TestMaster.h"


unsigned int TimeCNT = 0;//ʱ�����
unsigned int NextTime = 0;//��һ�δ���ʱ�����
unsigned int TIMER_MAX_COUNT = 70000;//���ʱ�����
static TIMEVAL last_time_set = TIMEVAL_MAX;//��һ�ε�ʱ�����


//Դ��������ʱ�ģ�ʱ�䵽�˾���Ҫ����һ�º���TimeDispatch()
void setTimer(TIMEVAL value)
{
	NextTime = (TimeCNT + value) % TIMER_MAX_COUNT;
}

//Դ��������ѯ������һ����ʱ�������ж���ʱ��
TIMEVAL getElapsedTime(void)
{
	
	int ret=0;
	ret = TimeCNT > last_time_set ? TimeCNT - last_time_set : TimeCNT + TIMER_MAX_COUNT - last_time_set;
	last_time_set = TimeCNT;
	return ret;
}

//Դ��������һ��CAN���ģ���Ҫ������������һ��CAN������ȥ
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


void timerForCan(void)  //systick 1ms����
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

