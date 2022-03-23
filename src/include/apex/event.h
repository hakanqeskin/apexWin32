/*
 * event.h
 *
 *  Created on: Jan 27, 2022
 *      Author: hakan.keskin
 */

#ifndef APEX_EVENT_H_
#define APEX_EVENT_H_

/*--------------------------------------------------------------*/
/* 																*/
/* EVENT constant and type definitions and management services 	*/
/* 																*/
/*--------------------------------------------------------------*/

#include "types.h"

#define MAX_NUMBER_OF_EVENTS SYSTEM_LIMIT_NUMBER_OF_EVENTS

#ifdef __cplusplus
extern "C" {
#endif

typedef NAME_TYPE EVENT_NAME_TYPE;

typedef APEX_INTEGER EVENT_ID_TYPE;

typedef enum { DOWN = 0, UP = 1 } EVENT_STATE_TYPE;

typedef struct {
	EVENT_STATE_TYPE EVENT_STATE;
	WAITING_RANGE_TYPE WAITING_PROCESSES;
} EVENT_STATUS_TYPE;

void CREATE_EVENT (
 /*in */ EVENT_NAME_TYPE,
 /*out*/ EVENT_ID_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void SET_EVENT (
 /*in */ EVENT_ID_TYPE,
 /*out*/ RETURN_CODE_TYPE *);

void RESET_EVENT (
 /*in */ EVENT_ID_TYPE,
 /*out*/ RETURN_CODE_TYPE *);

void WAIT_EVENT (
 /*in */ EVENT_ID_TYPE,
 /*in */ SYSTEM_TIME_TYPE,
 /*out*/ RETURN_CODE_TYPE *);

void GET_EVENT_ID (
 /*in */ EVENT_NAME_TYPE,
 /*out*/ EVENT_ID_TYPE*,
 /*out*/ RETURN_CODE_TYPE*);

void GET_EVENT_STATUS (
 /*in */ EVENT_ID_TYPE,
 /*out*/ EVENT_STATUS_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

#ifdef __cplusplus
}
#endif

#endif /* APEX_EVENT_H_ */
