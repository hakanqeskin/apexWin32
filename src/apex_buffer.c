/*
 * buffer.c
 *
 *  Created on: Jan 27, 2022
 *      Author: hakan.keskin
 */

#include "include/apex/buffer.h"

void CREATE_BUFFER(BUFFER_NAME_TYPE BUFFER_NAME,
		MESSAGE_SIZE_TYPE MAX_MESSAGE_SIZE,
		MESSAGE_RANGE_TYPE MAX_NB_MESSAGE,
		QUEUING_DISCIPLINE_TYPE QUEUING_DISCIPLINE,
		BUFFER_ID_TYPE *BUFFER_ID,
		RETURN_CODE_TYPE *RETURN_CODE )
{
	*RETURN_CODE = NOT_AVAILABLE;
}

void SEND_BUFFER (BUFFER_ID_TYPE BUFFER_ID,
		MESSAGE_ADDR_TYPE MESSAGE_ADDR,
		MESSAGE_SIZE_TYPE LENGTH,
		SYSTEM_TIME_TYPE TIME_OUT,
		RETURN_CODE_TYPE *RETURN_CODE )
{
	*RETURN_CODE = NOT_AVAILABLE;
}

void RECEIVE_BUFFER (BUFFER_ID_TYPE BUFFER_ID,
		SYSTEM_TIME_TYPE TIME_OUT,
		MESSAGE_ADDR_TYPE MESSAGE_ADDR,
		MESSAGE_SIZE_TYPE *LENGTH,
		RETURN_CODE_TYPE *RETURN_CODE )
{
	*RETURN_CODE = NOT_AVAILABLE;
}

void GET_BUFFER_ID (BUFFER_NAME_TYPE BUFFER_NAME,
		BUFFER_ID_TYPE *BUFFER_ID,
		RETURN_CODE_TYPE *RETURN_CODE )
{
	*RETURN_CODE = NOT_AVAILABLE;
}

void GET_BUFFER_STATUS (BUFFER_ID_TYPE BUFFER_ID,
		BUFFER_STATUS_TYPE *BUFFER_STATUS,
		RETURN_CODE_TYPE *RETURN_CODE )
{
	*RETURN_CODE = NOT_AVAILABLE;
}
