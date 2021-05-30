/*
 * DynamicContainer.h
 *
 *  Created on: Dec 15, 2020
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_CLASSES_CONTAINERS_DYNAMICCONTAINER_H_
#define LLANYLIB_CORE_CLASSES_CONTAINERS_DYNAMICCONTAINER_H_

#include "../Libs/llanytypeslib.h"

namespace Llanylib {
namespace Core {
namespace Classes {
namespace Containers {

/*
 * Contenedor de tipado no especifico
 * Guarda items generador con new/new[] por defecto, pero puede guardar cualquier
 *   tipo de punteros siempre que se pase un destructor valido
 *
 * Si 'Destructor' esta a nullptr, se considera que el puntero es de readonly
 *
 * Ocupa 24 bytes aprox
 * */
class DynamicContainer {
	private:
		Dynamic object;
		Destructor destructor;
	private:
		ll_bool_t setProtected(Dynamic object, Destructor destructor);
	public:
		DynamicContainer();
		virtual ~DynamicContainer();

		void clear();
		Dynamic getObjectDynamic();
		ll_bool_t getReadOnly() const;
		Destructor getDestructor() const;
		ll_bool_t set(Dynamic object, Destructor destructor);

		template<class T>
		T* getObject() { return (T*)this->object; }
};

} /* namespace Containers */
} /* namespace Classes */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_CLASSES_CONTAINERS_DYNAMICCONTAINER_H_ */
