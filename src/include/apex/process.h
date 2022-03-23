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

#define NULL_PROCESS_ID 0

#ifdef __cplusplus
extern "C" {
#endif

typedef NAME_TYPE PROCESS_NAME_TYPE;

typedef APEX_INTEGER PROCESS_ID_TYPE;

typedef APEX_INTEGER LOCK_LEVEL_TYPE;

typedef APEX_UNSIGNED STACK_SIZE_TYPE;

typedef APEX_INTEGER PRIORITY_TYPE;

typedef enum {
	DORMANT = 0,
	READY = 1,
	RUNNING = 2,
	WAITING = 3
} PROCESS_STATE_TYPE;

typedef enum { SOFT = 0, HARD = 1 } DEADLINE_TYPE;

typedef struct {
	SYSTEM_TIME_TYPE PERIOD;
	SYSTEM_TIME_TYPE TIME_CAPACITY;
	SYSTEM_ADDRESS_TYPE ENTRY_POINT;
	STACK_SIZE_TYPE STACK_SIZE;
	PRIORITY_TYPE BASE_PRIORITY;
	DEADLINE_TYPE DEADLINE;
	PROCESS_NAME_TYPE NAME;
} PROCESS_ATTRIBUTE_TYPE;

void CREATE_PROCESS (
 /*in */ PROCESS_ATTRIBUTE_TYPE *,
 /*out*/ PROCESS_ID_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void START (
 /*in */ PROCESS_ID_TYPE,
 /*out*/ RETURN_CODE_TYPE *);

#ifdef __cplusplus
}
#endif


#endif /* APEX_PROCESS_H_ */
