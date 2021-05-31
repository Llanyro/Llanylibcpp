/*
 * SmartLinkedlist.h
 *
 *  Created on: May 30, 2021
 *      Author: llanyro
 */

#ifndef LISTLIB_LINKEDLISTS_SMARTLINKEDLIST_H_
#define LISTLIB_LINKEDLISTS_SMARTLINKEDLIST_H_

#include "../../Core/Libs/memlib.h"

#include "../Linkedlists/LinkedlistPre.h"
#include "../Nodes/SmartNodeDouble.h"

namespace Llanylib {
namespace Listlib {
namespace Linkedlists {

template<class T>
class SmartLinkedlist : public LinkedlistPre<T, Nodes::NDUSO<T>> {
	public:
		SmartLinkedlist() : LinkedlistPre<T, Nodes::NDUO<T>>() {}
		virtual ~SmartLinkedlist() {}

		virtual void add(T* object) {
			// Creamos el nodo
			T_NODE* nuevoNodo = new T_NODE();
			nuevoNodo->setSmart_0(object, MEM_LIB::__delete__);
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
		virtual ll_bool_t set(T* object, const lent_t& position) {
			ll_bool_t result = true;
			T_NODE* nodo = this->getNodoCache(position);
			if(nodo != nullptr) nodo->setSmart_0(object, MEM_LIB::__delete__);
			else result = false;
			return result;
		}

};

} /* namespace Linkedlist */
} /* namespace Listlib */
} /* namespace Llanylib */

#endif /* LISTLIB_LINKEDLISTS_SMARTLINKEDLIST_H_ */
