/*
 * SmartNodeDouble.h
 *
 *  Created on: Jan 21, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_CLASSES_NODES_SMARTNODEDOUBLE_H_
#define LLANYLIB_CORE_CLASSES_NODES_SMARTNODEDOUBLE_H_

#include "Nodes.h"
#include "../Containers/SmartContainers.h"

namespace Llanylib {
namespace Listlib {
namespace Nodes {

// Nodo doble con un smart objeto (SmartContainer)
template<class T>
class NDUSO : public NodeDouble<NDUSO<T>>, Core::Classes::Containers::SmartContainer<T> {
	public:
		NDUSO() : NodeDouble<NDUSO>(), Containers::Container<T>() {}
		NDUSO(const T& item_0) : NodeDouble<NDUSO>(), Containers::Container<T>(item_0) {}
		virtual ~NDUSO() {}
};

// Nodo doble con dos smart objetos (SmartContainerDouble)
template<class T0, class T1>
class NDDSO : public NodeDouble<NDDSO<T0, T1>>, Core::Classes::Containers::SmartContainerDouble<T0, T1> {
	public:
		NDDSO() : NodeDouble<NDDSO<T0, T1>>(), Containers::ContainerDouble<T0, T1>() {}
		NDDSO(const T0& item_0, const T1& item_1) : NodeDouble<NDDSO<T0, T1>>(), Containers::ContainerDouble<T0, T1>(item_1, item_1) {}
		virtual ~NDDSO() {}
};

} /* namespace Nodes */
} /* namespace Listlib */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_CLASSES_NODES_SMARTNODEDOUBLE_H_ */
