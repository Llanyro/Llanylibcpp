/*
 * llanystring.cpp
 *
 *  Created on: Nov 28, 2020
 *      Author: llanyro
 */

#include "llanystring.h"

#include "../Libs/stringlib.h"
#include "../Libs/memlib.h"

namespace Llanylib {
namespace Corelib {
namespace Structs {
namespace String {

string* newLlanyString(const len_t& len) {
	string* str = new string();
	str->len = len + 1;
	str->free = true;
	str->str = new char[len + 1];
	fixLlanyString(str);
	return str;
}
string* newLlanyString(char const* const conststr) {
	string* str = nullptr;
	if (conststr != nullptr) {
		str = new string();
		//str->len = Simplelibs::String::stringlen(conststr, false) + 1;
		str->len = STRLEN_DEFINED_STRING(conststr) + 1;
		//str->len = (len_t)strlen(conststr) + 1;
		str->str = (char*)conststr;
		str->free = false;
		fixLlanyString(str);
	}
	return str;
}
void fixLlanyString(string* str) {
	// Si existe el string y es modificable
	if (str != nullptr && str->free)
		str->str[str->len - 1] = '\0';
}
void deleteLlanyString(string* str) {
	// Si existe el string
	if (str != nullptr) {
		// Es modificable y no contiene un nullptr
		if (str->free && str->str != nullptr)
			delete[] str->str;
		delete str;
	}
}
string* cloneLlanyString(const string* str) {
	string* newstr = new string();
	newstr->len = str->len;
	newstr->free = str->free;
	// Si no hay que liberar nada
	if(!str->free) newstr->str = str->str;
	else newstr->str = (char*)MEM_LIB::reservarYCopiar(str->str, 0, str->len, sizeof(char));
	return newstr;
}
ll_bool_t compareLlanyString(string* str, string* str2) {
	return STRING_LIB::strcmp(str->str, str->len, str2->str, str2->len);
}

} /* namespace String */
} /* namespace Structs */
} /* namespace Core */
} /* namespace Llanylib */
