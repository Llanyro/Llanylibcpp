/*
 * SmartContainers.h
 *
 *  Created on: Nov 27, 2020
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_CLASSES_CONTAINERS_SMARTCONTAINERS_H_
#define LLANYLIB_CORE_CLASSES_CONTAINERS_SMARTCONTAINERS_H_

#include "../LlanyCore.h"

#define CONTAINER Llanylib::Core::Classes::Containers

namespace Llanylib {
namespace Core {
namespace Classes {
namespace Containers {

template<class T>
class SmartContainer : public LlanyCore {
	protected:
		T* object_0;
		Destructor destructor_0;
	public:
		SmartContainer() : LlanyCore() {
			this->object_0 = nullptr;
			this->destructor_0 = nullptr;
		}
		SmartContainer(T* object_0, Destructor destructor_0) : SmartContainer<T>() {
			this->object_0 = object_0;
			this->destructor_0 = destructor_0;
		}
		SmartContainer(T* object_0) : SmartContainer<T>(object_0, nullptr) {}
		virtual ~SmartContainer() { this->remove_0(); }

		// Get/Set/Remove
		T* get_0() { return this->object_0; }
		const T* getConst_0() const { return this->object_0; }
		void set_0(T* object_0, Destructor destructor_0) {
			this->object_0 = object_0;
			this->destructor_0 = destructor_0;
		}
		void set_0(T* object_0) { this->set_0(object_0, nullptr); }
		void setSmart_0(T* object_0, Destructor destructor_0) {
			this->remove_0();
			this->set_0(object_0, destructor_0);
		}
		void setSmart_0(T* object_0) { this->setSmart_0(object_0, nullptr); }
		void setDestructor_0(Destructor destructor_0) { this->destructor_0 = destructor_0; }
		void remove_0() {
			if(this->destructor_0 != nullptr && this->object_0 != nullptr) {
				this->destructor_0((void**)&this->object_0);
				this->destructor_0 = nullptr;
			}
		}
		void del_0() { this->remove_0(); }

		// Funcion: Libera el puntero guardado y reinicia la clase
		// Version: Final
		// Retorno:
		//		True:  Si se ha eliminado algo
		//		False: Si no se ha eliminado nada
		// Complejidad temporal y espacial: O(1) y M(1)
		virtual ll_bool_t clear() override {
			this->remove_0();
			return true;
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

		// Get/Set/Remove
		T1* get_1() { return this->object_1; }
		const T1* getConst_1() const { return this->object_1; }
		void set_1(T1* object_1, Destructor destructor_1) {
			this->object_1 = object_1;
			this->destructor_1 = destructor_1;
		}
		void set_1(T1* object_1) { this->set_1(object_1, nullptr); }
		void setSmart_1(T1* object_1, Destructor destructor_1) {
			this->remove_1();
			this->set_1(object_1, destructor_1);
		}
		void setSmart_1(T1* object_1) { this->setSmart_1(object_1, nullptr); }
		void setDestructor_1(Destructor destructor_1) { this->destructor_1 = destructor_1; }
		void remove_1() {
			if(this->destructor_1 != nullptr && this->object_1 != nullptr) {
				this->destructor_1((void**)&this->object_1);
				this->destructor_1 = nullptr;
			}
		}
		void del_1() { this->remove_1(); }

		// Funcion: Libera el puntero guardado y reinicia la clase
		// Version: Final
		// Retorno:
		//		True:  Si se ha eliminado algo
		//		False: Si no se ha eliminado nada
		// Complejidad temporal y espacial: O(1) y M(1)
		virtual ll_bool_t clear() override {
			this->remove_0();
			this->remove_1();
			return true;
		}
};

} /* namespace Containers */
} /* namespace Classes */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_CLASSES_CONTAINERS_SMARTCONTAINERS_H_ */
