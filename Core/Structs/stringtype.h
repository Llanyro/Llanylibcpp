/*
 * stringtype.h
 *
 *  Created on: Jan 19, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_STRUCTS_STRINGTYPE_H_
#define LLANYLIB_CORE_STRUCTS_STRINGTYPE_H_

#include "../Libs/llanytypeslib.h"

namespace Llanylib {
namespace Core {
namespace Structs {

enum class StringType {
	String,
	IPv4,
	Number,
	Float
};

struct stringType {
	len_t numPoints = 0;
	len_t numNumbers = 0;
	len_t numCharsMayus = 0;
	len_t numCharsMinus = 0;
	len_t numUnknownChars = 0;
	StringType type = StringType::String;
};

stringType getStringType(const char* str, const len_t& len);
// Requiere un '/0' al final
stringType  getStringType(const char* str);



} /* namespace Structs */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_STRUCTS_STRINGTYPE_H_ */
