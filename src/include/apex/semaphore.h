/*
 * semaphore.h
 *
 *  Created on: Jan 27, 2022
 *      Author: hakan.keskin
 */

#ifndef APEX_SEMAPHORE_H_
#define APEX_SEMAPHORE_H_

/*------------------------------------------------------------------*/
/* 																	*/
/* SEMAPHORE constant and type definitions and management services	*/
/* 																	*/
/*------------------------------------------------------------------*/

#include "types.h"


#define MAX_NUMBER_OF_SEMAPHORES SYSTEM_LIMIT_NUMBER_OF_SEMAPHORES

#define MAX_SEMAPHORE_VALUE 32767

#ifdef __cplusplus
extern "C" {
#endif

typedef NAME_TYPE SEMAPHORE_NAME_TYPE;

typedef APEX_INTEGER SEMAPHORE_ID_TYPE;

typedef APEX_INTEGER SEMAPHORE_VALUE_TYPE;

typedef struct {
	SEMAPHORE_VALUE_TYPE CURRENT_VALUE;
	SEMAPHORE_VALUE_TYPE MAXIMUM_VALUE;
	WAITING_RANGE_TYPE WAITING_PROCESSES;
} SEMAPHORE_STATUS_TYPE;

void CREATE_SEMAPHORE (
 /*in */ SEMAPHORE_NAME_TYPE,
 /*in */ SEMAPHORE_VALUE_TYPE,
 /*in */ SEMAPHORE_VALUE_TYPE,
 /*in */ QUEUING_DISCIPLINE_TYPE,
 /*out*/ SEMAPHORE_ID_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void WAIT_SEMAPHORE (
 /*in */ SEMAPHORE_ID_TYPE,
 /*in */ SYSTEM_TIME_TYPE,
 /*out*/ RETURN_CODE_TYPE *);

void SIGNAL_SEMAPHORE (
 /*in */ SEMAPHORE_ID_TYPE,
 /*out*/ RETURN_CODE_TYPE *);

void GET_SEMAPHORE_ID (
 /*in */ SEMAPHORE_NAME_TYPE,
 /*out*/ SEMAPHORE_ID_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void GET_SEMAPHORE_STATUS (
 /*in */ SEMAPHORE_ID_TYPE,
 /*out*/ SEMAPHORE_STATUS_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

#ifdef __cplusplus
}
#endif

#endif /* APEX_SEMAPHORE_H_ */
