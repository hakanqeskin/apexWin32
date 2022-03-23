/*
 * name_sarvice.h
 *
 *  Created on: Jan 27, 2022
 *      Author: hakan.keskin
 */

#ifndef APEX_NAME_SARVICE_H_
#define APEX_NAME_SARVICE_H_

/*----------------------------------------------------------------------*/
/* 																		*/
/* Name Service constant and type definitions and management services 	*/
/* 																		*/
/*----------------------------------------------------------------------*/

#include "sap_ports.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef APEX_INTEGER NAME_SERVICE_ID_TYPE;

typedef NAME_TYPE NAME_SERVICE_NAME_TYPE;

typedef APEX_BYTE * NAME_SERVICE_ADDR_TYPE;

typedef APEX_INTEGER NAME_SERVICE_LENGTH_TYPE;

void CREATE_NAME_SERVICE (
 /*in */ NAME_SERVICE_NAME_TYPE,
 /*in */ QUEUING_DISCIPLINE_TYPE,
 /*out*/ NAME_SERVICE_ID_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void GET_NAME (
 /*in */ NAME_SERVICE_ID_TYPE,
 /*in */ SAP_ADDRESS_TYPE,
 /*in */ SYSTEM_TIME_TYPE,
 /*in */ NAME_SERVICE_ADDR_TYPE, /* by reference */
 /*in */ NAME_SERVICE_LENGTH_TYPE,
 /*out*/ NAME_SERVICE_LENGTH_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void GET_ADDRESS (
 /*in */ NAME_SERVICE_ID_TYPE,
 /*in */ NAME_SERVICE_ADDR_TYPE,
 /*in */ NAME_SERVICE_LENGTH_TYPE *,
 /*in */ SYSTEM_TIME_TYPE,
 /*out*/ SAP_ADDRESS_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

#ifdef __cplusplus
}
#endif

#endif /* APEX_NAME_SARVICE_H_ */
