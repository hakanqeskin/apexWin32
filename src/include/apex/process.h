/*
 * process.h
 *
 *  Created on: Jan 27, 2022
 *      Author: hakan.keskin
 */

#ifndef APEX_PROCESS_H_
#define APEX_PROCESS_H_

/*---------------------------------------------------------------*/
/* 																 */
/* PROCESS constant and type definitions and management services */
/* 																 */
/*---------------------------------------------------------------*/

#include "types.h"


#define MAX_NUMBER_OF_PROCESSES SYSTEM_LIMIT_NUMBER_OF_PROCESSES

#define MIN_PRIORITY_VALUE 1
#define MAX_PRIORITY_VALUE 239

#define MAX_LOCK_LEVEL 16

//#define NULL_PROCESS_ID 0
#define NULL_PROCESS_ID -1

#ifdef __cplusplus
extern "C" {
#endif

typedef NAME_TYPE PROCESS_NAME_TYPE;

typedef APEX_INTEGER LOCK_LEVEL_TYPE;

typedef APEX_INTEGER PRIORITY_TYPE;

typedef enum {
	DORMANT = 0,
	READY = 1,
	RUNNING = 2,
	WAITING = 3
} PROCESS_STATE_TYPE;

typedef struct {
	SYSTEM_TIME_TYPE PERIOD;
	SYSTEM_TIME_TYPE TIME_CAPACITY;
	SYSTEM_ADDRESS_TYPE ENTRY_POINT;
	STACK_SIZE_TYPE STACK_SIZE;
	PRIORITY_TYPE BASE_PRIORITY;
	DEADLINE_TYPE DEADLINE;
	PROCESS_NAME_TYPE NAME;
} PROCESS_ATTRIBUTE_TYPE;

typedef struct {
	SYSTEM_TIME_TYPE DEADLINE_TIME;
	PRIORITY_TYPE CURRENT_PRIORITY;
	PROCESS_STATE_TYPE PROCESS_STATE;
	PROCESS_ATTRIBUTE_TYPE ATTRIBUTES;
} PROCESS_STATUS_TYPE;

void CREATE_PROCESS (
 /*in */ PROCESS_ATTRIBUTE_TYPE *,
 /*out*/ PROCESS_ID_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void SET_PRIORITY(
/*in */ PROCESS_ID_TYPE,
/*in */ PRIORITY_TYPE,
/*out*/ RETURN_CODE_TYPE *);

void SUSPEND_SELF(
/*in */ SYSTEM_TIME_TYPE,
/*out*/ RETURN_CODE_TYPE *);

void SUSPEND(
/*in */ PROCESS_ID_TYPE,
/*out*/ RETURN_CODE_TYPE *);

void RESUME(
/*in */ PROCESS_ID_TYPE,
/*out*/ RETURN_CODE_TYPE *);

void STOP_SELF(void);

void STOP(
/*in */ PROCESS_ID_TYPE,
/*out*/ RETURN_CODE_TYPE *);

void START (
/*in */ PROCESS_ID_TYPE,
/*out*/ RETURN_CODE_TYPE *);

void DELAYED_START(
/*in */ PROCESS_ID_TYPE,
/*in */ SYSTEM_TIME_TYPE,
/*out*/ RETURN_CODE_TYPE *);

void LOCK_PREEMPTION(
/*out*/ LOCK_LEVEL_TYPE *,
/*out*/ RETURN_CODE_TYPE *);

void UNLOCK_PREEMPTION(
/*out*/ LOCK_LEVEL_TYPE *,
/*out*/ RETURN_CODE_TYPE *);

void GET_MY_ID(
/*out*/ PROCESS_ID_TYPE *,
/*out*/ RETURN_CODE_TYPE *);

void GET_PROCESS_ID(
/*in */ PROCESS_NAME_TYPE,
/*out*/ PROCESS_ID_TYPE *,
/*out*/ RETURN_CODE_TYPE *);

void GET_PROCESS_STATUS(
/*in */ PROCESS_ID_TYPE PROCESS_ID,
/*out*/ PROCESS_STATUS_TYPE *,
/*out*/ RETURN_CODE_TYPE *);

#ifdef __cplusplus
}
#endif

#endif /* APEX_PROCESS_H_ */
