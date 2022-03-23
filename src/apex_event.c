/*
 * event.c
 *
 *  Created on: Jan 27, 2022
 *      Author: hakan.keskin
 */

#include "include/apex/event.h"

void CREATE_EVENT (EVENT_NAME_TYPE EVENT_NAME,
		EVENT_ID_TYPE *EVENT_ID,
		RETURN_CODE_TYPE *RETURN_CODE )
{
	*RETURN_CODE = NOT_AVAILABLE;
}

void SET_EVENT (EVENT_ID_TYPE EVENT_ID,
		RETURN_CODE_TYPE *RETURN_CODE )
{
	*RETURN_CODE = NOT_AVAILABLE;
}

void RESET_EVENT (EVENT_ID_TYPE EVENT_ID,
		RETURN_CODE_TYPE *RETURN_CODE )
{
	*RETURN_CODE = NOT_AVAILABLE;
}

void WAIT_EVENT (EVENT_ID_TYPE EVENT_ID,
		SYSTEM_TIME_TYPE TIME_OUT,
		RETURN_CODE_TYPE *RETURN_CODE )
{
	*RETURN_CODE = NOT_AVAILABLE;
}

void GET_EVENT_ID (EVENT_NAME_TYPE EVENT_NAME,
		EVENT_ID_TYPE *EVENT_ID,
		RETURN_CODE_TYPE *RETURN_CODE )
{
	*RETURN_CODE = NOT_AVAILABLE;
}

void GET_EVENT_STATUS (EVENT_ID_TYPE EVENT_ID,
		EVENT_STATUS_TYPE *EVENT_STATUS,
		RETURN_CODE_TYPE *RETURN_CODE )
{
	*RETURN_CODE = NOT_AVAILABLE;
}
