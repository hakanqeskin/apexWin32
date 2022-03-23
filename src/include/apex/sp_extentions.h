/*
 * sp_extentions.h
 *
 *  Created on: Jan 27, 2022
 *      Author: hakan.keskin
 */

#ifndef APEX_SP_EXTENTIONS_H_
#define APEX_SP_EXTENTIONS_H_

/*--------------------------------------------------------------*/
/* 																*/
/* Sampling Port Extensions constant and type definitions and 	*/
/* management services 											*/
/* 																*/
/*--------------------------------------------------------------*/

#include "types.h"


#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	EMPTY_PORT = 0,
	CONSUMED_MESSAGE = 1,
	NEW_MESSAGE = 2
} UPDATED_TYPE;

typedef enum { STALE = 0, FRESH = 1 } AGE_TYPE;

typedef struct {
	SYSTEM_TIME_TYPE REFRESH_PERIOD;
	SYSTEM_TIME_TYPE TIME_STAMP;
	MESSAGE_SIZE_TYPE MAX_MESSAGE_SIZE;
	PORT_DIRECTION_TYPE PORT_DIRECTION;
	AGE_TYPE MESSAGE_AGE;
	UPDATED_TYPE UPDATED;
} SAMPLING_PORT_CURRENT_STATUS_TYPE;

#ifndef SAMPLING_PORT_ID_TYPE
typedef APEX_INTEGER SAMPLING_PORT_ID_TYPE;
#endif

void READ_UPDATED_SAMPLING_MESSAGE (
 /*in */ SAMPLING_PORT_ID_TYPE,
 /*in */ MESSAGE_ADDR_TYPE,
 /*out*/ MESSAGE_SIZE_TYPE *,
 /*out*/ UPDATED_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void GET_SAMPLING_PORT_CURRENT_STATUS (
 /*in */ SAMPLING_PORT_ID_TYPE,
 /*out*/ SAMPLING_PORT_CURRENT_STATUS_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void READ_SAMPLING_MESSAGE_CONDITIONAL (
 /*in */ SAMPLING_PORT_ID_TYPE,
 /*in */ SYSTEM_TIME_TYPE,
 /*in */ MESSAGE_ADDR_TYPE,
 /*out*/ MESSAGE_SIZE_TYPE *,
 /*out*/ SYSTEM_TIME_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

#ifdef __cplusplus
}
#endif

#endif /* APEX_SP_EXTENTIONS_H_ */
