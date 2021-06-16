/*
 * llanysimpleprint.h
 *
 *  Created on: Jan 19, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORELIB_SIMPLELIBS_LLANYSIMPLEPRINT_H_
#define LLANYLIB_CORELIB_SIMPLELIBS_LLANYSIMPLEPRINT_H_

#include <iostream>

#define PRINT(a) std::cout << a
#define PRINT2(a, b) std::cout << a << " " << b

#define PRINTLN(a) std::cout << a << std::endl
#define PRINT2LN(a, b) std::cout << a << " " << b << std::endl

#define LN std::cout << std::endl
#define ENDL LN;


#endif /* LLANYLIB_CORELIB_SIMPLELIBS_LLANYSIMPLEPRINT_H_ */
