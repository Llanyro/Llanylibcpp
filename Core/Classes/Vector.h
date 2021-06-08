/*
 * Vector.h
 *
 *  Created on: Jun 8, 2021
 *      Author: llanyro
 */

#ifndef CORE_CLASSES_VECTOR_H_
#define CORE_CLASSES_VECTOR_H_

#include "Countable.h"

namespace Llanylib {
namespace Core {
namespace Classes {

template<class T>
class Vector : public Countable {
	protected:
		T* vector;
	public:
		Vector() : Vector(300) {}
		Vector(const len_t& length) : Countable(length) {
			this->vector = new T[this->length];
		}
		virtual ~Vector() { delete[] this->vector; }
		// Funcion: Sustituye el objeto antiguo por uno nuevo
		// Version: Final
		// Precondiciones:
		//		pos < length
		// Retorno:
		//		 true: Si se ha seteado todo correctamente
		//		false: Si no se ha podido setear todo correctamente
		// Complejidad temporal y espacial: O(1) y M(1)
		virtual ll_bool_t set(const T& item, const len_t& position) {
			ll_bool_t result = true;
			if (this->in_range(position))
				this->vector[position] = item;
			else result = false;
			return result;
		}
		// Funcion: Obtiene el puntero del objeto solicitado
		// Precondiciones:
		//		posicion < count
		// Retorno: El objeto solicitado
		//		Si la posicion es erronea devuelve nullptr
		// Complejidad temporal y espacial: O(1) y M(1)
		virtual T* get(const len_t& position) const {
			T* item = nullptr;
			if(this->in_range(position))
				item = (T*)(this->vector + position);
			return item;
		}
		// Funcion: Obtiene el puntero del objeto solicitado en formato const
		// Precondiciones:
		//		posicion < count
		// Retorno: El objeto solicitado
		//		Si la posicion es erronea devuelve nullptr
		// Complejidad temporal y espacial: O(1) y M(1)
		virtual const T* cget(const len_t& position) const {
			const T* item = nullptr;
			if (this->in_range(position))
				item = this->vector + position;
			return item;
		}
		virtual T& operator[](const len_t& position) const {
			return this->in_range(position) ? 
				this->vector[position] : 
				this->vector[this->length - 1];
		}
};

template<class T, const len_t lenght>
class FixedVector : public Vector<T> {
	public:
		FixedVector() : Vector<T>(lenght) {}
		virtual ~FixedVector() {}
};

} /* namespace Classes */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* CORE_CLASSES_VECTOR_H_ */
