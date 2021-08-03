/*
 * VectorBuffer.h
 *
 *  Created on: Mar 3, 2021
 *      Author: llanyro
 */

#ifndef LISTLIB_DYNAMICLISTS_VECTORBUFFER_H_
#define LISTLIB_DYNAMICLISTS_VECTORBUFFER_H_

#include "../../Corelib/Libs/memlib.h"

#include "Vector.h"

namespace Llanylib {
namespace Listlib {
namespace Dynamiclist {
/*
	Class vector created to being used in Buffer
*/
template<class T>
class VectorBuffer : public Dynamiclist::Vector<T> {
	protected:
		len_t num;	// Number of objects in list
		ll_bool_t isFull() const { return this->num == this->length; }
	public:
		VectorBuffer(const len_t& length) : Dynamiclist::Vector<T>(length) { this->num = 0; }


		~VectorBuffer() {}
		ll_bool_t add(const T& object) {
			ll_bool_t result = true;
			if (!this->isFull()) {
				this->vector[this->num] = object;
				this->num++;
			}
			else result = false;
			return result;
		}
		len_t add(const T* vector, const len_t& length) {
			len_t result = 0;
			if (!this->isFull()) {
				result = this->length - this->num;	// Numero de elementos que se pueden insertar

				// Reparamos el resultado si es necesario
				if (result > length) result = length;

				// Copiamos bit a bit la memmoria que cabe en el vector
				MEM_LIB::copiarMemoria(this->vector + this->num, vector, 0, result, sizeof(T));
				// Guardamos el tamaño nuevo guardado
				this->num += result;
			}
			return result;
		}

		ll_bool_t operator+=(const T& object) { return this->add(object); }
		ll_bool_t operator+=(const T* vector) { return this->add(vector); }
};

} /* namespace Dynamiclist */
} /* namespace Listlib */
} /* namespace Llanylib */

#endif /* LISTLIB_DYNAMICLISTS_VECTORBUFFER_H_ */
