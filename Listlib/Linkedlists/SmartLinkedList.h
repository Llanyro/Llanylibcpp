/*
 * SmartLinkedList.h
 *
 *  Created on: Jul 14, 2021
 *      Author: llanyro
 */

#ifndef LISTLIB_LINKEDLISTS_SMARTLINKEDLIST_H_
#define LISTLIB_LINKEDLISTS_SMARTLINKEDLIST_H_

#include "AbstractLinkedlist.h"
#include "../../Nodelib/ListSmartNodes.h"

namespace Llanylib {
namespace Listlib {
namespace Linkedlists {

template<class T>
class SmartLinkedList : public AbstractLinkedlist<T, LIST_SMART_NODES::NodeDouble<T>>{
	public:
		SmartLinkedList() : AbstractLinkedlist<T, LIST_NODES::NodeDouble<T>>() {}
		virtual ~SmartLinkedList() {}
		virtual void add(T* object, Destructor destructor) {
			// Creamos el nodo y lo añadimos
			this->addNode(new LIST_SMART_NODES::NodeDouble<T>(object, destructor));
		}
		virtual ll_bool_t set(T* object, Destructor destructor, const len_t& position) {
			ll_bool_t result = true;
			if(this->validPos(position))
				this->getNodoCache(position)->setSmart_0(object, destructor);
			else result = false;
			return result;
		}
		virtual ll_bool_t setNoSmart(T* object, Destructor destructor, const len_t& position) {
			ll_bool_t result = true;
			if(this->validPos(position))
				this->getNodoCache(position)->set_0(object, destructor);
			else result = false;
			return result;
		}
		virtual T* extract(const len_t& position) {
			T* object = nullptr;
			if(this->validPos(position)) {
				LIST_SMART_NODES::NodeDouble<T>* node = this->getNodoCache(position);
				object = node->object_0;
				node->setDestructor_0(nullptr);
				this->remove(position);
			}
			return object;
		}
};

} /* namespace Linkedlists */
} /* namespace Listlib */
} /* namespace Llanylib */

#endif /* LISTLIB_LINKEDLISTS_SMARTLINKEDLIST_H_ */
