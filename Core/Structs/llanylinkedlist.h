/*
 * simplelist.h
 *
 *  Created on: Feb 8, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_STRUCTS_SIMPLELIST_H_
#define LLANYLIB_CORE_STRUCTS_SIMPLELIST_H_

#include "basicstructs.h"

namespace Llanylib {
namespace Core {
namespace Structs {

template<class T>
struct llanyNode : llanyContainer<T> { llanyNode<T>* next = nullptr; };
template<class T>
struct llanyList : llanyLen {
	Destructor destructor;
	llanyNode<T>* raiz = nullptr;
};

// Constructors
template<class T>
llanyList<T>* newlist(Destructor destructor) {
	llanyList<T>* list = new llanyList<T>();
	list->length = 0;
	list->raiz = nullptr;
	list->destructor = destructor;
	return list;
}
template<class T>
llanyList<T>* newlist() { return newlist<T>(nullptr); }
template<class T>
void removenoderecursive(llanyNode<T>* n, Destructor destructor) {
	if (n->next != nullptr) removenoderecursive(n->next, destructor);
	//if(destructor != nullptr) delete n->item_0;
	delete n;
}
template<class T>
void removelist(llanyList<T>** list) {
	if ((*list)->raiz != nullptr)
		removenoderecursive<T>((*list)->raiz, (*list)->destructor);
	(*list)->length = 0;
	delete *list;
	list = nullptr;
}

// Getters && Setters
template<class T>
llanyNode<T>* getNode(const llanyList<T>* l, const len_t& pos) {
	llanyNode<T>* n = nullptr;
	if (pos < l->length) {
		n = l->raiz;
		for (len_t i = 0; i < pos; i++)
			n = n->next;
	}
	return n;
}
template<class T>
T* getValue(const llanyList<T>* l, const len_t& pos) {
	T* result = nullptr;
	if (pos < l->length)
		result = &getNode(l, pos)->item_0;
	return result;
}
template<class T>
void add(llanyList<T>* l, const T& item) {
	llanyNode<T>* n = new llanyNode<T>();
	n->item_0 = item;

	if (l->length == 0)
		l->raiz = n;
	else {
		llanyNode<T>* anterior = getNode(l, l->length - 1);
		anterior->next = n;
	}
	l->length++;
}
template<class T>
ll_bool_t set(const llanyList<T>* l, const len_t& pos, const T& item) {
	ll_bool_t result = true;
	if(pos < l->len)
		getNode(l, pos)->item_0 = item;
	else result = false;
	return result;
}
template<class T>
ll_bool_t contains(const llanyList<T>* l, const T* item) {
	ll_bool_t result = false, continuar = true;
	llanyNode<T>* n = l->raiz;
	while (continuar) {
		if (n == nullptr) continuar = false;
		else if (n->item_0 == *item) {
			continuar = false;
			result = true;
		}
		else n = n->next;
	}
	return result;
}

} /* namespace Structs */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_STRUCTS_SIMPLELIST_H_ */
