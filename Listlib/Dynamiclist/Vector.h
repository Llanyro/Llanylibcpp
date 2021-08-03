/*
 * Vector.h
 *
 *  Created on: Mar 3, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_LISTLIB_VECTOR_VECTOR_H_
#define LLANYLIB_CORE_LISTLIB_VECTOR_VECTOR_H_

#include "../Corelist/List.h"
//#include "../../Corelib/Libs/memlib.h"

namespace Llanylib {
namespace Listlib {
namespace Dynamiclist {

/*
 * Clase para controlar vectores simples
 * */
template<class T>
class Vector : public Corelist::List<T> {
	protected:
		T* vector;
	public:
		Vector() { this->vector = nullptr; }
		Vector(const len_t& length) : Corelist::List<T>(length) { this->vector = new T[this->length]; }
		virtual ~Vector() {
			if (this->vector != nullptr) {
				delete[] this->vector;
				this->vector = nullptr;
			}
		}
		// Funcion: Obtiene el puntero del objeto solicitado
		// Precondiciones:
		//		posicion < count
		// Retorno: El objeto solicitado
		//		Si la posicion es erronea devuelve nullptr
		// Complejidad temporal y espacial: O(?) y M(1)
		virtual T* get(const len_t& position) const {
			T* result = nullptr;
			if(this->validPos(position))
				result = this->vector + position;
			return result;
		}
		// Funcion: Obtiene el puntero del objeto solicitado en formato const
		// Precondiciones:
		//		posicion < count
		// Retorno: El objeto solicitado
		//		Si la posicion es erronea devuelve nullptr
		// Complejidad temporal y espacial: O(?) y M(1)
		virtual const T* cget(const len_t& position) const {
			const T* result = nullptr;
			if(this->validPos(position))
				result = (this->vector + position);
			return result;
		}
		virtual T* operator[](const len_t& position) { return this->get(position); }

		virtual T* begin() const override { return this->vector; }
		virtual T* end() const override { return (this->vector + this->length - 1); }
		virtual const T* cbegin() const override { return this->vector; }
		virtual const T* cend() const override { return (this->vector + this->length - 1); }

		virtual ll_bool_t contains(const T* object, Compare_bool compare) const {
			ll_bool_t resultado = false;
			// Si tenemos la funcion de comparacion
			if (compare != nullptr) {
				for (len_t i = 0; !resultado && i < this->length; i++)
					resultado = compare(object, this->vector + i);
			}
			// Si no tenemos, usamos ==
			else {
				for (len_t i = 0; !resultado && i < this->length; i++)
					resultado = (*object == this->vector[i]);
			}
			return resultado;
		}
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
};

namespace Extra {

template<class T>
class Vector : public Dynamiclist::Vector<T> {
	protected:
		/*
		 * vector != nullptr
		 * if destructor == nullptr && free == true -> delete[] vector;
		 * if destructor == nullptr && free == false -> vector = nullptr;
		 * if destructor != nullptr && free == true -> destructor(&vector);
		 * if destructor != nullptr && free == false -> destructor(&vector);
		 * */
		ll_bool_t free = false; // Marca si es necesario liberar la memoria contenida
		Destructor destructor;
		ll_bool_t modificable;
	public:
		// Si queremos generar un vector de tamaño n
		Vector(const len_t& length) : Dynamiclist::Vector<T>(length) {
			this->free = true;
			this->destructor = nullptr;
			this->modificable = true;
		}
		// Si queremos controlar y guardar un vector creado externamente
		Vector(
			// Vector to use
			T* vector,
			// Size of vector
			const len_t& length,
			// If is  freeable
			const ll_bool_t& free,
			// Function to free the vector to use
			Destructor destructor) {
			this->vector = vector;
			this->length = length;
			this->free = free;
			this->destructor = destructor;
			// Es modificable si, se puede liberar de una manera u otra
			this->modificable = (this->free || this->destructor != nullptr);
		}
		/* Atajos */
		Vector() : Vector(300) {}
		Vector(
			// Vector to use
			T* vector,
			// Size of vector
			const len_t& length) : Vector(vector, length, false, nullptr) {}
		Vector(
			// Vector to use
			T* vector,
			// Size of vector
			const len_t& length,
			// If is  freeable
			const ll_bool_t& free) : Vector(vector, length, free, nullptr) {}
		Vector(
			// Vector to use
			T* vector,
			// Size of vector
			const len_t& length,
			// Function to free the vector to use
			Destructor destructor) : Vector(vector, length, true, destructor) {}
		virtual ~Vector() {
			// Si tenemos destructor, liberamos el vector
			if (this->destructor != nullptr) {
				this->destructor(this->vector);
				this->destructor = nullptr;
			}

			// Si no tenemos destructor, pero aun asi queremos liberarlo
			if (this->free == true) {
				delete[] this->vector;
				this->free = false;
			}

			this->vector = nullptr;
			this->modificable = false;
		}
	public:
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
			if (this->modificable && this->in_range(position))
				this->vector[position] = item;
			else result = false;
			return result;
		}
};

} /* namespace Extra */

namespace Buffer {


/*
	Class vector created to being used in Buffer
*/
template<class T>
class Vector : public Dynamiclist::Vector<T> {
	public:
		Vector(const len_t& length) : Dynamiclist::Vector<T>(length) {}
		~Vector(){}
};

} /* namespace Buffer */

} /* namespace Dynamiclist */
} /* namespace Listlib */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_LISTLIB_VECTOR_VECTOR_H_ */
