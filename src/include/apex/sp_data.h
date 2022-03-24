/*
 * sp_data.h
 *
 *  Created on: Jan 27, 2022
 *      Author: hakan.keskin
 */

#ifndef APEX_SP_DATA_H_
#define APEX_SP_DATA_H_

/*------------------------------------------------------------------*/
/* 																	*/
/* Sampling port data structures constant and type definitions and  */
/* management services 												*/
/* 																	*/
/*------------------------------------------------------------------*/

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/*
** Sampling port data types.
**
** Note: Data types APEX_BYTE, APEX_INTEGER, APEX_UNSIGNED, and
** APEX_LONG_INTEGER, are defined in ARINC 653Part 1. They are
** considered to be acceptable for use in this context.
**
** Implementation dependent:
**
** The type declaration associated with each typdef statement may be
** implementation dependent. Each must define a type that is consistent
** with the standard definition, in size, structure, and behavior.
*/



/*
** Enumerated values.
** These use integers to mimic enumerated data
** Legal values are defined by #define statements
** (see FS value declarations)
*/
typedef APEX_CHAR APEX_ENUM8 ; /* 8-bit enumeration */

typedef APEX_SHORT_INTEGER APEX_ENUM16 ; /* 16-bit enumeration */

typedef APEX_INTEGER APEX_ENUM32 ; /* 32-bit enumeration */

typedef APEX_ENUM8 FS_TYPE ; /* Function Status */

typedef struct {
	FS_TYPE fs1 : 8;
	FS_TYPE fs2 : 8;
	FS_TYPE fs3 : 8;
	FS_TYPE fs4 : 8;
} FSS_TYPE ; /* 32 bits */

/* Function Status (FS) state definitions */
/* These values should not be modified. */
#define NO_DATA 0x00
#define NORMAL_OPERATION 0x03
#define FUNCTIONAL_TEST 0x0C
#define NO_COMPUTED_DATA 0x30


#ifdef __cplusplus
}
#endif


#endif /* APEX_SP_DATA_H_ */
