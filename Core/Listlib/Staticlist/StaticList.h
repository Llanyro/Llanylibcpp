/*
 * Staticlist.h
 *
 *  Created on: Feb 21, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_LISTLIB_STATICLIST_STATICVECTOR_H_
#define LLANYLIB_CORE_LISTLIB_STATICLIST_STATICVECTOR_H_

#include "../Corelist/List.h"

namespace Llanylib {
namespace Listlib {
namespace Staticlist {

template<class T, const len_t size>
class Staticlist : public Corelist::List<T> {
	protected:
		T vector[size];
	public:
		Staticlist() : Corelist::List<T>() { this->length = size; }
		virtual ~Staticlist() {}
		#pragma region Funciones nuevas heredables
		// Funcion: Sustituye el objeto antiguo por uno nuevo
		// Version: Final
		// Precondiciones:
		//		pos < length
		// Retorno:
		//		 true: Si se ha seteado todo correctamente
		//		false: Si no se ha podido setear todo correctamente
		// Complejidad temporal y espacial: O(1) y M(1)
		virtual ll_bool_t set(const T& item, const len_t& pos) {
			ll_bool_t result = true;
			if (this->validPos(pos))
				this->vector[pos] = item;
			else result = false;
			return result;
		}
		#pragma endregion
		#pragma region Funciones nuevas no heredables
		// ------------------------------------
		#pragma endregion
		#pragma region Funciones heredadas
		// Funcion: Obtiene el puntero del objeto solicitado
		// Precondiciones:
		//		posicion < count
		// Retorno: El objeto solicitado
		//		Si la posicion es erronea devuelve nullptr
		// Complejidad temporal y espacial: O(1) y M(1)
		virtual T* get(const len_t& pos) const override {
			T* item = nullptr;
			if(this->validPos(pos))
				item = (T*)(this->vector + pos);
			return item;
		}
		// Funcion: Obtiene el puntero del objeto solicitado en formato const
		// Precondiciones:
		//		posicion < count
		// Retorno: El objeto solicitado
		//		Si la posicion es erronea devuelve nullptr
		// Complejidad temporal y espacial: O(1) y M(1)
		virtual const T* cget(const len_t& pos) const override {
			const T* item = nullptr;
			if (this->validPos(pos))
				item = this->vector + pos;
			return item;
		}
		virtual T* operator[](const len_t& pos) {
			return
					this->validPos(pos)
					? this->vector + pos
							: this->vector + this->length - 1;
		}
		#pragma endregion
};

} /* namespace Staticlist */
} /* namespace Listlib */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_LISTLIB_STATICLIST_STATICVECTOR_H_ */
