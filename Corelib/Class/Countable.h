/*
 * Len.h -> Countable.h
 *
 *  Created on: Jan 17, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_CLASSES_HERITABLES_LEN_H_
#define LLANYLIB_CORE_CLASSES_HERITABLES_LEN_H_

#include "../Structs/basicstructs.h"

#include "LlanyCore.h"

namespace Llanylib {
namespace Core {
namespace Classes {

class Countable : public Classes::LlanyCore, protected Structs::llanyLen {
	public:
		Countable();
		Countable(const len_t& length);
		virtual ~Countable();
		// Retorno: Numero de objetos en la lista
		// Complejidad temporal y espacial: O(1) y M(1)
		len_t count() const;
		len_t len() const;
		len_t size() const;
		// Funcion: Comprueba si la posicion dada se puede encontrar en la lista
		// Version: Final
		// Precondiciones:
		//		Ninguna
		// Retorno:
		//		 true: Si la posicion dada esta en la lista
		//		false: Si la posicion dada no esta en la lista
		// Complejidad temporal y espacial: O(1) y M(1)
		ll_bool_t in_range(const len_t& position) const;
		virtual ll_bool_t clear() override;
};

} /* namespace Classes */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_CLASSES_HERITABLES_LEN_H_ */