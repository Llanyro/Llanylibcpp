/*
 * stringtype.cpp
 *
 *  Created on: Jan 19, 2021
 *      Author: llanyro
 */

#include "stringtype.h"

#include "../Libs/asciidefines.h"
#include "../Libs/stringlib.h"

#define LLANY_STRING_TYPE Llanylib::Core::Structs::StringType

namespace Llanylib {
namespace Corelib {
namespace Structs {
namespace StringType {

stringType getStringType(const char* str, const len_t& len) {
	return stringType();
}
stringType getStringType(const char* str) {
	stringType result;
	ll_bool_t continuar = true;
	len_t i = 0;
	do {
		if (str[i] == '\0')
			continuar = false;
		else if (str[i] == '.')
			result.numPoints++;
		// Si contiene un numero
		else if (STRING_LIB::contains_char(CHARS_NUMS, CHARS_NUMS_LEN, str + i))
			result.numNumbers++;
		// Si contiene un caracter mayus
		else if (STRING_LIB::contains_char(ABECEDARIO_2, ABECEDARIO_2_LEN, str + i))
			result.numCharsMayus++;
		// Si contiene un caracter minus
		else if (STRING_LIB::contains_char(ABECEDARIO_3, ABECEDARIO_3_LEN, str + i))
			result.numCharsMinus++;
		else
			result.numUnknownChars++;
		i++;
	} while (continuar);
	return result;
}

} /* namespace StringType */
} /* namespace Structs */
} /* namespace Core */
} /* namespace Llanylib */
