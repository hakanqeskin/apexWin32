/*
 * file_system.h
 *
 *  Created on: Jan 27, 2022
 *      Author: hakan.keskin
 */

#ifndef APEX_FILE_SYSTEM_H_
#define APEX_FILE_SYSTEM_H_

/*--------------------------------------------------------------*/
/* 																*/
/* Unless specified as implementation dependent, the values 	*/
/* specified in this appendix should be implemented as defined. */
/* 																*/
/*--------------------------------------------------------------*/

/*------------------------------------------------------------------*/
/* 																	*/
/* File System constant and type definitions and management services*/
/* 																	*/
/*------------------------------------------------------------------*/

#include "types.h"

/* from APEX_TYPES: 								*/
/* typedef unsigned char APEX_BYTE; 				*/
/* typedef long APEX_INTEGER; 						*/
/* typedef long long APEX_LONG_INTEGER; 			*/
/* typedef enum {NO_ERROR, ...} RETURN_CODE_TYPE; 	*/
/* typedef APEX_BYTE * MESSAGE_ADDR_TYPE; 			*/
/* typedef APEX_INTEGER MESSAGE_SIZE_TYPE; 			*/
/* typedef APEX_LONG_INTEGER SYSTEM_TIME_TYPE; 		*/

#define SYSTEM_LIMIT_FILE_SIZE 0x40000000 /* file system scope */

 /* implementation dependent */
#define MAX_FILE_SIZE SYSTEM_LIMIT_FILE_SIZE
#define MAX_FILE_NAME_LENGTH 512 /* 511 char + null */

#define MAX_DIRECTORY_ENTRY_LENGTH 64 /* 63 char + null */

/* ERRNO Error codes */
/* The values defined by the ERRNO constants are implementation dependent */
#define APEX_EPERM 1 /* Operation not permitted */
#define APEX_ENOENT 2 /* No such file or directory */
#define APEX_EIO 5 /* Input/output error */
#define APEX_EBADF 9 /* Bad file descriptor */
#define APEX_EACCES 13 /* Permission denied */

#define APEX_EBUSY 16 /* Resource busy */
#define APEX_EEXIST 17 /* File exists */
#define APEX_ENOTDIR 20 /* Not a volume or directory */
#define APEX_EISDIR 21 /* Is a directory */
#define APEX_EINVAL 22 /* Invalid argument */
#define APEX_EMFILE 24 /* Too many open files by the current partition */

#define APEX_EFBIG 27 /* File too large */
#define APEX_ENOSPC 28 /* No space left on volume */
#define APEX_EROFS 30 /* Storage device containing file is */
 /* currently write protected */
#define APEX_ENAMETOOLONG 78 /* Filename too long */
#define APEX_EOVERFLOW 79 /* Current file position beyond end of file */
#define APEX_ENOTEMPTY 93 /* Directory not empty */
#define APEX_ESTALE 151 /* file or directory ID which an application has been using
is no longer valid */

