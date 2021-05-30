/*
 * LinkedlistClassic.h
 *
 *  Created on: Apr 25, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_LISTLIB_LINKEDLIST_LINKEDLISTCLASSIC_H_
#define LLANYLIB_CORE_LISTLIB_LINKEDLIST_LINKEDLISTCLASSIC_H_

#include "LinkedList.h"
#include "../Nodes/NodeDouble.h"

#define LLANY_LINKED_LIST Llanylib::Core::Listlib::LinkedList

namespace Llanylib {
namespace Listlib {
namespace LinkedList {

template<class T>
class LinkedlistClassic : public Linkedlist<T, Nodes::NDUO<T>> {
	public:
		LinkedlistClassic() : Linkedlist<T, Classes::Nodes::NDUO<T>>() {}
		virtual ~LinkedlistClassic() {}
};

} /* namespace Linkedlist */
} /* namespace Listlib */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_LISTLIB_LINKEDLIST_LINKEDLISTCLASSIC_H_ */
