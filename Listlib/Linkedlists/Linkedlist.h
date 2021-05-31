/*
 * Linkedlist.h
 *
 *  Created on: Mar 11, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_LISTLIB_LINKEDLIST_LINKEDLIST_H_
#define LLANYLIB_CORE_LISTLIB_LINKEDLIST_LINKEDLIST_H_

#include "../Linkedlists/LinkedlistPre.h"
#include "../Nodes/NodeDouble.h"

namespace Llanylib {
namespace Listlib {
namespace Linkedlists {

template<class T>
class Linkedlist : public LinkedlistPre<T, Nodes::NDUO<T>> {
	public:
		Linkedlist() : LinkedlistPre<T, Nodes::NDUO<T>>() {}
		virtual ~Linkedlist() {}

		virtual void add(const T& object) {
			// Creamos el nodo
			T_NODE* nuevoNodo = new T_NODE(object);
			// Caso especial de que la lista este vacia
			if (this->length == 0) {
				this->raiz = nuevoNodo;
				nuevoNodo->setSiguienteNodo(nuevoNodo);
				nuevoNodo->setAnteriorNodo(nuevoNodo);
			}
			// Añadirmos al final
			else {
				// Guardamos los Nodes que vamos a modificar
				T_NODE* anteriorNodo = this->getNodoCache(this->length - 1);
				T_NODE* siguienteNodo = anteriorNodo->getSiguienteNodo();

				// Apuntamos correctamente el nodo entre los otros Nodes
				nuevoNodo->setSiguienteNodo(siguienteNodo);
				nuevoNodo->setAnteriorNodo(anteriorNodo);
				// Hacemos que los otros Nodes apunten al nuevo
				anteriorNodo->setSiguienteNodo(nuevoNodo);
				siguienteNodo->setAnteriorNodo(nuevoNodo);
			}
			// Incrementamos el tama�o
			this->length++;
		}
		virtual ll_bool_t set(const T& object, const lent_t& position) {
			ll_bool_t result = true;
			T_NODE* nodo = this->getNodoCache(position);
			if(nodo != nullptr) nodo->set_0(object);
			else result = false;
			return result;
		}

};

} /* namespace Linkedlist */
} /* namespace Listlib */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_LISTLIB_LINKEDLIST_LINKEDLIST_H_ */
