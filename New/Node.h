#pragma once


#ifndef N_H
#define N_H

#include "Container.h"


template<class T>
class NodeSimple : public Container<T> {
	public:
		NodeSimple* nextNode;
	public:
		NodeSimple() : Container<T>() { this->nextNode = this; }
		NodeSimple(const T& object_0) : Container<T>(object_0) { this->nextNode = this; }
		virtual ~NodeSimple() { this->nextNode = nullptr; }
};

template<class T>
class NodeDouble : public Container<T> {
	public:
		NodeDouble* nextNode;
		NodeDouble* prevNode;
	public:
		NodeDouble() : Container<T>() {
			this->nextNode = this;
			this->prevNode = this;
		}
		NodeDouble(const T& object_0) : Container<T>(object_0) {
			this->nextNode = this;
			this->prevNode = this;
		}
		virtual ~NodeDouble() {
			this->nextNode = nullptr;
			this->prevNode = nullptr;
		}
};

#endif /* N_H */
