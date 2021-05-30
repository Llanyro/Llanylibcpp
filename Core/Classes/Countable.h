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

class Countable : protected Structs::llanyLen, public LlanyCore {
	public:
		Countable();
		Countable(const len_t& length);
		virtual ~Countable();
		// Retorno: Numero de objetos en la lista
		// Complejidad temporal y espacial: O(1) y M(1)
		len_t count() const;
		len_t len() const;
		len_t length() const;
		len_t size() const;
};

} /* namespace Classes */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_CLASSES_HERITABLES_LEN_H_ */
