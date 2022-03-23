/*
 * buffer.h
 *
 *  Created on: Jan 27, 2022
 *      Author: hakan.keskin
 */

#ifndef APEX_BUFFER_H_
#define APEX_BUFFER_H_

/*--------------------------------------------------------------*/
/* 																*/
/* BUFFER constant and type definitions and management services */
/* 																*/
/*--------------------------------------------------------------*/

#include "types.h"


#define MAX_NUMBER_OF_BUFFERS SYSTEM_LIMIT_NUMBER_OF_BUFFERS

#ifdef __cplusplus
extern "C" {
#endif

typedef NAME_TYPE BUFFER_NAME_TYPE;

typedef APEX_INTEGER BUFFER_ID_TYPE;

typedef struct {
	MESSAGE_RANGE_TYPE NB_MESSAGE;
	MESSAGE_RANGE_TYPE MAX_NB_MESSAGE;
	MESSAGE_SIZE_TYPE MAX_MESSAGE_SIZE;
	WAITING_RANGE_TYPE WAITING_PROCESSES;
} BUFFER_STATUS_TYPE;

void CREATE_BUFFER (
 /*in */ BUFFER_NAME_TYPE,
 /*in */ MESSAGE_SIZE_TYPE,
 /*in */ MESSAGE_RANGE_TYPE,
 /*in */ QUEUING_DISCIPLINE_TYPE,
 /*out*/ BUFFER_ID_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void SEND_BUFFER (
 /*in */ BUFFER_ID_TYPE,
 /*in */ MESSAGE_ADDR_TYPE, /* by reference */
 /*in */ MESSAGE_SIZE_TYPE,
 /*in */ SYSTEM_TIME_TYPE,
 /*out*/ RETURN_CODE_TYPE *);

void RECEIVE_BUFFER (
 /*in */ BUFFER_ID_TYPE,
 /*in */ SYSTEM_TIME_TYPE,
 /*out*/ MESSAGE_ADDR_TYPE,
 /*out*/ MESSAGE_SIZE_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void GET_BUFFER_ID (
 /*in */ BUFFER_NAME_TYPE,
 /*out*/ BUFFER_ID_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void GET_BUFFER_STATUS (
 /*in */ BUFFER_ID_TYPE,
 /*out*/ BUFFER_STATUS_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

#ifdef __cplusplus
}
#endif

#endif /* APEX_BUFFER_H_ */
