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
		SmartLinkedlist() : LinkedlistPre<T, Nodes::NDUSO<T>>() {}
		virtual ~SmartLinkedlist() {}

		virtual void add(T* object) {
			// Creamos el nodo
			Nodes::NDUSO<T>* nuevoNodo = new Nodes::NDUSO<T>(object, MEM_LIB::__delete__);
			//Nodes::NDUSO<T>* nuevoNodo = new Nodes::NDUSO<T>();
			//nuevoNodo->setSmart_0(object, MEM_LIB::__delete__);

			// Caso especial de que la lista este vacia
			if (this->length == 0) {
				this->raiz = nuevoNodo;
				nuevoNodo->setSiguienteNodo(nuevoNodo);
				nuevoNodo->setAnteriorNodo(nuevoNodo);
			}
			// Añadirmos al final
			else {
				// Guardamos los Nodes que vamos a modificar
				Nodes::NDUSO<T>* anteriorNodo = this->getNodoCache(this->length - 1);
				Nodes::NDUSO<T>* siguienteNodo = anteriorNodo->getSiguienteNodo();

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
		virtual ll_bool_t set(T* object, const len_t& position) {
			ll_bool_t result = true;
			if(this->validPos(position))
				this->getNodoCache(position)->
						setSmart_0(object, MEM_LIB::__delete__);
			else result = false;
			return result;
		}

};

} /* namespace Linkedlist */
} /* namespace Listlib */
} /* namespace Llanylib */

#endif /* LISTLIB_LINKEDLISTS_SMARTLINKEDLIST_H_ */
