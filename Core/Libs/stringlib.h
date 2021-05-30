/*
 * stringlib.h
 *
 *  Created on: Mar 7, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_SIMPLELIBS_STRINGLIB_H_
#define LLANYLIB_CORE_SIMPLELIBS_STRINGLIB_H_

#include "llanymathtypeslib.h"

#define STRING_LIB Llanylib::Core::Libs::String

namespace Llanylib {
namespace Core {
namespace Libs {
namespace String {

// Simplificados
ll_bool_t isNumber(const char* str);
ll_bool_t isFloat(const char* str);
ll_bool_t isNumber(const char* str, const ll_bool_t isDynamic);
ll_bool_t isFloat(const char* str, const ll_bool_t isDynamic);
ll_bool_t strcmp(const char* str_1, const char* str_2);
ll_bool_t strcmp(const char* str_1, const len_t& len, const char* str_2);
ll_bool_t strcmp(const char* str_1, const char* str_2, const len_t& len);
ll_bool_t strcmpSimilar(const char* str_1, const char* str_2);
ll_bool_t strcmpSimilar(const char* str_1, const len_t& len, const char* str_2);
ll_bool_t strcmpSimilar(const char* str_1, const char* str_2, const len_t& len);
ll_bool_t containsChar(const char* str, const char* character);

// String compare
ll_bool_t strcmp(const char* str_1, const len_t& len_1, const char* str_2, const len_t len_2);
ll_bool_t strcmpSimilar(const char* str_1, const len_t& len_1, const char* str_2, const len_t len_2);
// Start with
ll_bool_t startWith(const char* str_1, const len_t& len_1, const char* str_2, const len_t len_2);
ll_bool_t startWithSimilar(const char* str_1, const len_t& len_1, const char* str_2, const len_t len_2);

// Devuelve si un caracter esta contenido en un string
ll_bool_t containsChar(const char* str, const len_t& len, const char* character);
// Devuelve si es un numero natural
ll_bool_t isNumber(const char* str, const len_t& len);
ll_bool_t isFloat(const char* str, const len_t& len);

ll_bool_t isNumber(const char* str, const len_t& len);
ll_bool_t isFloat(const char* str, const len_t& len);

#define STRLEN_DEFINED_STRING(str) sizeof(str)
len_t stringlen(const char* str, const ll_bool_t isDynamic);
len_t stringlen(const char* str);
len_t stringlen_low(const char* str);


} /* namespace String */
} /* namespace Libs */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_SIMPLELIBS_STRINGLIB_H_ */
