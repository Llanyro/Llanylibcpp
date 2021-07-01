#pragma once

#include "../Corelib/Libs/llanytypeslib.h"
#include "Node.h"

template<class T>
class Iterator {
	protected:
		NodeSimple<T>* node;
	public:
		Iterator(NodeSimple<T>* node) { this->node = node; }
		virtual ~Iterator() { this->node = nullptr; }
		T* getObject(const int& object) const { return &this->node->object_0; }
		NodeSimple<T>* getNode() const { return this->node; }
		ll_bool_t advance(const len_t& num) {
			ll_bool_t result = true;
			if (this->node != nullptr)
				for (len_t i = 0; i < num; i++)
					this->node = this->node->nextNode;
			else result = false;
			return result;
		}
};

template<class T>
class IteratorDouble {
	protected:
		NodeDouble<T>* node;
	public:
		IteratorDouble(NodeDouble<T>* node) { this->node = node; }
		virtual ~IteratorDouble() { this->node = nullptr; }
		T* getObject(const int& object) const { return &this->node->object_0; }
		NodeDouble<T>* getNode() const { return this->node; }
		ll_bool_t advance(const len_t& num) {
			ll_bool_t result = true;
			if (this->node != nullptr)
				for (len_t i = 0; i < num; i++)
					this->node = this->node->nextNode;
			else result = false;
			return result;
		}
		ll_bool_t advanceReverse(const len_t& num) {
			ll_bool_t result = true;
			if (this->node != nullptr)
				for (len_t i = 0; i < num; i++)
					this->node = this->node->prevNode;
			else result = false;
			return result;
		}
};
