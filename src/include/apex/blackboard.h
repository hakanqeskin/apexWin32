/*
 * blackboard.h
 *
 *  Created on: Jan 27, 2022
 *      Author: hakan.keskin
 */

#ifndef APEX_BLACKBOARD_H_
#define APEX_BLACKBOARD_H_

/*------------------------------------------------------------------*/
/* 																	*/
/* BLACKBOARD constant and type definitions and management services */
/* 																	*/
/*------------------------------------------------------------------*/

#include "types.h"


#define MAX_NUMBER_OF_BLACKBOARDS SYSTEM_LIMIT_NUMBER_OF_BLACKBOARDS

#ifdef __cplusplus
extern "C" {
#endif

typedef NAME_TYPE BLACKBOARD_NAME_TYPE;

typedef APEX_INTEGER BLACKBOARD_ID_TYPE;

typedef enum { EMPTY = 0, OCCUPIED = 1 } EMPTY_INDICATOR_TYPE;

typedef struct {
	EMPTY_INDICATOR_TYPE EMPTY_INDICATOR;
	MESSAGE_SIZE_TYPE MAX_MESSAGE_SIZE;
	WAITING_RANGE_TYPE WAITING_PROCESSES;
} BLACKBOARD_STATUS_TYPE;

void CREATE_BLACKBOARD (
 /*in */ BLACKBOARD_NAME_TYPE,
 /*in */ MESSAGE_SIZE_TYPE,
 /*out*/ BLACKBOARD_ID_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void DISPLAY_BLACKBOARD (
 /*in */ BLACKBOARD_ID_TYPE,
 /*in */ MESSAGE_ADDR_TYPE, /* by reference */
 /*in */ MESSAGE_SIZE_TYPE,
 /*out*/ RETURN_CODE_TYPE *);

void READ_BLACKBOARD (
 /*in */ BLACKBOARD_ID_TYPE,
 /*in */ SYSTEM_TIME_TYPE,
 /*out*/ MESSAGE_ADDR_TYPE,
 /*out*/ MESSAGE_SIZE_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void CLEAR_BLACKBOARD (
 /*in */ BLACKBOARD_ID_TYPE,
 /*out*/ RETURN_CODE_TYPE*);

void GET_BLACKBOARD_ID (
 /*in */ BLACKBOARD_NAME_TYPE,
 /*out*/ BLACKBOARD_ID_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void GET_BLACKBOARD_STATUS (
 /*in */ BLACKBOARD_ID_TYPE,
 /*out*/ BLACKBOARD_STATUS_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

#ifdef __cplusplus
}
#endif

#endif /* APEX_BLACKBOARD_H_ */
