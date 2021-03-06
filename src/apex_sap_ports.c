/*
 * sap_ports.c
 *
 *  Created on: Jan 27, 2022
 *      Author: hakan.keskin
 */

#include "include/apex/sap_ports.h"

void CREATE_SAP_PORT (SAP_PORT_NAME_TYPE SAP_PORT_NAME,
		MESSAGE_SIZE_TYPE MAX_MESSAGE_SIZE,
		MESSAGE_RANGE_TYPE MAX_NB_MESSAGE,
		PORT_DIRECTION_TYPE PORT_DIRECTION,
		QUEUING_DISCIPLINE_TYPE QUEUING_DISCIPLINE,
		SAP_PORT_ID_TYPE *SAP_PORT_ID,
		RETURN_CODE_TYPE *RETURN_CODE )
{
	*RETURN_CODE = NOT_AVAILABLE;
}

void SEND_SAP_MESSAGE (SAP_PORT_ID_TYPE SAP_PORT_ID,
		MESSAGE_ADDR_TYPE MESSAGE_ADDR,
		MESSAGE_SIZE_TYPE LENGTH,
		SYSTEM_TIME_TYPE TIME_OUT,
		SAP_ADDRESS_TYPE DESTINATION_ADDR,
		RETURN_CODE_TYPE *RETURN_CODE )
{
	*RETURN_CODE = NOT_AVAILABLE;
}

void RECEIVE_SAP_MESSAGE (SAP_PORT_ID_TYPE SAP_PORT_ID,
		SYSTEM_TIME_TYPE TIME_OUT,
		MESSAGE_ADDR_TYPE MESSAGE_ADDR,
		MESSAGE_SIZE_TYPE *LENGTH,
		SAP_ADDRESS_TYPE *SOURCE_ADDR,
		RETURN_CODE_TYPE *RETURN_CODE )
{
	*RETURN_CODE = NOT_AVAILABLE;
}

void GET_SAP_PORT_ID (SAP_PORT_NAME_TYPE SAP_PORT_NAME,
		SAP_PORT_ID_TYPE *SAP_PORT_ID,
		RETURN_CODE_TYPE *RETURN_CODE)
{
	*RETURN_CODE = NOT_AVAILABLE;
}

void GET_SAP_PORT_STATUS (SAP_PORT_ID_TYPE SAP_PORT_ID,
		SAP_PORT_STATUS_TYPE *SAP_PORT_STATUS,
		RETURN_CODE_TYPE *RETURN_CODE )
{
	*RETURN_CODE = NOT_AVAILABLE;
}

void SEND_EXTENDED_SAP_MESSAGE(SAP_PORT_ID_TYPE SAP_PORT_ID,
		MESSAGE_ADDR_TYPE MESSAGE_ADDR,
		MESSAGE_SIZE_TYPE LENGTH,
		SYSTEM_TIME_TYPE TIME_OUT,
		SAP_ADDRESS_TYPE SOURCE_ADDR,
		SAP_ADDRESS_TYPE DESTINATION_ADDR,
		RETURN_CODE_TYPE *RETURN_CODE )
{
	*RETURN_CODE = NOT_AVAILABLE;
}

void RECEIVE_EXTENDED_SAP_MESSAGE(SAP_PORT_ID_TYPE SAP_PORT_ID,
		SYSTEM_TIME_TYPE TIME_OUT,
		MESSAGE_ADDR_TYPE MESSAGE_ADDR,
		MESSAGE_SIZE_TYPE *LENGTH,
		SAP_ADDRESS_TYPE *SOURCE_ADDR,
		SAP_ADDRESS_TYPE *DESTINATION_ADDR,
		RETURN_CODE_TYPE *RETURN_CODE )
{
	*RETURN_CODE = NOT_AVAILABLE;
}
