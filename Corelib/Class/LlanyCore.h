/*
 * LlanyCore.h
 *
 *  Created on: Nov 27, 2020
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORELIBLIBLIB_CLASSES_HERITABLES_LLANYCORE_H_
#define LLANYLIB_CORELIBLIB_CLASSES_HERITABLES_LLANYCORE_H_

#include  "../Libs/llanytypeslib.h"
#include "String.h"

namespace Llanylib {
namespace Corelib {
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
		virtual String* hash() const;
		// Sirve para generar una funcion para poder printear la clase
		virtual String* toString() const;
		// Serialize y toJSON son iguales, es decir
		//	el serializador simula o imita el metodo json
		virtual String* serialize() const;
		void* clone() const;
};

} /* namespace Classes */
} /* namespace Corelib */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORELIBLIB_CLASSES_HERITABLES_LLANYCORE_H_ */
