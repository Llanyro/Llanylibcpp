/*
 * Vector.h
 *
 *  Created on: Mar 3, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_LISTLIB_VECTOR_VECTOR_H_
#define LLANYLIB_CORE_LISTLIB_VECTOR_VECTOR_H_

#include "../Corelist/List.h"

namespace Llanylib {
namespace Listlib {
namespace Dynamiclist {

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
		Vector(T* vector, const len_t& length, const ll_bool_t& free) : Vector<T>() {
			this->setVector(vector, length, free);
		}
		virtual ~Vector() { this->clear(); }
	public:
		# pragma region Funciones nuevas heredables
		virtual ll_bool_t setVector(T* vector, const len_t& length, const ll_bool_t& free) {
			this->clear();
			this->free = free;
			this->vector = vector;
			this->length = length;
			return true;
		}
		virtual ll_bool_t set(T* item, const len_t& pos) const {
			ll_bool_t result = true;
			if (this->validPos(pos))
				this->vector[pos] = *item;
			else result = false;
			return result;
		}
		# pragma endregion
		#pragma region Funciones nuevas no heredables
		//-----------------------------
		#pragma endregion
		#pragma region Funciones heredadas
		virtual ll_bool_t clear() override {
			if (this->vector != nullptr && this->free) delete this->vector;
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
		virtual T* end() const override { return this->vector + this->length; }
		virtual const T* cbegin() const override { return this->vector; }
		virtual const T* cend() const override { return this->vector + this->length; }
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
