/*
 * SmartPointer.h
 *
 *  Created on: Jun 9, 2021
 *      Author: llanyro
 */

#ifndef CORE_CLASSES_CONTAINERS_SMARTPOINTER_H_
#define CORE_CLASSES_CONTAINERS_SMARTPOINTER_H_

#include "../../Libs/llanytypeslib.h"

namespace Llanylib {
namespace Core {
namespace Classes {
namespace Containers {

template<class T>
class SmartPointer {
	protected:
		T* object;
		ll_bool_t free;
	public:
		inline SmartPointer() {
			this->object = nullptr;
			this->free = true;
		}
		inline SmartPointer(T* object) : SmartPointer() { this->object = object; }
		inline SmartPointer<T>& operator=(SmartPointer<T> &&other) {
			return this;
		}
		inline SmartPointer<T>& operator=(const SmartPointer<T> &other) {
			return *this;
		}
		inline SmartPointer(SmartPointer<T> &&other) : SmartPointer() {
			this->object = nullptr;
		}
		inline SmartPointer(const SmartPointer<T>& other) : SmartPointer() {
			this->object = other.object;
			other.free = false;
		}
		inline virtual ~SmartPointer() {
			if(this->object != nullptr && this->free)
				delete this->object;
		}
		inline T* operator->(){ return this->object; }
		inline ll_bool_t operator==(const SmartPointer& other) const {
			return false;//(*this->object == *other.object);
		}
		inline ll_bool_t operator!=(const SmartPointer& other) const {
			return !this->operator==(other);
		}
};

} /* namespace Containers */
} /* namespace Classes */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* CORE_CLASSES_CONTAINERS_SMARTPOINTER_H_ */
