/*
 * String.h
 *
 *  Created on: Jun 9, 2021
 *      Author: llanyro
 */

#ifndef CORE_CLASSES_STRING_H_
#define CORE_CLASSES_STRING_H_

//#include "SimpleLists/Vector.h"
//#include "../../Listlib/Dynamiclist/Vector.h"

namespace Llanylib {
namespace Corelib {
namespace Classes {

class String {
	char* a;
};

/*class String : public Listlib::Dynamiclist::Vector<char> {
	public:
		String();
		String(const len_t& lenght);
		virtual ~String();
		ll_bool_t operator==(const String& other) const;
		ll_bool_t operator!=(const String& other) const;
};

template<const len_t lenght>
class FixedString : public SimpleLists::FixedVector<char, lenght> {
	public:
		FixedString();
		virtual ~FixedString();
};*/

} /* namespace Classes */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* CORE_CLASSES_STRING_H_ */
