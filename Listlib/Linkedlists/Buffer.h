/*
 * Vector.h
 *
 *  Created on: Mar 3, 2021
 *      Author: llanyro
 */

#ifndef LISTLIB_LINKEDLISTS_BUFFER_H_
#define LISTLIB_LINKEDLISTS_BUFFER_H_

#include "../Corelist/List.h"
#include "../../Nodelib/ListNodes.h"

namespace Llanylib {
namespace Listlib {
namespace Linkedlists {

/*
	contains();
	get();
	clear();
	~Buffer();
	remove();
	add(const T& object);
	add(const T* vector, const len_t& length);

*/
template<class T>
class Buffer : public Corelist::List<T> {
	protected:
		LIST_NODES::NodeDouble* root;
		CONTAINERS::ContainerDouble<LIST_NODES::NodeDouble*, len_t>* cache;
	protected:
		// Funcion: Busca el la lista el nodo solicitado
		// Extra: Guarda el ultimo nodo visitado
		// Version: Beta
		// Precondiciones:
		//		position != nullptr
		// Retorno: Nodo solicitado
		// Complejidad temporal y espacial: O(n/2) y M(1)
		LIST_NODES::NodeDouble* getNodoNoCache(const len_t& position) const {
			LIST_NODES::NodeDouble* nodoActual = nullptr;
			if (this->validPos(position)) {
				nodoActual = this->root;
				if (position < this->length / 2)
					for (len_t i = 0; i < position; i++)
						nodoActual = nodoActual->nextNode;
				else
					for (len_t i = 0; i < this->length - position; i++)
						nodoActual = nodoActual->prevNode;
				// Guardamos el ultimo accedido
				this->cache->object_0 = nodoActual;
				this->cache->object_1 = position;
			}
			return nodoActual;
		}
		// Funcion: Busca el la lista el nodo solicitado ademas de contar con el ultimo buscado
		// Version: Beta
		// Precondiciones:
		//		position != nullptr
		// Retorno: Nodo solicitado
		// Complejidad temporal y espacial peor: O(n/2) y M(1)
		// Complejidad temporal y espacial mejor: O(1) y M(1)
		LIST_NODES::NodeDouble* getNodoCache(const len_t& position) const {
			LIST_NODES::NodeDouble* nodoActual = nullptr;
			if (this->validPos(position)) {
				if (position == 0)
					nodoActual = this->root;
				else if (position == (this->length - 1))
					nodoActual = this->root->prevNode;
				else if (this->cache->object_0 != nullptr) {
					nodoActual = this->cache->object_0;
					if (position > this->cache->object_1)
						for (len_t i = this->cache->object_1; i < position; i++)
							nodoActual = nodoActual->nextNode;
					else
						for (len_t i = 0; i < this->cache->object_1 - position; i++)
							nodoActual = nodoActual->prevNode;
					// Guardamos el ultimo accedido
					this->cache->object_0 = nodoActual;
					this->cache->object_1 = position;
				}
				else nodoActual = this->getNodoNoCache(position);
			}
			return nodoActual;
		}
		void addNode(NODE* node) {
			// Caso especial de que la lista este vacia
			if (this->length == 0)
				this->root = node;
			// Añadirmos al final
			else {
				// Guardamos los Nodes que vamos a modificar
				LIST_NODES::NodeDouble* anteriorNodo = this->getNodoCache(this->length - 1);
				LIST_NODES::NodeDouble* siguienteNodo = anteriorNodo->nextNode;

				// Apuntamos correctamente el nodo entre los otros Nodes
				node->nextNode = siguienteNodo;
				node->prevNode = anteriorNodo;
				// Hacemos que los otros Nodes apunten al nuevo
				anteriorNodo->nextNode = node;
				siguienteNodo->prevNode = node;
			}
			// Incrementamos el tamaño
			this->length++;
		}
	public:
		Buffer() {
			this->root = nullptr;
			this->cache =
				new CONTAINERS::ContainerDouble<LIST_NODES::NodeDouble*, len_t>(nullptr, 0);
		}
		virtual ~Buffer() {
			this->clear();
			delete this->cache;
		}
		virtual ll_bool_t contains(const T* object, Compare_bool compare) const override { return false; }
		virtual T* get(const len_t& position) const override { return nullptr; }
		virtual T* operator[](const len_t& position) override { return this->get(position); }
		virtual ll_bool_t clear() override { return true; }
		// Funcion: Elimina un item de la lista
		// Extra: Si esta seteado como liberable, eliminara el objeto
		// Version: Final
		// Precondiciones:
		//		pos < len
		// Retorno:
		//		 true: Si se ha eliminado el objeto con exito
		//		false: Si no se ha eliminado el objeto con exito
		// Complejidad temporal y espacial: O(1) y M(1)
		virtual ll_bool_t remove(const len_t& pos) { return false; }
		virtual void add(const T& object) {}
		virtual void add(const T* vector, const len_t& length) {}
		virtual ll_bool_t set(const T& object, const len_t& position) { return false; }
};

} /* namespace Linkedlists */
} /* namespace Listlib */
} /* namespace Llanylib */

#endif /* LISTLIB_LINKEDLISTS_BUFFER_H_ */
