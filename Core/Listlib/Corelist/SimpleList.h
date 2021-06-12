/*
 * Simplelist.h
 *
 *  Created on: Feb 20, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_LISTLIB_CORELIST_SIMPLELIST_H_
#define LLANYLIB_CORE_LISTLIB_CORELIST_SIMPLELIST_H_

#include "../../Core/Classes/LlanyCore.h"

// Contiene todas las funciones generales de las listas
// Pero no contiene el size

namespace Llanylib {
namespace Listlib {
namespace Corelist {

template<class T>
class Simplelist : public Core::Classes::LlanyCore {
	protected:
		Simplelist() : LlanyCore() {}
		virtual ~Simplelist() {}
	public:
		#pragma region Funciones nuevas heredables
		/*
		 * Las funciones 'get' permiten extraer un puntero de un objeto sin modificar la lista en si
		 * Tenemos 2 funciones diferentes, para evitar que en ciertos casos se modifique el contenido del objeto a extraer
		 *
		 * La funcion de remove() elimina el objeto si esta indicado y del llama a remove()
		 * */

		virtual T* begin() const { return nullptr; }
		virtual T* end() const { return nullptr; }
		virtual const T* cbegin() const { return nullptr; }
		virtual const T* cend() const { return nullptr; }
		// Funcion: Obtiene el puntero del objeto solicitado
		// Precondiciones:
		//		posicion < count
		// Retorno: El objeto solicitado
		//		Si la posicion es erronea devuelve nullptr
		// Complejidad temporal y espacial: O(?) y M(1)
		virtual T* get(const len_t& pos) const { return nullptr; }
		// Funcion: Obtiene el puntero del objeto solicitado en formato const
		// Precondiciones:
		//		posicion < count
		// Retorno: El objeto solicitado
		//		Si la posicion es erronea devuelve nullptr
		// Complejidad temporal y espacial: O(?) y M(1)
		virtual const T* cget(const len_t& pos) const { return nullptr; }
		virtual T* operator[](const len_t& pos) { return nullptr; }
		virtual ll_bool_t contains(const T* item, Compare_bool compare) const { return false; }
		virtual ll_bool_t swap(const len_t& posObject1, const len_t& posObject2) { return false; }
		#pragma endregion
		#pragma region Funciones nuevas no heredables
		// Funcion:Por defector llama a contains()_
		ll_bool_t contains(const T* item) const { return this->contains(item, nullptr); }
		#pragma endregion
		#pragma region Funciones heredadas
		#pragma endregion
};
/*
		 * Las funciones 'set' permiten camiar un objeto de la lista por otro
		 * Tenemos 2 funciones diferentes, ya que una solo sustituye el objeto
		 * 	y la otra elimina el antiguo y lo sustituye (smart)

		virtual ll_bool_t add(const T* item) { return false; }

		// Funcion: Sustituye el objeto antiguo por uno nuevo
		// Version: Final
		// Precondiciones:
		//		Ninguna
		// Retorno:
		//		 true: Si se ha seteado todo correctamente
		//		false: Si no se ha podido setear todo correctamente
		// Complejidad temporal y espacial: O(?) y M(1)
		virtual ll_bool_t set(T* item, const ll_bool_t& readOnly, const len_t& pos) { return false; }
		// Funcion: llama a set() con el parametro isFreeable = false
		ll_bool_t set(T* item, const len_t& pos) { return this->set(item, false, pos); }

		// Funcion: Sustituye el objeto antiguo por uno nuevo
		// Extra: Si se puede liberar el antiguo se libera
		// Version: Final
		// Precondiciones:
		//		Ninguna
		// Retorno: Void/Si se ha realizado todo correctamente
		//		Resultado
		// Complejidad temporal y espacial: O(1) y M(1)
		virtual ll_bool_t setSmart(T* item, const ll_bool_t& isFreeable, const len_t& pos) { return false; }
		// Funcion: Por defecto llama a setSmart() con el parametro isFreeable = false
		ll_bool_t setSmart(T* item, const len_t& pos) { return this->setSmart(item, false, pos); }
*/

} /* namespace Corelist */
} /* namespace Listlib */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_LISTLIB_CORELIST_SIMPLELIST_H_ */
