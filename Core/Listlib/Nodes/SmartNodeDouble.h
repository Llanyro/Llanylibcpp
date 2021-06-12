/*
 * SmartNodeDouble.h
 *
 *  Created on: Jan 21, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_CLASSES_NODES_SMARTNODEDOUBLE_H_
#define LLANYLIB_CORE_CLASSES_NODES_SMARTNODEDOUBLE_H_

#include "Nodes.h"
#include "../../Classes/Containers/SmartContainers.h"

namespace Llanylib {
namespace Listlib {
namespace Nodes {

// Nodo doble con un smart objeto (SmartContainer)
template<class T>
class NDUSO : public NodeDouble<NDUSO<T>>, public CONTAINER::SmartContainer<T> {
	public:
		NDUSO() : NodeDouble<NDUSO<T>>(), CONTAINER::SmartContainer<T>() {}
		NDUSO(T* item_0, Destructor destructor_0) : NodeDouble<NDUSO<T>>(),
			CONTAINER::SmartContainer<T>(item_0, destructor_0) {}
		virtual ~NDUSO() {}
};

// Nodo doble con dos smart objetos (SmartContainerDouble)
template<class T0, class T1>
class NDDSO : public NodeDouble<NDDSO<T0, T1>>, public CONTAINER::SmartContainerDouble<T0, T1> {
	public:
		NDDSO() : NodeDouble<NDDSO<T0, T1>>(), CONTAINER::SmartContainerDouble<T0, T1>() {}
		NDDSO(T0* item_0, Destructor destructor_0, T1* item_1, Destructor destructor_1) :
			NodeDouble<NDDSO<T0, T1>>(),
			CONTAINER::SmartContainerDouble<T0, T1>(item_0, destructor_0, item_1, destructor_1) {}
		virtual ~NDDSO() {}
};

} /* namespace Nodes */
} /* namespace Listlib */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_CLASSES_NODES_SMARTNODEDOUBLE_H_ */
