/*
 * stringlib.h
 *
 *  Created on: Mar 7, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORELIBLIB_SIMPLELIBS_STRINGLIB_H_
#define LLANYLIB_CORELIBLIB_SIMPLELIBS_STRINGLIB_H_

#include "llanymathtypeslib.h"

#define STRING_LIB Llanylib::Core::Libs::String

namespace Llanylib {
namespace Corelib {
namespace Libs {
namespace String {

// Simplificados
ll_bool_t strcmp(const char* str_1, const char* str_2);
ll_bool_t strcmp(const char* str_1, const len_t& len, const char* str_2);
ll_bool_t strcmp(const char* str_1, const char* str_2, const len_t& len);
ll_bool_t strcmp_similar(const char* str_1, const char* str_2);
ll_bool_t strcmp_similar(const char* str_1, const len_t& len, const char* str_2);
ll_bool_t strcmp_similar(const char* str_1, const char* str_2, const len_t& len);
ll_bool_t contains_char(const char* str, const char* character);

// String compare
ll_bool_t strcmp(const char* str_1, const len_t& len_1, const char* str_2, const len_t len_2);
ll_bool_t strcmp_similar(const char* str_1, const len_t& len_1, const char* str_2, const len_t len_2);
// Start with
ll_bool_t start_with(const char* str_1, const len_t& len_1, const char* str_2, const len_t len_2);
ll_bool_t start_with_similar(const char* str_1, const len_t& len_1, const char* str_2, const len_t len_2);

// Devuelve si un caracter esta contenido en un string
ll_bool_t contains_char(const char* str, const len_t& len, const char* character);
// Devuelve si es un numero natural
ll_bool_t is_number(const char* str, const len_t& lenght);
ll_bool_t is_float(const char* str, const len_t& lenght);

ll_bool_t is_number(const char* str, const len_t& lenght);
ll_bool_t is_float(const char* str, const len_t& lenght);

#define STRLEN_DEFINED_STRING(str) (sizeof(str) + 1)
len_t stringlenght(const char* str);
len_t stringlenght_low(const char* str);


} /* namespace String */
} /* namespace Libs */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORELIBLIB_SIMPLELIBS_STRINGLIB_H_ */
