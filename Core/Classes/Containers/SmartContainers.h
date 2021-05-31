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
		T* item_0;
		Destructor destructor_0;
	public:
		SmartContainer() : LlanyCore() {
			this->item_0 = nullptr;
			this->destructor_0 = nullptr;
		}
		SmartContainer(T* item_0, Destructor destructor_0) : SmartContainer<T>() {
			this->set_0(item_0, destructor_0);
		}
		SmartContainer(T* item_0) : SmartContainer<T>(item_0, nullptr) {}
		virtual ~SmartContainer() { this->remove_0(); }

		// Get/Set/Remove
		T* get_0() { return this->item_0; }
		const T* getConst_0() const { return this->item_0; }
		void set_0(T* item_0, Destructor destructor_0) {
			this->item_0 = item_0;
			this->destructor_0 = destructor_0;
		}
		void set_0(T* item_0) { this->set_0(item_0, nullptr); }
		void setSmart_0(T* item_0, Destructor destructor_0) {
			this->remove_0();
			this->set_0(item_0, destructor_0);
		}
		void setSmart_0(T* item_0) { this->setSmart_0(item_0, nullptr); }
		void remove_0() {
			if(this->destructor_0 != nullptr && this->item_0 != nullptr) {
				this->destructor_0((void**)&this->item_0);
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
		T1* item_1;
		Destructor destructor_1;
	public:
		SmartContainerDouble() : SmartContainer<T0>() {
			this->item_1 = nullptr;
			this->destructor_1 = nullptr;
		}
		SmartContainerDouble(T0* item_0, Destructor destructor_0, T1* item_1, Destructor destructor_1)
		: SmartContainer<T0>(item_0, destructor_0) {
			this->set_1(item_1, destructor_1);
		}
		SmartContainerDouble(T0* item_0, T1* item_1, Destructor destructor_1)
		: SmartContainerDouble<T0, T1>(item_0, nullptr, item_1, destructor_1) {}
		SmartContainerDouble(T0* item_0, Destructor destructor_0, T1* item_1)
		: SmartContainerDouble<T0, T1>(item_0, destructor_0, item_1, nullptr) {}
		SmartContainerDouble(T0* item_0, T1* item_1)
		: SmartContainerDouble<T0, T1>(item_0, nullptr, item_1, nullptr) {}
		virtual ~SmartContainerDouble() { this->remove_1(); }

		// Get/Set/Remove
		T1* get_1() { return this->item_1; }
		const T1* getConst_1() const { return this->item_1; }
		void set_1(T1* item_1, Destructor destructor_1) {
			this->item_1 = item_1;
			this->destructor_1 = destructor_1;
		}
		void set_1(T1* item_1) { this->set_1(item_1, nullptr); }
		void setSmart_1(T1* item_1, Destructor destructor_1) {
			this->remove_1();
			this->set_1(item_1, destructor_1);
		}
		void setSmart_1(T1* item_1) { this->setSmart_1(item_1, nullptr); }
		void remove_1() {
			if(this->destructor_1 != nullptr && this->item_1 != nullptr) {
				this->destructor_1((void**)&this->item_1);
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
