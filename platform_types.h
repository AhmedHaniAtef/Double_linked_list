/**
 * @file    : platform_types.h
 * @brief   : Defining new data types
 * @date    : 25 AUG 2023
 * @details : This file contains the new data types.
 * @author  : Ahmed Hani Atef
*/

#ifndef _PLATFORM_TYPES_H
#define _PLATFORM_TYPES_H

/********************* Start of Libraries includes********************/
#include <stdio.h>
#include <stdlib.h>
/********************* End of Libraries includes *********************/

/************************* Start of Defines **************************/
#define ZERO (0)
/************************** End of Defines ***************************/

/********************** Start of Platform Types **********************/
typedef unsigned char       uint8_t;
typedef unsigned short      uint16_t;
typedef unsigned int        uint32_t;
typedef unsigned long int   uint64_t;
typedef signed char         sint8_t;
typedef signed short        sint16_t;
typedef signed int          sint32_t;
typedef signed long int     sint64_t;
typedef float               float32_t;
typedef double              float64_t;
/*********************** End of Platform Types ***********************/

#endif

/*===================================================================================================
*   Revision log
    Date            By                  Description
    ------------    -----------------   -------------------------------------------------------------
    25 AUG 2023     Ahmed Hani Atef     Creating of platform_types.h file and creating new data types

=====================================================================================================*/