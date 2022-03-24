/*
 * types.h
 *
 *  Created on: Jan 27, 2022
 *      Author: hakan.keskin
 */

#ifndef APEX_TYPES_H_
#define APEX_TYPES_H_
/*----------------------------------------------------------------*/
/* 																  */
/* Global constant and type definitions 						  */
/* 																  */
/*----------------------------------------------------------------*/

/*--------------------------*/
/* Domain limits            */
/*--------------------------*/

/* 							Implementation Dependent 						*/
/* These values define the domain limits and are implementation dependent.  */

#define SYSTEM_LIMIT_NUMBER_OF_PARTITIONS 32 /* module scope */

#define SYSTEM_LIMIT_NUMBER_OF_MESSAGES 512 /* module scope */

#define SYSTEM_LIMIT_MESSAGE_SIZE 8192 /* module scope */

#define SYSTEM_LIMIT_NUMBER_OF_PROCESSES 2 /* partition scope */

#define SYSTEM_LIMIT_NUMBER_OF_SAMPLING_PORTS 512 /* partition scope */

#define SYSTEM_LIMIT_NUMBER_OF_QUEUING_PORTS 512 /* partition scope */

#define SYSTEM_LIMIT_NUMBER_OF_BUFFERS 256 /* partition scope */
#define SYSTEM_LIMIT_NUMBER_OF_BLACKBOARDS 256 /* partition scope */ 
#define SYSTEM_LIMIT_NUMBER_OF_SEMAPHORES 256 /* partition scope */ 
#define SYSTEM_LIMIT_NUMBER_OF_EVENTS 256 /* partition scope */
#define MAX_NAME_LENGTH	30

#define INFINITE_TIME_VALUE -1

#ifdef __cplusplus
extern "C" {
#endif

/*----------------------*/
/* Base APEX types 		*/
/*----------------------*/

/* 						Implementation Dependent 					*/
/* The actual size of these base types is system specific and the 	*/
/* sizes must match the sizes used by the implementation of the 	*/
/* underlying Operating System. 									*/

typedef char APEX_CHAR; /* 8-bit signed integer */

typedef unsigned char APEX_BYTE; /* 8-bit unsigned */

typedef short int APEX_SHORT_INTEGER; /* 16-bit signed integer */

typedef unsigned short int APEX_UNSIGNED_SHORT;/* 16-bit unsigned integer */

typedef long APEX_INTEGER; /* 32-bit signed */

typedef unsigned long APEX_UNSIGNED; /* 32-bit unsigned */

typedef long long APEX_LONG_INTEGER; /* 64-bit signed */

typedef unsigned long long APEX_UNSIGNED_LONG; /* 64-bit unsigned integer */

typedef float APEX_FLOAT; /* 32-bit float */

typedef double APEX_DOUBLE; /* 64-bit float */

/*----------------------*/
/* General APEX types   */
/*----------------------*/
typedef enum {
	NO_ERROR = 0, 			/* request valid and operation performed */
	NO_ACTION = 1, 		/* status of system unaffected by request */
	NOT_AVAILABLE = 2, 	/* resource required by request unavailable */
	INVALID_PARAM = 3, 	/* invalid parameter specified in request */
	INVALID_CONFIG = 4, 	/* parameter incompatible with configuration */
	INVALID_MODE = 5, 		/* request incompatible with current mode */
	TIMED_OUT = 6 			/* time-out tied up with request has expired */
} RETURN_CODE_TYPE;

typedef char NAME_TYPE[MAX_NAME_LENGTH];

typedef void (* SYSTEM_ADDRESS_TYPE);

typedef APEX_BYTE * MESSAGE_ADDR_TYPE;

typedef APEX_INTEGER MESSAGE_SIZE_TYPE;

typedef APEX_INTEGER MESSAGE_RANGE_TYPE;

typedef enum { SOURCE = 0, DESTINATION = 1 } PORT_DIRECTION_TYPE;

typedef enum { FIFO = 0, PRIORITY = 1 } QUEUING_DISCIPLINE_TYPE;

typedef enum { SOFT = 0, HARD = 1 } DEADLINE_TYPE;

/* 64-bit signed integer with a 1 nanosecond LSB */
typedef APEX_LONG_INTEGER SYSTEM_TIME_TYPE;

typedef APEX_INTEGER PARTITION_ID_TYPE;

typedef APEX_INTEGER PROCESS_ID_TYPE;

typedef APEX_INTEGER WAITING_RANGE_TYPE;

typedef APEX_UNSIGNED STACK_SIZE_TYPE;

#ifdef __cplusplus
}
#endif

#endif /* APEX_TYPES_H_ */
