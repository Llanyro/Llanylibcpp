/*
 * LlanyCore.h
 *
 *  Created on: Nov 27, 2020
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORELIB_CLASSES_HERITABLES_LLANYCORE_H_
#define LLANYLIB_CORELIB_CLASSES_HERITABLES_LLANYCORE_H_

#include  "../Libs/llanytypeslib.h"

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
		virtual dynamic hash() const;
		// Sirve para generar una funcion para poder printear la clase
		virtual dynamic toString() const;
		// Serialize y toJSON son iguales, es decir
		//	el serializador simula o imita el metodo json
		virtual dynamic serialize() const;
		void* clone() const;
};

} /* namespace Classes */
} /* namespace Corelib */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORELIB_CLASSES_HERITABLES_LLANYCORE_H_ */
