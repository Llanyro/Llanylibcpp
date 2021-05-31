/*
 * Containers.h
 *
 *  Created on: Nov 24, 2020
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_CLASSES_CONTAINERS_CONTAINERS_H_
#define LLANYLIB_CORE_CLASSES_CONTAINERS_CONTAINERS_H_

#include "../LlanyCore.h"

#define CONTAINER Llanylib::Core::Classes::Containers

namespace Llanylib {
namespace Core {
namespace Classes {
namespace Containers {

template<class T>
class Container : public LlanyCore {
	protected:
		T item_0;
	public:
		// Constructores
		Container() : LlanyCore() { this->item_0 = T(); }
		Container(const T& item_0) { this->item_0 = item_0; }
		Container(const Container* other) {
			if (other != nullptr)
				this->item_0 = other->item_0;
			else
				this->item_0 = T();
		}
		virtual ~Container() {}
		// Get/Set
		T* get_0() { return &this->item_0; }
		const T* getConst_0() const { return &this->item_0; }
		void set_0(const T& item_0) { this->item_0 = item_0; }
};

template<class T0, class T1>
class ContainerDouble : public Container<T0> {
	protected:
		T1 item_1;
	public:
		// Constructores
		ContainerDouble() : Container<T0>() { this->item_1 = T1(); }
		ContainerDouble(const T0& item_0, const T1& item_1) : Container<T0>(item_0) {
			this->item_1 = item_1;
		}
		ContainerDouble(const ContainerDouble* other) : Container<T0>(other) {
			if (other != nullptr)
				this->item_1 = other->item_1;
			else
				this->item_1 = T1();
		}
		virtual ~ContainerDouble() {}
		// Get/Set
		T1* get_1() { return &this->item_1; }
		const T1* getConst_1() const { return &this->item_1; }
		void set_1(const T1& item_1) { this->item_1 = item_1; }
};

} /* namespace Containers */
} /* namespace Classes */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_CLASSES_CONTAINERS_CONTAINERS_H_ */
