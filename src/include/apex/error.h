/*
 * error.h
 *
 *  Created on: Jan 27, 2022
 *      Author: hakan.keskin
 */

#ifndef APEX_ERROR_H_
#define APEX_ERROR_H_

/*--------------------------------------------------------------*/
/* 																*/
/* ERROR constant and type definitions and management services  */
/* 																*/
/*--------------------------------------------------------------*/

#include "types.h"

#define MAX_ERROR_MESSAGE_SIZE 128

#ifdef __cplusplus
extern "C" {
#endif

typedef APEX_INTEGER ERROR_MESSAGE_SIZE_TYPE;

typedef APEX_BYTE ERROR_MESSAGE_TYPE[MAX_ERROR_MESSAGE_SIZE];

#ifndef PROCESS_ID_TYPE
typedef APEX_INTEGER PROCESS_ID_TYPE;
#endif

#ifndef STACK_SIZE_TYPE
typedef APEX_UNSIGNED STACK_SIZE_TYPE;
#endif

typedef enum {
	DEADLINE_MISSED = 0,
	APPLICATION_ERROR = 1,
	NUMERIC_ERROR = 2,
	ILLEGAL_REQUEST = 3,
	STACK_OVERFLOW = 4,
	MEMORY_VIOLATION = 5,
	HARDWARE_FAULT = 6,
	POWER_FAIL = 7
} ERROR_CODE_TYPE;

typedef struct {
	ERROR_CODE_TYPE ERROR_CODE;
	ERROR_MESSAGE_SIZE_TYPE LENGTH;
	PROCESS_ID_TYPE FAILED_PROCESS_ID;
	SYSTEM_ADDRESS_TYPE FAILED_ADDRESS;
	ERROR_MESSAGE_TYPE MESSAGE;
} ERROR_STATUS_TYPE;

void REPORT_APPLICATION_MESSAGE (
 /*in */ MESSAGE_ADDR_TYPE,
 /*in */ MESSAGE_SIZE_TYPE,
 /*out*/ RETURN_CODE_TYPE *);

void CREATE_ERROR_HANDLER (
 /*in */ SYSTEM_ADDRESS_TYPE,
 /*in */ STACK_SIZE_TYPE,
 /*out*/ RETURN_CODE_TYPE *);

void GET_ERROR_STATUS (
 /*out*/ ERROR_STATUS_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void RAISE_APPLICATION_ERROR (
 /*in */ ERROR_CODE_TYPE,
 /*in */ MESSAGE_ADDR_TYPE,
 /*in */ ERROR_MESSAGE_SIZE_TYPE,
 /*out*/ RETURN_CODE_TYPE *);

#ifdef __cplusplus
}
#endif

#endif /* APEX_ERROR_H_ */
