/*
 * memory_block.h
 *
 *  Created on: Jan 27, 2022
 *      Author: hakan.keskin
 */

#ifndef APEX_MEMORY_BLOCK_H_
#define APEX_MEMORY_BLOCK_H_

/*----------------------------------------------------------------------*/
/* 																		*/
/* Memory Block constant and type definitions and management services 	*/
/* 																		*/
/*----------------------------------------------------------------------*/

#include "types.h"


#ifdef __cplusplus
extern "C" {
#endif

typedef NAME_TYPE MEMORY_BLOCK_NAME_TYPE;

typedef enum {READ = 0, READ_WRITE=1} MEMORY_BLOCK_MODE_TYPE;

typedef APEX_INTEGER MEMORY_BLOCK_SIZE_TYPE;

typedef APEX_BYTE * MEMORY_BLOCK_ADDR_TYPE;

typedef struct MEMORY_BLOCK_STATUS_TYPE {
	MEMORY_BLOCK_ADDR_TYPE MEMORY_BLOCK_ADDR;
	MEMORY_BLOCK_MODE_TYPE MEMORY_BLOCK_MODE;
	MEMORY_BLOCK_SIZE_TYPE MEMORY_BLOCK_SIZE; /* Number of bytes */
} MEMORY_BLOCK_STATUS_TYPE;

void GET_MEMORY_BLOCK_STATUS (
 /* in */ MEMORY_BLOCK_NAME_TYPE,
 /* out */ MEMORY_BLOCK_STATUS_TYPE *,
 /* out */ RETURN_CODE_TYPE *);

#ifdef __cplusplus
}
#endif

#endif /* APEX_MEMORY_BLOCK_H_ */
