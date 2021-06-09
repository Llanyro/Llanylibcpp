/*
 * String.h
 *
 *  Created on: Jun 9, 2021
 *      Author: llanyro
 */

#ifndef CORE_CLASSES_STRING_H_
#define CORE_CLASSES_STRING_H_

#include "SimpleLists/Vector.h"

namespace Llanylib {
namespace Core {
namespace Classes {

class String : public SimpleLists::Vector<char> {
	public:
		String();
		String(const len_t& lenght);
		virtual ~String();
};

template<const len_t lenght>
class FixedString : public SimpleLists::FixedVector<char, lenght> {
	public:
		FixedString();
		virtual ~FixedString();
};

} /* namespace Classes */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* CORE_CLASSES_STRING_H_ */