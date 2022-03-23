/*
 * partition.h
 *
 *  Created on: Jan 27, 2022
 *      Author: hakan.keskin
 */

#ifndef APEX_PARTITION_H_
#define APEX_PARTITION_H_

/*------------------------------------------------------------------*/
/* 																	*/
/* PARTITION constant and type definitions and management services  */
/* 																	*/
/*------------------------------------------------------------------*/

#include "types.h"


#define MAX_NUMBER_OF_PARTITIONS SYSTEM_LIMIT_NUMBER_OF_PARTITIONS

#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
	IDLE = 0,
	COLD_START = 1,
	WARM_START = 2,
	NORMAL = 3
} OPERATING_MODE_TYPE;

typedef APEX_INTEGER PARTITION_ID_TYPE;

typedef enum {
	NORMAL_START = 0,
	PARTITION_RESTART = 1,
	HM_MODULE_RESTART = 2,
	HM_PARTITION_RESTART = 3
} START_CONDITION_TYPE;

#ifndef LOCK_LEVEL_TYPE
typedef APEX_INTEGER LOCK_LEVEL_TYPE;
#endif

typedef struct {
	SYSTEM_TIME_TYPE PERIOD;
	SYSTEM_TIME_TYPE DURATION;
	PARTITION_ID_TYPE IDENTIFIER;
	LOCK_LEVEL_TYPE LOCK_LEVEL;/* Not used. Always set to zero */
	OPERATING_MODE_TYPE OPERATING_MODE;
	START_CONDITION_TYPE START_CONDITION;
} PARTITION_STATUS_TYPE;

void GET_PARTITION_STATUS (
 /*out*/ PARTITION_STATUS_TYPE *,
 /*out*/ RETURN_CODE_TYPE *);

void SET_PARTITION_MODE (
 /*in */ OPERATING_MODE_TYPE ,
 /*out*/ RETURN_CODE_TYPE *);

#ifdef __cplusplus
}
#endif

#endif /* APEX_PARTITION_H_ */
