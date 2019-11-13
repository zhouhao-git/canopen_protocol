/*
This file is part of CanFestival, a library implementing CanOpen Stack.

Copyright (C): Edouard TISSERANT and Francis DUPIN

See COPYING file for copyrights details.

This library is free software; you can redistribute it and/or
modify it under the terms of the GNU Lesser General Public
License as published by the Free Software Foundation; either
version 2.1 of the License, or (at your option) any later version.

This library is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public
License along with this library; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef __timer_h__
#define __timer_h__

#include <timerscfg.h>
#include <applicfg.h>

#define TIMER_HANDLE INTEGER16

#include "data.h"


/* --------- types and constants definitions --------- */
/*��ʱ�¼����״̬*/
#define TIMER_FREE 0            /*���У��������û�б���ʱ���¼�ռ��*/
#define TIMER_ARMED 1			/*��ռ�ã���������ѱ���ʱ���¼�ռ��*/
#define TIMER_TRIG 2			/*���δ���*/
#define TIMER_TRIG_PERIOD 3		/*���ڴ���*/

#define TIMER_NONE -1

typedef void (*TimerCallback_t)(CO_Data* d, UNS32 id);

struct struct_s_timer_entry {
	UNS8 state;				/*�¼�״̬*/
	CO_Data* d;				/*�ڵ�ָ��*/
	TimerCallback_t callback; /* The callback func. */
	UNS32 id; 				/* �ص��������������������¼� */
	TIMEVAL val;			/*��ʱʱ��*/
	TIMEVAL interval; 		/* Periodicity �Ƿ����ڳ�����0��ʾ���δ�������0��ʾ���ڴ���*/
};

typedef struct struct_s_timer_entry s_timer_entry;

/* ---------  prototypes --------- */
/*#define SetAlarm(d, id, callback, value, period) printf("%s, %d, SetAlarm(%s, %s, %s, %s, %s)\n",__FILE__, __LINE__, #d, #id, #callback, #value, #period); _SetAlarm(d, id, callback, value, period)*/
/**
 * @ingroup timer
 * @brief Set an alarm to execute a callback function when expired.
 * @param *d Pointer to a CAN object data structure
 * @param id The alarm Id
 * @param callback A callback function
 * @param value Call the callback function at current time + value
 * @param period Call periodically the callback function
 * @return handle The timer handle
 */
TIMER_HANDLE SetAlarm(CO_Data* d, UNS32 id, TimerCallback_t callback, TIMEVAL value, TIMEVAL period);

/**
 * @ingroup timer
 * @brief Delete an alarm before expiring.
 * @param handle A timer handle
 * @return The timer handle
 */
TIMER_HANDLE DelAlarm(TIMER_HANDLE handle);

void TimeDispatch(void);

/**
 * @ingroup timer
 * @brief Set a timerfor a given time.
 * @param value The time value.
 */
void setTimer(TIMEVAL value);

/**
 * @ingroup timer
 * @brief Get the time elapsed since latest timer occurence.
 * @return time elapsed since latest timer occurence
 */
TIMEVAL getElapsedTime(void);

#endif /* #define __timer_h__ */
