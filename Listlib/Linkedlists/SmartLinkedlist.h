/*
 * SmartLinkedlist.h
 *
 *  Created on: May 30, 2021
 *      Author: llanyro
 */

#ifndef LISTLIB_LINKEDLISTS_SMARTLINKEDLIST_H_
#define LISTLIB_LINKEDLISTS_SMARTLINKEDLIST_H_

//#include "../Nodes/SmartNodeDouble.h"
//#include "AbstractLinkedlist.h"
//#include "../Corelist/AbstractSmartList.h"

namespace Llanylib {
namespace Listlib {
namespace Linkedlists {

/*template<class T>
class SmartLinkedlist : public AbstractLinkedlist<T, Nodes::NDUSO<T>>, public Corelist::AbstractSmartList<T> {
	public:
		SmartLinkedlist() : Corelist::AbstractSmartList<T>(), AbstractLinkedlist<T, Nodes::NDUSO<T>>() {}
		virtual ~SmartLinkedlist() {}
		virtual void addSmart(T* object, Destructor destructor) override {
			// Creamos el nodo
			Nodes::NDUSO<T>* nuevoNodo = new Nodes::NDUSO<T>(object, destructor);

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
		virtual ll_bool_t setSmart(T* object, Destructor destructor, const len_t& position, const ll_bool_t& smart) const override {
			ll_bool_t result = true;
			if(this->validPos(position)) {
				if(smart)
					this->getNodoCache(position)->setSmart_0(object, destructor);
				else
					this->getNodoCache(position)->set_0(object, destructor);
			}
			else result = false;
			return result;
		}
		virtual ll_bool_t removeSmart(const len_t& position, const ll_bool_t& smart) override {
			ll_bool_t result = false;

			// If smart is up -> then remove normally
			// If smart is down -> set node to not smart and delete it
			if(this->validPos(position)) {
				if(!smart)
					this->getNodoCache(position)->setDestructor_0(nullptr);
				result = AbstractLinkedlist<T, Nodes::NDUSO<T>>::remove(position);
			}
			return result;
		}
};*/

} /* namespace Linkedlist */
} /* namespace Listlib */
} /* namespace Llanylib */

#endif /* LISTLIB_LINKEDLISTS_SMARTLINKEDLIST_H_ */
