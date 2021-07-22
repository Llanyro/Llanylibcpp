/*
 * llanytypeslib.h
 *
 *  Created on: Nov 16, 2020
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORELIB_SIMPLELIBS_LLANYTYPESLIB_H_
#define LLANYLIB_CORELIB_SIMPLELIBS_LLANYTYPESLIB_H_

// Signed
typedef char ll_char_t;
typedef short ll_short_t;
typedef int ll_int_t;
typedef long ll_long_t;
typedef long long ll_longlong_t;

typedef unsigned char ll_uchar_t;
typedef unsigned short ll_ushort_t;
typedef unsigned int ll_uint_t;
typedef unsigned long ll_ulong_t;
typedef unsigned long long ll_ulonglong_t;

// Flotantes
typedef float ll_float_t;
typedef double ll_double_t;
typedef long double ll_ldouble_t;
//typedef char ll_ldouble_t;

//Bits
typedef ll_char_t ll_int8_t;
typedef ll_uchar_t ll_uint8_t;
typedef ll_short_t ll_int16_t;
typedef ll_ushort_t ll_uint16_t;
typedef ll_int_t ll_int32_t;
typedef ll_uint_t ll_uint32_t;

#if defined __x86_64__ && !defined __ILP32__
typedef ll_long_t ll_int64_t;
typedef ll_ulong_t ll_uint64_t;
#else
typedef ll_longlong_t ll_int64_t;
typedef ll_ulonglong_t ll_uint64_t;
#endif

typedef ll_uchar_t hex;		// Usado para guardar el valor numerico de un Hexadecimal
typedef ll_uint64_t len_t; 	// Usado para posiciones de listas y tamaños de listas -> es decir: cantidades de datos
typedef bool ll_bool_t;
//typedef enum { False, True } ll_bool_t;
//typedef char const* const ll_constchar_t;
typedef void* dynamic;
typedef void ll_void;

/*
32 bits
char 		Bytes 1 : -128 to 127												-> 255
short 		Bytes 2 : -32,768 to 32,767											-> 65,535
int 		Bytes 4 : -2,147,483,648 to 2,147,483,647							-> 4,294,967,295
long 		Bytes 4 : -2,147,483,648 to 2,147,483,647							-> 4,294,967,295
long long	Bytes 8 : -9,223,372,036,854,775,808 to 9,223,372,036,854,775,808	-> 18,446,744,073,709,551,615

64 bits
char 		Bytes 1 : -128 to 127												-> 255
short 		Bytes 2 : -32,768 to 32,767											-> 65,535
int 		Bytes 4 : -2,147,483,648 to 2,147,483,647							-> 4,294,967,295
long 		Bytes 8 : -9,223,372,036,854,775,808 to 9,223,372,036,854,775,808	-> 18,446,744,073,709,551,615
long long	Bytes 8 : -9,223,372,036,854,775,808 to 9,223,372,036,854,775,808	-> 18,446,744,073,709,551,615

32 & 64 bits
float		Bytes 4 :
double		Bytes 8 :
long double	Bytes 16:
*/

typedef ll_int_t (*Compare_int)(const void* item_a, const void* item_b);
typedef ll_bool_t (*Compare_bool)(const void* item_a, const void* item_b);
typedef ll_int_t (*CompareChar_int)(const char* caracter1, const char* caracter2);
typedef ll_uint32_t (*Range_uint32)(const ll_uint32_t& value);
typedef void (*Destructor)(void*);

#define COMPARE_INT_T ll_int_t compare_t(const T* item_a, const T* item_b)
#define COMPARE_BOOL_T ll_bool_t compare_t(const T* item_a, const T* item_b)

#define TRUE_STRING "True"
#define TRUE_STRING_LEN 4
#define FALSE_STRING "False"
#define FALSE_STRING_LEN 5
#define TRUE_VALUE 1
#define FALSE_VALUE 0

#endif /* LLANYLIB_CORELIB_SIMPLELIBS_LLANYTYPESLIB_H_ */
