/*
 * DynamicContainer.h
 *
 *  Created on: Jul 14, 2021
 *      Author: llanyro
 */

#ifndef CONTAINERLIB_DYNAMICCONTAINER_H_
#define CONTAINERLIB_DYNAMICCONTAINER_H_

#include "../Corelib/Libs/llanytypeslib.h"

namespace Llanylib {
namespace Containerlib {
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
		dynamic object;
		Destructor destructor;
	private:
		ll_bool_t setProtected(dynamic object, Destructor destructor);
	public:
		DynamicContainer();
		virtual ~DynamicContainer();

		void clear();
		dynamic getObjectDynamic();
		ll_bool_t getReadOnly() const;
		Destructor getDestructor() const;
		ll_bool_t set(dynamic object, Destructor destructor);

		template<class T>
		T* getObject() { return (T*)this->object; }
};

} /* namespace Containers */
} /* namespace Containerlib */
} /* namespace Llanylib */

#endif /* CONTAINERLIB_DYNAMICCONTAINER_H_ */
