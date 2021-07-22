/*
 * SmartContainers.h
 *
 *  Created on: Jul 14, 2021
 *      Author: llanyro
 */

#ifndef CONTAINERLIB_SMARTCONTAINERS_H_
#define CONTAINERLIB_SMARTCONTAINERS_H_

#include "../Corelib/Libs/llanytypeslib.h"

#define SMART_CONTAINERS Llanylib::Containerlib::SmartContainers

namespace Llanylib {
namespace Containerlib {
namespace SmartContainers {

template<class T>
class SmartContainer {
	public:
		T* object_0;
		Destructor destructor_0;
	public:
		SmartContainer() {
			this->object_0 = nullptr;
			this->destructor_0 = nullptr;
		}
		SmartContainer(T* object_0, Destructor destructor_0) : SmartContainer<T>() {
			this->object_0 = object_0;
			this->destructor_0 = destructor_0;
		}
		SmartContainer(T* object_0) : SmartContainer<T>(object_0, nullptr) {}
		virtual ~SmartContainer() { this->remove_0(); }
		T* get_object_0() { return this->object_0; }
		const T* get_const_object_0() const { return this->object_0; }

		// Set/Remove
		void set_0(T* object_0) { this->set_0(object_0, nullptr); }
		void setSmart_0(T* object_0) { this->setSmart_0(object_0, nullptr); }
		void setDestructor_0(Destructor destructor_0) { this->destructor_0 = destructor_0; }
		void del_0() { this->remove_0(); }

		void set_0(T* object_0, Destructor destructor_0) {
			this->object_0 = object_0;
			this->destructor_0 = destructor_0;
		}
		void setSmart_0(T* object_0, Destructor destructor_0) {
			this->remove_0();
			this->set_0(object_0, destructor_0);
		}
		void remove_0() {
			if(this->destructor_0 != nullptr && this->object_0 != nullptr) {
				this->destructor_0((void*)this->object_0);
				this->destructor_0 = nullptr;
				this->object_0 = nullptr;
			}
		}
};

template<class T0, class T1>
class SmartContainerDouble : public SmartContainer<T0> {
	protected:
		T1* object_1;
		Destructor destructor_1;
	public:
		SmartContainerDouble() : SmartContainer<T0>() {
			this->object_1 = nullptr;
			this->destructor_1 = nullptr;
		}
		SmartContainerDouble(T0* object_0, Destructor destructor_0, T1* object_1, Destructor destructor_1)
		: SmartContainer<T0>(object_0, destructor_0) {
			this->object_1 = object_1;
			this->destructor_1 = destructor_1;
		}
		SmartContainerDouble(T0* object_0, T1* object_1, Destructor destructor_1)
		: SmartContainerDouble<T0, T1>(object_0, nullptr, object_1, destructor_1) {}
		SmartContainerDouble(T0* object_0, Destructor destructor_0, T1* object_1)
		: SmartContainerDouble<T0, T1>(object_0, destructor_0, object_1, nullptr) {}
		SmartContainerDouble(T0* object_0, T1* object_1)
		: SmartContainerDouble<T0, T1>(object_0, nullptr, object_1, nullptr) {}
		virtual ~SmartContainerDouble() { this->remove_1(); }
		T1* get_object_1() { return this->object_1; }
		const T1* get_const_object_1() const { return this->object_1; }

		// Get/Set/Remove
		void set_1(T1* object_1) { this->set_1(object_1, nullptr); }
		void setSmart_1(T1* object_1) { this->setSmart_1(object_1, nullptr); }
		void setDestructor_1(Destructor destructor_1) { this->destructor_1 = destructor_1; }
		void del_1() { this->remove_1(); }

		void set_1(T1* object_1, Destructor destructor_1) {
			this->object_1 = object_1;
			this->destructor_1 = destructor_1;
		}

		void setSmart_1(T1* object_1, Destructor destructor_1) {
			this->remove_1();
			this->set_1(object_1, destructor_1);
		}
		void remove_1() {
			if(this->destructor_1 != nullptr && this->object_1 != nullptr) {
				this->destructor_1((void*)this->object_1);
				this->destructor_1 = nullptr;
				this->object_1 = nullptr;
			}
		}
};

} /* namespace Containers */
} /* namespace Containerlib */
} /* namespace Llanylib */

#endif /* CONTAINERLIB_SMARTCONTAINERS_H_ */
