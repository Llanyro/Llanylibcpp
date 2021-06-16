/*
 * Basic.h
 *
 *  Created on: Jan 19, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_STRUCTS_BASIC_H_
#define LLANYLIB_CORE_STRUCTS_BASIC_H_

#include "../Libs/llanytypeslib.h"

#define SIMPLE_STRUCTS Llanylib::Core::Structs
#define BASIC_STRUCTS Llanylib::Core::Structs

namespace Llanylib {
namespace Core {
namespace Structs {

// Struct para los objetos que sean contables
struct llanyLen { len_t length = 0; };

//template<class T, const len_t numReturns>
//struct llanyStaticVector { T vector[numReturns]; };

template<class T>
struct llanyContainer { T item_0 = T(); };

template<class T0, class T1>
struct llanyContainerDouble : llanyContainer<T0> { T1 item_1 = T1(); };

template<class T, class T1>
struct cachelist {
	T cache = T();
	T1 position = T1();
};

template<class T>
struct NodeDoble {
	T item = T();
	NodeDoble<T>* siguiente = nullptr;
	NodeDoble<T>* anterior = nullptr;
};


} /* namespace Structs */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_STRUCTS_BASIC_H_ */
