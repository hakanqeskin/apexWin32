/*
 * module_schedules.h
 *
 *  Created on: Jan 27, 2022
 *      Author: hakan.keskin
 */

#ifndef APEX_MODULE_SCHEDULES_H_
#define APEX_MODULE_SCHEDULES_H_

/*----------------------------------------------------------*/
/* 															*/
/* Multiple Module Schedules constant and type definitions 	*/
/* and management services 									*/
/* 															*/
/*----------------------------------------------------------*/

#include "types.h"


#ifdef __cplusplus
extern "C" {
#endif

typedef APEX_INTEGER SCHEDULE_ID_TYPE;

typedef NAME_TYPE SCHEDULE_NAME_TYPE;

typedef struct {
	SYSTEM_TIME_TYPE TIME_OF_LAST_SCHEDULE_SWITCH;
	SCHEDULE_ID_TYPE CURRENT_SCHEDULE;
	SCHEDULE_ID_TYPE NEXT_SCHEDULE;
} SCHEDULE_STATUS_TYPE;

void SET_MODULE_SCHEDULE (
 /*in */ SCHEDULE_ID_TYPE,
 /*out*/ RETURN_CODE_TYPE *);

void GET_MODULE_SCHEDULE_STATUS (
 /*out*/ SCHEDULE_STATUS_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void GET_MODULE_SCHEDULE_ID (
 /*in */ SCHEDULE_NAME_TYPE,
 /*out*/ SCHEDULE_ID_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

#ifdef __cplusplus
}
#endif

#endif /* APEX_MODULE_SCHEDULES_H_ */
