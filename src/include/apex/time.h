/*
 * time.h
 *
 *  Created on: Jan 27, 2022
 *      Author: hakan.keskin
 */

#ifndef APEX_TIME_H_
#define APEX_TIME_H_

/*--------------------------------------------------------------*/
/* 																*/
/* TIME constant and type definitions and management services 	*/
/* 																*/
/*--------------------------------------------------------------*/

#include "types.h"


#ifdef __cplusplus
extern "C" {
#endif

void PERIODIC_WAIT(/*out*/ RETURN_CODE_TYPE*);

void GET_TIME(/*out*/ SYSTEM_TIME_TYPE*, /*out*/ RETURN_CODE_TYPE*);

#ifdef __cplusplus
}
#endif

#endif /* APEX_TIME_H_ */
