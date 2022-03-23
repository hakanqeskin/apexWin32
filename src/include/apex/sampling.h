/*
 * sampling.h
 *
 *  Created on: Jan 27, 2022
 *      Author: hakan.keskin
 */

#ifndef APEX_SAMPLING_H_
#define APEX_SAMPLING_H_

/*----------------------------------------------------------------------*/
/* 																		*/
/* SAMPLING PORT constant and type definitions and management services	*/
/* 																		*/
/*----------------------------------------------------------------------*/

#include "types.h"


#define MAX_NUMBER_OF_SAMPLING_PORTS SYSTEM_LIMIT_NUMBER_OF_SAMPLING_PORTS

#ifdef __cplusplus
extern "C" {
#endif

typedef NAME_TYPE SAMPLING_PORT_NAME_TYPE;

typedef APEX_INTEGER SAMPLING_PORT_ID_TYPE;

typedef enum { INVALID = 0, VALID = 1 } VALIDITY_TYPE;

void CREATE_SAMPLING_PORT (
 /*in */ SAMPLING_PORT_NAME_TYPE,
 /*in */ MESSAGE_SIZE_TYPE,
 /*in */ PORT_DIRECTION_TYPE,
 /*in */ SYSTEM_TIME_TYPE,
 /*out*/ SAMPLING_PORT_ID_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void WRITE_SAMPLING_MESSAGE (
 /*in */ SAMPLING_PORT_ID_TYPE,
 /*in */ MESSAGE_ADDR_TYPE, /* by reference */
 /*in */ MESSAGE_SIZE_TYPE,
 /*out*/ RETURN_CODE_TYPE *);

void READ_SAMPLING_MESSAGE (
 /*in */ SAMPLING_PORT_ID_TYPE,
 /*out*/ MESSAGE_ADDR_TYPE,
 /*out*/ MESSAGE_SIZE_TYPE *,
 /*out*/ VALIDITY_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

#ifdef __cplusplus
}
#endif

#endif /* APEX_SAMPLING_H_ */
