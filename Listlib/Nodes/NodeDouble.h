/*
 * NodeDouble.h
 *
 *  Created on: Dec 13, 2020
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_CLASSES_NODES_NODEDOUBLE_H_
#define LLANYLIB_CORE_CLASSES_NODES_NODEDOUBLE_H_

#include "Nodes.h"
#include "../../Core/Classes/Containers/Containers.h"

namespace Llanylib {
namespace Listlib {
namespace Nodes {

// Nodo doble con un objeto (Container)
template<class T>
class NDUO : public NodeDouble<NDUO<T>>, public CONTAINER::Container<T> {
	public:
		NDUO() : NodeDouble<NDUO>(), CONTAINER::Container<T>() {}
		NDUO(const T& item_0) : NodeDouble<NDUO>(), CONTAINER::Container<T>(item_0) {}
		virtual ~NDUO() {}
		NDUO<T>* operator+(const len_t& positions) {
			NDUO<T>* result = nullptr;
			// Si estamos en la posicion indicada devolvemos este nodo
			if (positions == 0) result = this;
			// Si aun quedan posiciones
			else
				result = this->getSiguienteNodo() != nullptr
				// Si el siguiente nodo no es nullptr
				? this->getSiguienteNodo()->operator+(positions - 1)
				// Si es nullptr devolvemos nullptr (Ya que se ha pasado)
				: nullptr;
		}
		NDUO<T>* operator-(const len_t& positions) {
			NDUO<T>* result = nullptr;
			// Si estamos en la posicion indicada devolvemos este nodo
			if (positions == 0) result = this;
			// Si aun quedan posiciones
			else
				result = this->getAnteriorNodo() != nullptr
				// Si el anterior nodo no es nullptr
				? this->getAnteriorNodo()->operator+(positions - 1)
				// Si es nullptr devolvemos nullptr (Ya que se ha pasado)
				: nullptr;
		}
};

// Nodo doble con dos objetos (ContainerDouble)
template<class T0, class T1>
class NDDO : public NodeDouble<NDDO<T0, T1>>, public CONTAINER::ContainerDouble<T0, T1> {
	public:
		NDDO() : NodeDouble<NDDO<T0, T1>>(), CONTAINER::ContainerDouble<T0, T1>() {}
		NDDO(const T0& item_0, const T1& item_1) : NodeDouble<NDDO<T0, T1>>(), CONTAINER::ContainerDouble<T0, T1>(item_1, item_1) {}
		virtual ~NDDO() {}
		NDDO<T0, T1>* operator+(const len_t& positions) {
			NDDO<T0, T1>* result = nullptr;
			// Si estamos en la posicion insicada devolvemos este nodo
			if (positions == 0) result = this;
			// Si aun quedan posiciones
			else
				result = this->getSiguienteNodo() != nullptr
				// Si el siguiente nodo no es nullptr
				? this->getSiguienteNodo()->operator+(positions - 1)
				// Si es nullptr devolvemos nullptr (Ya que se ha pasado)
				: nullptr;
		}
		NDDO<T0, T1>* operator-(const len_t& positions) {
			NDDO<T0, T1>* result = nullptr;
			// Si estamos en la posicion insicada devolvemos este nodo
			if (positions == 0) result = this;
			// Si aun quedan posiciones
			else
				result = this->getAnteriorNodo() != nullptr
				// Si el anterior nodo no es nullptr
				? this->getAnteriorNodo()->operator+(positions - 1)
				// Si es nullptr devolvemos nullptr (Ya que se ha pasado)
				: nullptr;
		}
};

} /* namespace Nodes */
} /* namespace Listlib */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_CLASSES_NODES_NODEDOUBLE_H_ */
