/*
 * Basic.h
 *
 *  Created on: Jan 19, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORELIBLIB_STRUCTS_BASIC_H_
#define LLANYLIB_CORELIBLIB_STRUCTS_BASIC_H_

#include "../Libs/llanytypeslib.h"

#define SIMPLE_STRUCTS Llanylib::Core::Structs
#define BASIC_STRUCTS Llanylib::Core::Structs

namespace Llanylib {
namespace Corelib {
namespace Structs {

template<class T>
struct _container{
	T __object_0 = T();
};

template<class T0, class T1>
struct llanyContainerDouble : llanyContainer<T0> {
	T1 item_1 = T1();
};

template<class T, class T1>
struct cachelist {
	T cache = T();
	T1 position = T1();
};

} /* namespace Structs */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORELIBLIB_STRUCTS_BASIC_H_ */
