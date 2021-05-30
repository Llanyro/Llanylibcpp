/*
 * LlanyCore.h
 *
 *  Created on: Nov 27, 2020
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_CLASSES_HERITABLES_LLANYCORE_H_
#define LLANYLIB_CORE_CLASSES_HERITABLES_LLANYCORE_H_

#include  "../Libs/llanymathtypeslib.h"

namespace Llanylib {
namespace Core {
namespace Classes {

class LlanyCore {
	protected:
		LlanyCore();
		virtual ~LlanyCore();
	public:
		// Funcion: Limpia el objeto
		// Devuelve true si todo ha salido correctamente
		// Complejidad temporal y espacial: O(?) y M(1)
		virtual ll_bool_t clear();
		// Devuelve un hash del objeto en formato string
		virtual void* hash() const;
		// Sirve para generar una funcion para poder printear la clase
		virtual void* toString() const;
		// Serialize y toJSON son iguales, es decir
		//	el serializador simula o imita el metodo json
		virtual void* serialize() const;
		template<class T>
		T* clone() const { return nullptr; }
};

} /* namespace Classes */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_CLASSES_HERITABLES_LLANYCORE_H_ */