#ifdef __cplusplus
extern "C" {
#endif

typedef char FILE_NAME_TYPE [MAX_FILE_NAME_LENGTH];

typedef char DIRECTORY_ENTRY_TYPE [MAX_DIRECTORY_ENTRY_LENGTH];

typedef APEX_INTEGER FILE_ID_TYPE;

typedef APEX_INTEGER DIRECTORY_ID_TYPE;

/* 32-bit or 64-bit (APEX_LONG_INTEGER) */
typedef APEX_INTEGER FILE_SIZE_TYPE;

 /* implementation dependent */
typedef APEX_INTEGER FILE_ERRNO_TYPE;

typedef enum { READ = 0, READ_WRITE = 1 } FILE_MODE_TYPE;

typedef enum { SEEK_SET = 0, SEEK_CUR = 1, SEEK_END = 2 } FILE_SEEK_TYPE;

typedef enum {
	FILE_ENTRY = 0,
	DIRECTORY_ENTRY = 1,
	OTHER_ENTRY = 2,
	END_OF_DIRECTORY = 3
} ENTRY_KIND_TYPE;

typedef enum { UNSET = 0, SET = 1 } TIME_SET_TYPE;

typedef enum { VOLATILE = 0, NONVOLATILE = 1, REMOTE = 2} MEDIA_TYPE;

typedef struct {
	APEX_INTEGER TM_SEC; /* seconds after the minute [0,59] */
	APEX_INTEGER TM_MIN; /* minutes after the hour [0,59] */
	APEX_INTEGER TM_HOUR; /* hours since midnight [0,23] */
	APEX_INTEGER TM_MDAY; /* day of the month [1,31] */
	APEX_INTEGER TM_MON; /* months since January [0,11] */
	APEX_INTEGER TM_YEAR; /* years since 1900 */
	APEX_INTEGER TM_WDAY; /* days since Sunday [0,6] */
	APEX_INTEGER TM_YDAY; /* days since January 1 [0,365] */
	APEX_INTEGER TM_ISDST; /* Daylight Savings Time flag */
	TIME_SET_TYPE TM_IS_SET; /* time has been set */
} COMPOSITE_TIME_TYPE;

typedef struct {
	COMPOSITE_TIME_TYPE CREATE_TIME;
	COMPOSITE_TIME_TYPE LAST_UPDATE;
	FILE_SIZE_TYPE POSITION;
	FILE_SIZE_TYPE SIZE;
	APEX_INTEGER NB_OF_CHANGES;
	APEX_INTEGER NB_OF_WRITE_ERRORS;
} FILE_STATUS_TYPE;

typedef struct {
	APEX_LONG_INTEGER TOTAL_BYTES;
	APEX_LONG_INTEGER USED_BYTES;
	APEX_LONG_INTEGER FREE_BYTES;
	APEX_LONG_INTEGER MAX_ATOMIC_SIZE;
	APEX_INTEGER BLOCK_SIZE;
	FILE_MODE_TYPE ACCESS_RIGHTS;
	MEDIA_TYPE MEDIA;
} VOLUME_STATUS_TYPE;

void OPEN_NEW_FILE (
 /*in */ FILE_NAME_TYPE,
 /*out */ FILE_ID_TYPE *,
 /*out */ RETURN_CODE_TYPE *,
 /*inout*/ FILE_ERRNO_TYPE *);

void OPEN_FILE (
 /*in */ FILE_NAME_TYPE,
 /*in */ FILE_MODE_TYPE,
 /*out */ FILE_ID_TYPE *,
 /*out */ RETURN_CODE_TYPE *,
 /*inout*/ FILE_ERRNO_TYPE *);

void CLOSE_FILE (
 /*in */ FILE_ID_TYPE,
 /*out */ RETURN_CODE_TYPE *,
 /*inout*/ FILE_ERRNO_TYPE *);

void READ_FILE (
 /*in */ FILE_ID_TYPE,
 /*in */ MESSAGE_ADDR_TYPE, /* by reference */
 /*in */ MESSAGE_SIZE_TYPE,
 /*out */ MESSAGE_SIZE_TYPE *,
 /*out */ RETURN_CODE_TYPE *,
 /*inout*/ FILE_ERRNO_TYPE *);

void WRITE_FILE (
 /*in */ FILE_ID_TYPE,
 /*in */ MESSAGE_ADDR_TYPE, /* by reference */
 /*in */ MESSAGE_SIZE_TYPE,
 /*out */ RETURN_CODE_TYPE *,
 /*inout*/ FILE_ERRNO_TYPE *);

void SEEK_FILE (
 /*in */ FILE_ID_TYPE,
 /*in */ FILE_SIZE_TYPE,
 /*in */ FILE_SEEK_TYPE,
 /*out */ FILE_SIZE_TYPE *,
 /*out */ RETURN_CODE_TYPE *,
 /*inout*/ FILE_ERRNO_TYPE *);

void RESIZE_FILE (
 /*in */ FILE_ID_TYPE,
 /*in */ FILE_SIZE_TYPE,
 /*out */ RETURN_CODE_TYPE *,
 /*inout*/ FILE_ERRNO_TYPE *);

void SYNC_FILE (
 /*in */ FILE_ID_TYPE,
 /*out */ RETURN_CODE_TYPE *,
 /*inout*/ FILE_ERRNO_TYPE *);

void REMOVE_FILE (
 /*in */ FILE_NAME_TYPE,
 /*out */ RETURN_CODE_TYPE *,
 /*inout*/ FILE_ERRNO_TYPE *);

void RENAME_FILE (
 /*in */ FILE_NAME_TYPE,
 /*in */ FILE_NAME_TYPE,
 /*out */ RETURN_CODE_TYPE *,
 /*inout*/ FILE_ERRNO_TYPE *);

void GET_FILE_STATUS (
 /*in */ FILE_ID_TYPE,
 /*out */ FILE_STATUS_TYPE *,
 /*out */ RETURN_CODE_TYPE *,
 /*inout*/ FILE_ERRNO_TYPE *);

void GET_VOLUME_STATUS (
 /*in */ FILE_NAME_TYPE,
 /*out */ VOLUME_STATUS_TYPE *,
 /*out */ RETURN_CODE_TYPE *,
 /*inout*/ FILE_ERRNO_TYPE *);

void OPEN_DIRECTORY (
 /*in */ FILE_NAME_TYPE,
 /*out */ DIRECTORY_ID_TYPE *,
 /*out */ RETURN_CODE_TYPE *,
 /*inout*/ FILE_ERRNO_TYPE *);

void CLOSE_DIRECTORY (
 /*in */ DIRECTORY_ID_TYPE,
 /*out */ RETURN_CODE_TYPE *,
 /*inout*/ FILE_ERRNO_TYPE *);

void READ_DIRECTORY (
 /*in */ DIRECTORY_ID_TYPE,
 /*out */ DIRECTORY_ENTRY_TYPE *,
 /*out */ ENTRY_KIND_TYPE *,
 /*out */ RETURN_CODE_TYPE *,
 /*inout*/ FILE_ERRNO_TYPE *);

void REWIND_DIRECTORY (
 /*in */ DIRECTORY_ID_TYPE,
 /*out */ RETURN_CODE_TYPE *,
 /*inout*/ FILE_ERRNO_TYPE *);

void MAKE_DIRECTORY (
 /*in */ FILE_NAME_TYPE,
 /*out */ RETURN_CODE_TYPE *,
 /*inout*/ FILE_ERRNO_TYPE *);

void REMOVE_DIRECTORY (
 /*in */ FILE_NAME_TYPE,
 /*out */ RETURN_CODE_TYPE *,
 /*inout*/ FILE_ERRNO_TYPE *);

void SYNC_DIRECTORY (
 /*in */ DIRECTORY_ID_TYPE,
 /*out */ RETURN_CODE_TYPE *,
 /*inout*/ FILE_ERRNO_TYPE *);

void RENAME_DIRECTORY (
 /*in */ FILE_NAME_TYPE,
 /*in */ FILE_NAME_TYPE,
 /*out */ RETURN_CODE_TYPE *,
 /*inout*/ FILE_ERRNO_TYPE *);

#ifdef __cplusplus
}
#endif

#endif /* APEX_FILE_SYSTEM_H_ */
