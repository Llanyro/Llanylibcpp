/*
 * ListNodesBase.h
 *
 *  Created on: Jul 15, 2021
 *      Author: llanyro
 */

#ifndef NODELIB_LISTNODESBASE_H_
#define NODELIB_LISTNODESBASE_H_

namespace Llanylib {
namespace Nodelib {
namespace ListNodes {

template<class NODE>
class NodeSimple {
	public:
		NODE* nextNode;
	public:
		NodeSimple() { this->nextNode = nullptr; }
		NodeSimple(NODE* nextNode) { this->nextNode = nextNode; }
		virtual ~NodeSimple() { this->nextNode = nullptr; }
};

template<class NODE>
class NodeDouble : public NodeSimple<NODE>{
	public:
		NODE* prevNode;
	public:
		NodeDouble() {
			this->nextNode = nullptr;
			this->prevNode = nullptr;
		}
		NodeDouble(NODE* nextNode, NODE* prevNode) {
			this->nextNode = nextNode;
			this->prevNode = prevNode;
		}
		virtual ~NodeDouble() {
			this->nextNode = nullptr;
			this->prevNode = nullptr;
		}
};

} /* namespace ListNodes */
} /* namespace Nodelib */
} /* namespace Llanylib */

#endif /* NODELIB_LISTNODESBASE_H_ */
