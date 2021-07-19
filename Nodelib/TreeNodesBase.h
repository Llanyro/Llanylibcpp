/*
 * TreeNodesBase.h
 *
 *  Created on: Jul 15, 2021
 *      Author: llanyro
 */

#ifndef NODELIB_TREENODESBASE_H_
#define NODELIB_TREENODESBASE_H_

namespace Llanylib {
namespace Nodelib {
namespace TreeNodes {

template<class NODE>
class NodeGen {
	public:
		NODE* parent;	//
		NODE* left;		//
		NODE* right;	// He
	public:
		NodeGen() {
			this->left = nullptr;
			this->right = nullptr;
		}
		NodeGen(NODE* left, NODE* right) {
			this->left = left;
			this->right = right;
		}
		virtual ~NodeGen() {
			this->left = nullptr;
			this->right = nullptr;
		}
};

template<class NODE>
class Node {
	public:
		NODE* left;
		NODE* right;
	public:
		NodeSimple() {
			this->left = nullptr;
			this->right = nullptr;
		}
		NodeSimple(NODE* left, NODE* right) {
			this->left = left;
			this->right = right;
		}
		virtual ~NodeSimple() {
			this->left = nullptr;
			this->right = nullptr;
		}
};



} /* namespace TreeNodes */
} /* namespace Nodelib */
} /* namespace Llanylib */

#endif /* NODELIB_TREENODESBASE_H_ */
