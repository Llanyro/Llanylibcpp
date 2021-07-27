/*
 * Vector.h
 *
 *  Created on: Mar 3, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_LISTLIB_VECTOR_VECTOR_H_
#define LLANYLIB_CORE_LISTLIB_VECTOR_VECTOR_H_

#include "../Corelist/List.h"
#include "../../Corelib/Libs/memlib.h"

namespace Llanylib {
namespace Listlib {
namespace Dynamiclist {

/*
 * Clase para controlar vectores simples-
 * */
template<class T>
class VectorLite : public Corelist::List<T> {
	protected:
		T* vector;
	public:
		VectorLite() : VectorLite(300) {}
		VectorLite(const len_t& length) : Countable(length) {
			this->vector = new T[this->length];
		}
		virtual ~VectorLite() { delete[] this->vector; }
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
					resultado = (*object == (this->vector + i));
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




template<class T>
class Vector : public Corelist::List<T> {
	protected:
		/*
		 * vector != nullptr
		 * if destructor == nullptr && free == true -> delete[] vector;
		 * if destructor == nullptr && free == false -> vector = nullptr;
		 * if destructor != nullptr && free == true -> destructor(&vector);
		 * if destructor != nullptr && free == false -> destructor(&vector);
		 * */
		T* vector;
		ll_bool_t free = false; // Marca si es necesario liberar la memoria contenida
		Destructor destructor;
		ll_bool_t modificable;
	public:
		// Si queremos generar un vector de tamaño n
		Vector(const len_t& length) : Corelist::List<T>() {
			this->vector = new T[this->length];
			this->free = true;
			this->destructor = nullptr;
			this->modificable = true;
		}
		// Si queremos controlar y guardar un vector creado externamente
		Vector(T* vector, const ll_bool_t& free, Destructor destructor) {
			this->vector = vector;
			this->free = free;
			this->destructor = destructor;
			// Es modificable si, se puede liberar de una manera u otra
			this->modificable = (this->free || this->destructor != nullptr);
		}

		/* Atajos */
		Vector() : Vector(300) {}
		Vector(T* vector) : Vector(vector, false, nullptr) {}
		Vector(T* vector, const ll_bool_t& free) : Vector(vector, free, nullptr) {}
		Vector(T* vector, Destructor destructor) : Vector(vector, true, destructor) {}

		virtual ~Vector() {
			// Si tenemos destructor, liberamos el vector
			if(this->destructor != nullptr) {
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

		// Funcion: Obtiene el puntero del objeto solicitado
		// Precondiciones:
		//		posicion < count
		// Retorno: El objeto solicitado
		//		Si la posicion es erronea devuelve nullptr
		// Complejidad temporal y espacial: O(?) y M(1)
		virtual T* get(const len_t& position) const override {
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
		virtual const T* cget(const len_t& position) const override {
			const T* result = nullptr;
			if(this->validPos(position))
				result = this->vector + position;
			return result;
		}
		virtual T* operator[](const len_t& position) override { return this->get(position); }


};


template<class T>
class Vector : public Corelist::List<T> {
	protected:
		T* vector;
		ll_bool_t free = false; // Marca si es necesario liberar la memoria contenida
	protected:
		Vector() : Corelist::List<T>() {
			this->free = false;
			this->vector = nullptr;
		}
		Vector(const len_t& length) : Corelist::List<T>(length) {
			this->free = true;
			this->vector = new T[length];
		}
		Vector(T* vector, const len_t& length) : Vector<T>(vector, length, true) {}
		Vector(T* vector, const len_t& length, const ll_bool_t& free) : Vector<T>() {
			this->free = free;
			this->vector = vector;
			this->length = length;
		}
		virtual ~Vector() { this->clear(); }
	public:
		# pragma region Funciones nuevas heredables
		virtual ll_bool_t setVector(T* vector, const len_t& length, const ll_bool_t& free) {
			ll_bool_t result = true;
			if(this->clear()) {
				this->free = free;
				this->vector = vector;
				this->length = length;
			}
			else result = false;
			return result;
		}
		virtual ll_bool_t setVector(T* vector, const len_t& length) {
			return this->setVector(vector, length, true);
		}
		virtual ll_bool_t set(const T& item, const len_t& pos) const {
			ll_bool_t result = true;
			if (this->validPos(pos))
				this->vector[pos] = item;
			else result = false;
			return result;
		}
		# pragma endregion
		#pragma region Funciones nuevas no heredables
		//-----------------------------
		#pragma endregion
		#pragma region Funciones heredadas
		virtual ll_bool_t clear() override {
			if (this->vector != nullptr && this->free)
				delete[] this->vector;
			this->vector = nullptr;
			return Corelist::List<T>::clear();
		}
		virtual T* get(const len_t& pos) const override {
			T* result = nullptr;
			if (this->validPos(pos))
				result = this->vector + pos;
			return result;
		}
		virtual const T* cget(const len_t& pos) const override {
			const T* result = nullptr;
			if (this->validPos(pos))
				result = this->vector + pos;
			return result;
		}
		virtual T* begin() const override { return this->vector; }
		virtual T* end() const override { return this->vector + this->length - 1; }
		virtual const T* cbegin() const override { return this->vector; }
		virtual const T* cend() const override { return this->vector + this->length - 1; }
		#pragma endregion
};

/*
template<class T>
class Vector : public Vector<T> {
	protected:
		T* vector;
	public:
		Vector(const len_t size) : Vector<T>(size) {}
		virtual ~Vector() {}
		# pragma region Funciones nuevas heredables
		# pragma endregion
		#pragma region Funciones nuevas no heredables
		#pragma endregion
		#pragma region Funciones heredadas
		#pragma endregion
};
*/
/*
template<class T>
class DynamicVector : public Corelist::List<T> {
	protected:
		T* vector;
		len_t maxSize;
	protected:
		len_t numPosAdd() const { return this->maxSize - this->length; }
		len_t canAddItem(const len_t& num) const { return (num + this->length) < this->maxSize; }
	public:
		DynamicVector(const len_t maxSize) : Corelist::List<T>() {
			this->maxSize = maxSize;
			this->vector = new T[maxSize];
		}
		~DynamicVector() { this->clear(); }

		virtual ll_bool_t clear() override {
			if (this->vector != nullptr) delete this->vector;
			this->vector = nullptr;
			this->maxSize = 0;
		}
		virtual T* get(const len_t& pos) const override {
			T* result = nullptr;
			if (this->validPos(pos))
				result = &this->vector[pos];
			return result;
		}
		virtual const T* getConst(const len_t& pos) const override {
			const T* result = nullptr;
			if (this->validPos(pos))
				result = &this->vector[pos];
			return result;
		}
		virtual ll_bool_t remove(const len_t& pos) {
			return false;
		}

		// A�ade un elemento al final
		virtual ll_bool_t add(const T* item) {
			ll_bool_t result = true;
			if (item != nullptr && ) {



			}
			else
				result = false;
			return result;
		}
		virtual ll_bool_t insert(const T* item, const len_t& position) {
			ll_bool_t result = true;
			if (item != nullptr && this->validPos(position)) {

			}
			else
				result = false;
			return result;
		}
};
*/


} /* namespace Dynamiclist */
} /* namespace Listlib */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_LISTLIB_VECTOR_VECTOR_H_ */
