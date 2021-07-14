/*
 * ListNodes.h
 *
 *  Created on: Jul 14, 2021
 *      Author: llanyro
 */

#ifndef NODELIB_LISTNODES_H_
#define NODELIB_LISTNODES_H_

#include "Nodes.h"
#include "../Containerlib/Containers.h"

#define LIST_NODES Llanylib::Nodelib::ListNodes

namespace Llanylib {
namespace Nodelib {
namespace ListNodes {

template<class T>
class NodeSimple :
		public Nodes::NodeSimple<NodeSimple<T>>,
		public CONTAINERS::Container<T> {
	public:
		NodeSimple() :
			Nodes::NodeSimple<NodeSimple<T>>(this),
			CONTAINERS::Container<T>() {}
		NodeSimple(const T& object_0, NodeSimple* nextNode) :
			Nodes::NodeSimple<NodeSimple<T>>(nextNode),
			CONTAINERS::Container<T>(object_0) {}
		NodeSimple(const T& object_0) :
			Nodes::NodeSimple<NodeSimple<T>>(this),
			CONTAINERS::Container<T>(object_0) {}
		NodeSimple(NodeSimple* nextNode) :
			Nodes::NodeSimple<NodeSimple<T>>(nextNode),
			CONTAINERS::Container<T>() {}
		virtual ~NodeSimple() {}
};

template<class T>
class NodeDouble :
		public Nodes::NodeDouble<NodeDouble<T>>,
		public Containerlib::Containers::Container<T> {
	public:
		NodeDouble() :
			Nodes::NodeDouble<NodeDouble<T>>(this, this),
			CONTAINERS::Container<T>() {}
		NodeDouble(const T& object_0, NodeDouble* nextNode, NodeDouble* prevNode) :
			Nodes::NodeDouble<NodeDouble<T>>(nextNode, prevNode),
			CONTAINERS::Container<T>(object_0) {}
		NodeDouble(const T& object_0) :
			Nodes::NodeDouble<NodeDouble<T>>(this, this),
			CONTAINERS::Container<T>(object_0) {}
		NodeDouble(NodeDouble* nextNode, NodeDouble* prevNode) :
			Nodes::NodeDouble<NodeDouble<T>>(nextNode, prevNode),
			CONTAINERS::Container<T>() {}
		virtual ~NodeDouble() {}
};

} /* namespace ListNodes */
} /* namespace Nodelib */
} /* namespace Llanylib */

#endif /* NODELIB_LISTNODES_H_ */
