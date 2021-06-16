/*
 * llanymathtypeslib.h
 *
 *  Created on: Feb 6, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_SIMPLELIBS_LLANYMATHTYPESLIB_H_
#define LLANYLIB_CORE_SIMPLELIBS_LLANYMATHTYPESLIB_H_

#include "llanytypeslib.h"

typedef ll_float_t ll_coordinate_t;

#define PI_VAL (3.14159265358979323846)
#define E_VAL 2.718

#define TWO_PI_VAL 2 * PI_VAL
#define TAU_VAL TWO_PI_VAL

// Obtiene el numero mayor de dos numeros
#define GET_MAX(a,b) (((a)>(b))?(a):(b))
// Obtiene el numero menor de dos numeros
#define GET_MIN(a,b) (((a)<(b))?(a):(b))
// Devuelve true si el primero es mayor
#define EVALUATE(a,b) ((a > b) ? true : false)
// Devuelve true si el primero es mayor o igual
#define EVALUATE_2(a,b) ((a >= b) ? true : false)

#define GRAVITATIONAL_CONSTANT 6.674e-10
#define GRAVITATIONAL_CONSTANT_2 6.674


#endif /* LLANYLIB_CORE_SIMPLELIBS_LLANYMATHTYPESLIB_H_ */
