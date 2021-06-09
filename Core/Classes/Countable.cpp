/*
 * Len.cpp -> Countable.cpp
 *
 *  Created on: Jan 17, 2021
 *      Author: llanyro
 */

#include "Countable.h"

namespace Llanylib {
namespace Core {
namespace Classes {

Countable::Countable() { this->length = 0; }
Countable::Countable(const len_t& length) { this->length = length; }
Countable::~Countable() { this->length = 0; }

// Retorno: Numero de objetos en la lista
// Complejidad temporal y espacial: O(1) y M(1)
len_t Countable::count() const { return this->length; }
len_t Countable::len() const { return this->length; }
len_t Countable::size() const { return this->length; }
ll_bool_t Countable::in_range(const len_t& position) const { return position < this->length; }
void Countable::clear() { this->length = 0; }

} /* namespace Classes */
} /* namespace Core */
} /* namespace Llanylib */
