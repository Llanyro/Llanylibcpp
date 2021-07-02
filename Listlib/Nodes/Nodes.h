/*
 * Nodes.h
 *
 *  Created on: Jan 19, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_CLASSES_NODES_NODES_H_
#define LLANYLIB_CORE_CLASSES_NODES_NODES_H_

/*#include "../../Classes/LlanyCore.h"

namespace Llanylib {
namespace Listlib {
namespace Nodes {

template<class T, const len_t numNodes>
class Node : public Core::Classes::LlanyCore {
	protected:
		T** vector;
	public:
		Node() : LlanyCore() {
			this->vector = new T*[numNodes];
			for (len_t i = 0; i < numNodes; ++i) this->vector[i] = nullptr;
		}
		virtual ~Node() {
			for (len_t i = 0; i < numNodes; ++i) this->vector[i] = nullptr;
			delete[] this->vector;
		}
		T* get(const len_t& position) {
			T* result = nullptr;
			if(position < numNodes)
				result = this->vector[position];
			return result;
		}
		const T* getConst(const len_t& position) const {
			const T* result = nullptr;
			if(position < numNodes)
				result = this->vector[position];
			return result;
		}
		ll_bool_t set(T* node, const len_t& position) {
			ll_bool_t result = true;
			if(position < numNodes)
				this->vector[position] = node;
			else result = false;
			return result;
		}
		//virtual void deleteRecursivo(const void* first) {}
};

template<class T>
class NodeDouble : protected Node<T, 2> {
	public:
		NodeDouble() : Node<T, 2>() {}
		virtual ~NodeDouble() {}
		T* getSiguienteNodo() { return Node<T, 2>::get(0); }
		const T* getConstSiguienteNodo() const { return Node<T, 2>::getConst(0); }
		ll_bool_t setSiguienteNodo(T* node) { return Node<T, 2>::set(node, 0); }
		T* getAnteriorNodo() { return Node<T, 2>::get(1); }
		const T* getConstAnteriorNodo() const { return Node<T, 2>::getConst(1); }
		ll_bool_t setAnteriorNodo(T* node) { return Node<T, 2>::set(node, 1); }
		/*virtual void deleteRecursivo(const NodeDouble<T>* first) {
			// Si no hay primero, este nodo es el primero
			// Si hay siguiente nodo
			if(first == nullptr && this->getSiguienteNodo() != nullptr) {
				// Si el siguiente nodo no es este nodo
				if(this->getSiguienteNodo() != this)
					this->getSiguienteNodo()->deleteRecursivo(this);
				// Si es el mismo nodo, no hacemos nada
			}
			else {
				// Si hay siguiente nodo y no es el primero
				if(this->getSiguienteNodo() != nullptr && this->getSiguienteNodo() != first)
					this->getSiguienteNodo()->deleteRecursivo(first);
			}
			delete this;
		}*
};

template<class T>
class NodeAVL : protected Node<T, 3> {
	public:
		NodeAVL() : Node<T, 3>() {}
		virtual ~NodeAVL() {}

		T* getParent() { return Node<T, 3>::get(0); }
		const T* getConstParent() const { return Node<T, 3>::getConst(0); }
		ll_bool_t setParent(T* node) { return Node<T, 3>::set(node, 0); }

		T* getLeftChild() { return Node<T, 3>::get(1); }
		const T* getConstLeftChild() const { return Node<T, 3>::get(1); }
		ll_bool_t setLeftChild(T* node) { return Node<T, 3>::set(node, 1); }

		T* getRightChild() { return Node<T, 3>::get(2); }
		const T* getConstRightChild() const { return Node<T, 3>::get(2); }
		ll_bool_t setRightChild(T* node) { return Node<T, 3>::set(node, 2); }
};*/

} /* namespace Nodes */
} /* namespace Listlib */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_CLASSES_NODES_NODES_H_ */
