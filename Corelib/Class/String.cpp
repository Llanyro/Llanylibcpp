/*
 * String.cpp
 *
 *  Created on: Jun 9, 2021
 *      Author: llanyro
 */

#include "String.h"

#include "../Libs/stringlib.h"


namespace Llanylib {
namespace Corelib {
namespace Classes {

String::String() : Vector(){}
String::String(const len_t& lenght) : Vector(lenght){}
String::~String(){}
inline ll_bool_t String::operator==(const String& other) const {
	return STRING_LIB::strcmp(this->vector, this->length, other.vector, other.length);
}
inline ll_bool_t String::operator!=(const String& other) const {
	return !this->operator==(other);
}






template<len_t lenght>
FixedString<lenght>::FixedString() : String(lenght){}
template<len_t lenght>
FixedString<lenght>::~FixedString(){}

} /* namespace Classes */
} /* namespace Core */
} /* namespace Llanylib */
