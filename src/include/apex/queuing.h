/*
 * queuing.h
 *
 *  Created on: Jan 27, 2022
 *      Author: hakan.keskin
 */

#ifndef APEX_QUEUING_H_
#define APEX_QUEUING_H_

/*--------------------------------------------------------------------*/
/* 																	  */
/* QUEUING PORT constant and type definitions and management services */
/* 																	  */
/*--------------------------------------------------------------------*/

#include "types.h"


#define MAX_NUMBER_OF_QUEUING_PORTS SYSTEM_LIMIT_NUMBER_OF_QUEUING_PORTS

#ifdef __cplusplus
extern "C" {
#endif

typedef NAME_TYPE QUEUING_PORT_NAME_TYPE;

typedef APEX_INTEGER QUEUING_PORT_ID_TYPE;

typedef struct {
	MESSAGE_RANGE_TYPE NB_MESSAGE;
	MESSAGE_RANGE_TYPE MAX_NB_MESSAGE;
	MESSAGE_SIZE_TYPE MAX_MESSAGE_SIZE;
	PORT_DIRECTION_TYPE PORT_DIRECTION;
	WAITING_RANGE_TYPE WAITING_PROCESSES;
} QUEUING_PORT_STATUS_TYPE;

void CREATE_QUEUING_PORT (
 /*in */ QUEUING_PORT_NAME_TYPE,
 /*in */ MESSAGE_SIZE_TYPE,
 /*in */ MESSAGE_RANGE_TYPE,
 /*in */ PORT_DIRECTION_TYPE,
 /*in */ QUEUING_DISCIPLINE_TYPE,
 /*out*/ QUEUING_PORT_ID_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void SEND_QUEUING_MESSAGE (
 /*in */ QUEUING_PORT_ID_TYPE,
 /*in */ MESSAGE_ADDR_TYPE, /* by reference */
 /*in */ MESSAGE_SIZE_TYPE,
 /*in */ SYSTEM_TIME_TYPE,
 /*out*/ RETURN_CODE_TYPE *);

void RECEIVE_QUEUING_MESSAGE (
 /*in */ QUEUING_PORT_ID_TYPE,
 /*in */ SYSTEM_TIME_TYPE,
 /*out*/ MESSAGE_ADDR_TYPE,
 /*out*/ MESSAGE_SIZE_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void GET_QUEUING_PORT_STATUS (
 /*in */ QUEUING_PORT_ID_TYPE,
 /*out*/ QUEUING_PORT_STATUS_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void CLEAR_QUEUING_PORT (
 /*in */ QUEUING_PORT_ID_TYPE,
 /*out*/ RETURN_CODE_TYPE *);

#ifdef __cplusplus
}
#endif

#endif /* APEX_QUEUING_H_ */
