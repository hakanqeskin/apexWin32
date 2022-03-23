/*
 * logbook.h
 *
 *  Created on: Jan 27, 2022
 *      Author: hakan.keskin
 */

#ifndef APEX_LOGBOOK_H_
#define APEX_LOGBOOK_H_

/*----------------------------------------------------------------------*/
/* 																		*/
/* Logbook system constant and type definitions and management services */
/* 																		*/
/*----------------------------------------------------------------------*/

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef APEX_INTEGER LOGBOOK_ID_TYPE;

typedef NAME_TYPE LOGBOOK_NAME_TYPE;

typedef enum {
	ABORTED = 0,
	IN_PROGRESS = 1,
	COMPLETE = 2
} WRITE_STATUS_TYPE;

typedef struct {
	APEX_INTEGER MAX_MESSAGE_SIZE;
	APEX_INTEGER MAX_NB_LOGGED_MESSAGES;
	APEX_INTEGER MAX_NB_IN_PROGRESS_MESSAGES;
	APEX_INTEGER NB_LOGGED_MESSAGES;
	APEX_INTEGER NB_IN_PROGRESS_MESSAGES;
	APEX_INTEGER NB_ABORTED_MESSAGES;
} LOGBOOK_STATUS_TYPE;

void CREATE_LOGBOOK (
 /*in */ LOGBOOK_NAME_TYPE,
 /*in */ MESSAGE_SIZE_TYPE,
 /*in */ MESSAGE_RANGE_TYPE,
 /*in */ MESSAGE_RANGE_TYPE,
 /*out*/ LOGBOOK_ID_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void WRITE_LOGBOOK (
 /*in */ LOGBOOK_ID_TYPE,
 /*in */ MESSAGE_ADDR_TYPE,
 /*in */ MESSAGE_SIZE_TYPE,
 /*out*/ RETURN_CODE_TYPE *);

void OVERWRITE_LOGBOOK (
 /*in */ LOGBOOK_ID_TYPE,
 /*in */ MESSAGE_ADDR_TYPE,
 /*in */ MESSAGE_SIZE_TYPE,
 /*out*/ RETURN_CODE_TYPE *);

void READ_LOGBOOK (
 /*in */ LOGBOOK_ID_TYPE,
 /*in */ MESSAGE_RANGE_TYPE,
 /*in */ MESSAGE_ADDR_TYPE,
 /*out*/ MESSAGE_SIZE_TYPE *,
 /*out*/ WRITE_STATUS_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void CLEAR_LOGBOOK (
 /*in */ LOGBOOK_ID_TYPE,
 /*out*/ RETURN_CODE_TYPE *);

void GET_LOGBOOK_ID (
 /*in */ LOGBOOK_NAME_TYPE,
 /*out*/ LOGBOOK_ID_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void GET_LOGBOOK_STATUS (
 /*in */ LOGBOOK_ID_TYPE,
 /*out*/ LOGBOOK_STATUS_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

#ifdef __cplusplus
}
#endif


#endif /* APEX_LOGBOOK_H_ */
