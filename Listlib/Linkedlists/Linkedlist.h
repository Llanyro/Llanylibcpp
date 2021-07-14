/*
 * Linkedlist.h
 *
 *  Created on: Jul 14, 2021
 *      Author: llanyro
 */

#ifndef LISTLIB_LINKEDLISTS_LINKEDLIST_H_
#define LISTLIB_LINKEDLISTS_LINKEDLIST_H_

#include "AbstractLinkedlist.h"
#include "../../Nodelib/ListNodes.h"

namespace Llanylib {
namespace Listlib {
namespace Linkedlists {

template<class T>
class Linkedlist : public AbstractLinkedlist<T, LIST_NODES::NodeDouble<T>> {
	public:
		Linkedlist() : AbstractLinkedlist<T, LIST_NODES::NodeDouble<T>>() {}
		virtual ~Linkedlist() {}
		virtual void add(const T& object) {
			// Creamos el nodo y lo añadimos
			this->addNode(new LIST_NODES::NodeDouble<T>(object));
		}
		virtual ll_bool_t set(const T& object, const len_t& position) {
			ll_bool_t result = true;
			if(this->validPos(position))
				this->getNodoCache(position)->object_0 = object;
			else result = false;
			return result;
		}
};

} /* namespace Linkedlists */
} /* namespace Listlib */
} /* namespace Llanylib */

#endif /* LISTLIB_LINKEDLISTS_LINKEDLIST_H_ */
