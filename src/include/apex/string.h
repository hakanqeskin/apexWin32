#ifndef APEX_STRING_H_
#define APEX_STRING_H_

#include "types.h"

/*
** String data type.
** There is not a generalized form of the APEX string type that is
** expressible as a C typedef. For a string of a given length,
** a structure should be defined similar to this example:
*/

#ifdef __cplusplus
extern "C" {
#endif

typedef APEX_UNSIGNED_SHORT APEX_WORD; /* 16-bit unsigned integer */

typedef struct {
	APEX_WORD length;
	APEX_CHAR data[MAX_NAME_LENGTH]; /* length of specific string */
} APEX_STRING;

#ifdef __cplusplus
}
#endif

#endif /*APEX_STRING_H_*/
