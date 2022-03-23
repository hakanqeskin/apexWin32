/*
 * qp_list.c
 *
 *  Created on: Jan 27, 2022
 *      Author: hakan.keskin
 */

#include "include/apex/qp_list.h"

void CREATE_QUEUING_PORT_LIST (QUEUING_PORT_LIST_NAME_TYPE QUEUING_PORT_LIST_NAME,
		LIST_SIZE_TYPE MAX_LIST_SIZE,
		QUEUING_PORT_LIST_ID_TYPE *QUEUING_PORT_LIST_ID,
		RETURN_CODE_TYPE *RETURN_CODE)
{
	*RETURN_CODE = NOT_AVAILABLE;
}

void ADD_PORT_TO_QUEUING_PORT_LIST (QUEUING_PORT_LIST_ID_TYPE QUEUING_PORT_LIST_ID,
		QUEUING_PORT_ID_TYPE QUEUING_PORT_ID,
		PORT_ACTION_TYPE PORT_ACTION,
		RETURN_CODE_TYPE *RETURN_CODE)
{
	*RETURN_CODE = NOT_AVAILABLE;
}

void SET_PORT_ACTION_IN_QUEUING_PORT_LIST (QUEUING_PORT_LIST_ID_TYPE QUEUING_PORT_LIST_ID,
		QUEUING_PORT_ID_TYPE QUEUING_PORT_ID,
		PORT_ACTION_TYPE PORT_ACTION,
		RETURN_CODE_TYPE *RETURN_CODE)
{
	*RETURN_CODE = NOT_AVAILABLE;
}

void GET_QUEUING_PORT_ACTION_STATUS (QUEUING_PORT_LIST_ID_TYPE QUEUING_PORT_LIST_ID,
		QUEUING_PORT_ID_TYPE QUEUING_PORT_ID,
		PORT_ACTION_TYPE *PORT_ACTION_STATUS,
		RETURN_CODE_TYPE *RETURN_CODE)
{
	*RETURN_CODE = NOT_AVAILABLE;
}

void RECEIVE_MESSAGE_FROM_QUEUING_PORT_LIST (QUEUING_PORT_LIST_ID_TYPE QUEUING_PORT_LIST_ID,
		SYSTEM_TIME_TYPE TIME_OUT,
		MESSAGE_ADDR_TYPE MESSAGE_ADDR,
		MESSAGE_SIZE_TYPE BUFFER_SIZE,
		RESET_LIST_TYPE RESET_LIST,
		QUEUING_PORT_ID_TYPE *QUEUING_PORT_ID,
		MESSAGE_SIZE_TYPE *LENGTH,
		RETURN_CODE_TYPE *RETURN_CODE)
{
	*RETURN_CODE = NOT_AVAILABLE;
}

void WAIT_FOR_MESSAGE_FROM_QUEUING_PORT_LIST (QUEUING_PORT_LIST_ID_TYPE QUEUING_PORT_LIST_ID,
		SYSTEM_TIME_TYPE TIME_OUT,
		RESET_LIST_TYPE RESET_LIST,
		QUEUING_PORT_ID_TYPE *QUEUING_PORT_ID,
		RETURN_CODE_TYPE *RETURN_CODE)
{
	*RETURN_CODE = NOT_AVAILABLE;
}
