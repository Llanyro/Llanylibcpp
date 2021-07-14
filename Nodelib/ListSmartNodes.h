/*
 * ListSmartNodes.h
 *
 *  Created on: Jul 14, 2021
 *      Author: llanyro
 */

#ifndef NODELIB_LISTSMARTNODES_H_
#define NODELIB_LISTSMARTNODES_H_

#include "Nodes.h"
#include "../Containerlib/SmartContainers.h"

#define LIST_SMART_NODES Llanylib::Nodelib::ListSmartNodes

namespace Llanylib {
namespace Nodelib {
namespace ListSmartNodes {

template<class T>
class NodeSimple :
		public Nodes::NodeSimple<NodeSimple<T>>,
		public SMART_CONTAINERS::SmartContainer<T> {
	public:
		NodeSimple() :
			Nodes::NodeSimple<NodeSimple<T>>(this),
			SMART_CONTAINERS::SmartContainer<T>() {}
		NodeSimple(T* object_0, Destructor destructor_0, NodeSimple* nextNode) :
			Nodes::NodeSimple<NodeSimple<T>>(nextNode),
			SMART_CONTAINERS::SmartContainer<T>(object_0, destructor_0) {}
		NodeSimple(T* object_0, Destructor destructor_0) :
			Nodes::NodeSimple<NodeSimple<T>>(this),
			SMART_CONTAINERS::SmartContainer<T>(object_0, destructor_0) {}
		NodeSimple(NodeSimple* nextNode) :
			Nodes::NodeSimple<NodeSimple<T>>(nextNode),
			SMART_CONTAINERS::SmartContainer<T>() {}
		virtual ~NodeSimple() {}
};

template<class T>
class NodeDouble :
		public Nodes::NodeDouble<NodeDouble<T>>,
		public SMART_CONTAINERS::SmartContainer<T> {
	public:
		NodeDouble() :
			Nodes::NodeDouble<NodeDouble<T>>(this, this),
			SMART_CONTAINERS::SmartContainer<T>() {}
		NodeDouble(T* object_0, Destructor destructor_0, NodeDouble* nextNode, NodeDouble* prevNode) :
			Nodes::NodeDouble<NodeDouble<T>>(nextNode, prevNode),
			SMART_CONTAINERS::SmartContainer<T>(object_0, destructor_0) {}
		NodeDouble(T* object_0, Destructor destructor_0) :
			Nodes::NodeDouble<NodeDouble<T>>(this, this),
			SMART_CONTAINERS::SmartContainer<T>(object_0, destructor_0) {}
		NodeDouble(T* object_0, NodeDouble* nextNode, NodeDouble* prevNode) :
			Nodes::NodeDouble<NodeDouble<T>>(nextNode, prevNode),
			SMART_CONTAINERS::SmartContainer<T>(object_0) {}
		NodeDouble(T* object_0) :
			Nodes::NodeDouble<NodeDouble<T>>(this, this),
			SMART_CONTAINERS::SmartContainer<T>(object_0) {}
		NodeDouble(NodeDouble* nextNode, NodeDouble* prevNode) :
			Nodes::NodeDouble<NodeDouble<T>>(nextNode, prevNode),
			SMART_CONTAINERS::SmartContainer<T>() {}
		virtual ~NodeDouble() {}
};
} /* namespace Nodes */
} /* namespace Nodelib */
} /* namespace Llanylib */

#endif /* NODELIB_LISTSMARTNODES_H_ */