/*
 * sap_ports.h
 *
 *  Created on: Jan 27, 2022
 *      Author: hakan.keskin
 */

#ifndef APEX_SAP_PORTS_H_
#define APEX_SAP_PORTS_H_

/*------------------------------------------------------------------*/
/* 																	*/
/* SAP Ports constant and type definitions and management services 	*/
/* 																	*/
/*------------------------------------------------------------------*/

#include "types.h"


#define MAX_NUMBER_OF_SAP_PORTS 1024 /* Implementation dependent */

#define SAP_ADDR_TYPE_UNKNOWN 0 /* unknown address type */
#define SAP_ADDR_TYPE_INET 1 /* type is IP address type */

#ifdef __cplusplus
extern "C" {
#endif

/* Partition scope */
typedef NAME_TYPE SAP_PORT_NAME_TYPE;

typedef APEX_INTEGER SAP_PORT_ID_TYPE;

#ifndef APEX_UNSIGNED_SHORT
/* Implementation dependent*/
typedef unsigned short int APEX_UNSIGNED_SHORT;/* 16-bit unsigned integer */
#endif

typedef struct SAP_ADDRESS_TYPE {
	APEX_BYTE Addr_Length; /* structure size */
	APEX_BYTE Addr_Type; /* address type */
	APEX_UNSIGNED_SHORT UDP_Port_Number; /* src/dst UDP port number */
	APEX_UNSIGNED IP_Address; /* src/dst IP address */
	APEX_BYTE Addr_Spare[8]; /* structure padding */
} SAP_ADDRESS_TYPE;

/* structure returned by SAP port status query */
typedef struct SAP_PORT_STATUS_TYPE {
	MESSAGE_RANGE_TYPE NB_MESSAGE;
	MESSAGE_RANGE_TYPE MAX_NB_MESSAGE;
	MESSAGE_SIZE_TYPE MAX_MESSAGE_SIZE;
	PORT_DIRECTION_TYPE PORT_DIRECTION;
	WAITING_RANGE_TYPE WAITING_PROCESSES;
	SAP_ADDRESS_TYPE CURRENT_DEST_ADDR;
	SAP_ADDRESS_TYPE CURRENT_SRC_ADDR;
} SAP_PORT_STATUS_TYPE;

void CREATE_SAP_PORT (
 /*in */ SAP_PORT_NAME_TYPE,
 /*in */ MESSAGE_SIZE_TYPE,
 /*in */ MESSAGE_RANGE_TYPE,
 /*in */ PORT_DIRECTION_TYPE,
 /*in */ QUEUING_DISCIPLINE_TYPE,
 /*out*/ SAP_PORT_ID_TYPE *,
 /*out*/ RETURN_CODE_TYPE * );

void SEND_SAP_MESSAGE (
 /*in */ SAP_PORT_ID_TYPE,
 /*in */ MESSAGE_ADDR_TYPE, /* by reference */
 /*in */ MESSAGE_SIZE_TYPE,
 /*in */ SYSTEM_TIME_TYPE,
 /*in */ SAP_ADDRESS_TYPE,
 /*out*/ RETURN_CODE_TYPE *);

void RECEIVE_SAP_MESSAGE (
 /*in */ SAP_PORT_ID_TYPE,
 /*in */ SYSTEM_TIME_TYPE,
 /*out*/ MESSAGE_ADDR_TYPE,
 /*out*/ MESSAGE_SIZE_TYPE *,
 /*out*/ SAP_ADDRESS_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void GET_SAP_PORT_ID (
 /*in */ SAP_PORT_NAME_TYPE,
 /*out*/ SAP_PORT_ID_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void GET_SAP_PORT_STATUS (
 /*in */ SAP_PORT_ID_TYPE,
 /*in */ SAP_PORT_STATUS_TYPE *,
 /*in */ RETURN_CODE_TYPE *);

void SEND_EXTENDED_SAP_MESSAGE(
 /*in */ SAP_PORT_ID_TYPE,
 /*in */ MESSAGE_ADDR_TYPE, /* by reference */
 /*in */ MESSAGE_SIZE_TYPE,
 /*in */ SYSTEM_TIME_TYPE,
 /*in */ SAP_ADDRESS_TYPE,
 /*in */ SAP_ADDRESS_TYPE,
 /*out*/ RETURN_CODE_TYPE *);

void RECEIVE_EXTENDED_SAP_MESSAGE(
 /*in */ SAP_PORT_ID_TYPE,
 /*in */ SYSTEM_TIME_TYPE,
 /*out*/ MESSAGE_ADDR_TYPE,
 /*out*/ MESSAGE_SIZE_TYPE *,
 /*out*/ SAP_ADDRESS_TYPE *,
 /*out*/ SAP_ADDRESS_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

#ifdef __cplusplus
}
#endif

#endif /* APEX_SAP_PORTS_H_ */
