/*
 * qp_list.h
 *
 *  Created on: Jan 27, 2022
 *      Author: hakan.keskin
 */

#ifndef APEX_QP_LIST_H_
#define APEX_QP_LIST_H_

/*--------------------------------------------------------------------------*/
/* 																			*/
/* Queuing Port List constants, type definitions and management services	*/
/* 																			*/
/*--------------------------------------------------------------------------*/

#include "types.h"


#ifdef __cplusplus
extern "C" {
#endif

/* Types */
typedef enum {INACTIVE, ACTIVE} PORT_ACTION_TYPE;

typedef enum {RESET, CONTINUE} RESET_LIST_TYPE;

typedef APEX_INTEGER LIST_SIZE_TYPE;

typedef APEX_INTEGER QUEUING_PORT_LIST_ID_TYPE;

typedef NAME_TYPE QUEUING_PORT_LIST_NAME_TYPE;

#ifndef QUEUING_PORT_ID_TYPE
typedef APEX_INTEGER QUEUING_PORT_ID_TYPE;
#endif

/* Services */
void CREATE_QUEUING_PORT_LIST (
 /*in */ QUEUING_PORT_LIST_NAME_TYPE,
 /*in */ LIST_SIZE_TYPE,
 /*out*/ QUEUING_PORT_LIST_ID_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void ADD_PORT_TO_QUEUING_PORT_LIST (
 /*in */ QUEUING_PORT_LIST_ID_TYPE,
 /*in */ QUEUING_PORT_ID_TYPE,
 /*in */ PORT_ACTION_TYPE,
 /*out*/ RETURN_CODE_TYPE *);

void SET_PORT_ACTION_IN_QUEUING_PORT_LIST (
 /*in */ QUEUING_PORT_LIST_ID_TYPE,
 /*in */ QUEUING_PORT_ID_TYPE,
 /*in */ PORT_ACTION_TYPE,
 /*out*/ RETURN_CODE_TYPE *);

void GET_QUEUING_PORT_ACTION_STATUS (
 /*in */ QUEUING_PORT_LIST_ID_TYPE,
 /*in */ QUEUING_PORT_ID_TYPE,
 /*out*/ PORT_ACTION_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void RECEIVE_MESSAGE_FROM_QUEUING_PORT_LIST (
 /*in */ QUEUING_PORT_LIST_ID_TYPE,
 /*in */ SYSTEM_TIME_TYPE,
 /*in */ MESSAGE_ADDR_TYPE,
 /*in */ MESSAGE_SIZE_TYPE,
 /*in */ RESET_LIST_TYPE,
 /*out*/ QUEUING_PORT_ID_TYPE *,
 /*out*/ MESSAGE_SIZE_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void WAIT_FOR_MESSAGE_FROM_QUEUING_PORT_LIST (
 /*in */ QUEUING_PORT_LIST_ID_TYPE,
 /*in */ SYSTEM_TIME_TYPE,
 /*in */ RESET_LIST_TYPE,
 /*out*/ QUEUING_PORT_ID_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

#ifdef __cplusplus
}
#endif

#endif /* APEX_QP_LIST_H_ */
