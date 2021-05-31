/*
 * List.h
 *
 *  Created on: Feb 20, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_LISTLIB_CORELIST_LIST_H_
#define LLANYLIB_CORE_LISTLIB_CORELIST_LIST_H_

#include "../../Core/Classes/Countable.h"
#include "SimpleList.h"

namespace Llanylib {
namespace Listlib {
namespace Corelist {

template<class T>
class List : public Simplelist<T>, public Core::Classes::Countable {
	protected:
		List() : Simplelist<T>(), Countable() {}
		List(const len_t& length) : Simplelist<T>(), Countable(length) {}
		virtual ~List() {}
	public:
		#pragma region Funciones nuevas heredables
		/*
		 * Puede que algun dia necesite algo extra
		 * */
		// Funcion: Comprueba si la posicion dada se puede encontrar en la lista
		// Version: Final
		// Precondiciones:
		//		Ninguna
		// Retorno:
		//		 true: Si la posicion dada esta en la lista
		//		false: Si la posicion dada no esta en la lista
		// Complejidad temporal y espacial: O(1) y M(1)
		virtual ll_bool_t validPos(const len_t& pos) const { return pos < this->length; }
		// Funcion: Nos dice si una lista incrementa el maximo al llegar a este u otra condicion
		// Version: Final
		// Precondiciones:
		//		Ninguna
		// Retorno:
		//		 true: Si la lista cambia de tama�o
		//		false: Si la lista mantiene su tama�o con el tiempo
		// Complejidad temporal y espacial: O(1) y M(1)
		virtual ll_bool_t autoRealloc() const { return false; }
		virtual ll_bool_t clear() override {
			this->length = 0;
			return true;
		}
		#pragma endregion
		#pragma region Funciones nuevas no heredables
		
		#pragma endregion
		#pragma region Funciones heredadas

		#pragma endregion
};

} /* namespace Corelist */
} /* namespace Listlib */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_LISTLIB_CORELIST_LIST_H_ */
