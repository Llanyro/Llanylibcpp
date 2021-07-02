#pragma once

#ifndef L_H
#define L_H

#include "../Corelib/Class/Countable.h"
#include "../Listlib/Corelist/List.h"


#include "Iterator.h"

namespace Llanylib {
namespace Listlib {
namespace Linkedlists {

template<class T>
class ListTest : public Corelist::List<T> {
	protected:
		NodeDouble<T>* root;
		ContainerDouble<NodeDouble<T>*, len_t>* cache;
	public:
		ListTest() {
			this->root = nullptr;
			this->cache = new ContainerDouble<NodeDouble<T>*, len_t>(nullptr, 0);
		}
		virtual ~ListTest() {
			this->clear();
			delete this->cache;
		}
	protected:
		// Funcion: Busca el la lista el nodo solicitado
		// Extra: Guarda el ultimo nodo visitado
		// Version: Beta
		// Precondiciones:
		//		position != nullptr
		// Retorno: Nodo solicitado
		// Complejidad temporal y espacial: O(n/2) y M(1)
		NodeDouble<T>* getNodoNoCache(const len_t& position) const {
			NodeDouble<T>* nodoActual = nullptr;
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
		NodeDouble<T>* getNodoCache(const len_t& position) const {
			NodeDouble<T>* nodoActual = nullptr;
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
	protected:
		virtual ll_bool_t contains(const T* item, Compare_bool compare) const override {
			ll_bool_t resultado = false;
			NodeDouble<T>* nodoActual = this->root;
			// Si tenemos la funcion de comparacion
			if (compare != nullptr) {
				for (len_t i = 0; !resultado && i < this->length; i++) {
					resultado = compare(item, &nodoActual->object_0);
					nodoActual = nodoActual->nextNode;
				}
			}
			// Si no tenemos, usamos ==
			else {
				for (len_t i = 0; !resultado && i < this->length; i++) {
					resultado = (*item == nodoActual->object_0);
					nodoActual = nodoActual->nextNode;
				}
			}
			return resultado;
		}
		virtual T* get(const len_t& pos) const override {
			T* item = nullptr;
			if (this->validPos(pos))
				item = &this->getNodoCache(pos)->object_0;
			return item;
		}
		virtual T* operator[](const len_t& pos) override { return this->get(pos); }
		virtual ll_bool_t clear() override {
			NodeDouble<T>* temp = nullptr;
			NodeDouble<T>* nodeRemove = this->root->prevNode;
			while (nodeRemove != this->root) {
				temp = nodeRemove->prevNode;
				delete nodeRemove;
				nodeRemove = temp;
			}
			delete this->root;
			return true;
		}
		// Funcion: Elimina un item de la lista
		// Extra: Si esta seteado como liberable, eliminara el objeto
		// Version: Final
		// Precondiciones:
		//		pos < len
		// Retorno:
		//		 true: Si se ha eliminado el objeto con exito
		//		false: Si no se ha eliminado el objeto con exito
		// Complejidad temporal y espacial: O(1) y M(1)
		virtual ll_bool_t remove(const len_t& pos) {
			bool resultado = false;
			if (this->validPos(pos)) {
				// Nodes a modificar
				NodeDouble<T>* nodoAEliminar = nullptr;
				if (this->length == 1) {
					nodoAEliminar = this->root;
					this->root = nullptr;
					this->cache->object_0 = nullptr;
					this->cache->object_1 = 0;
				}
				else {
					// Hacemos esto para aumentar al eficiencia al eliminar el nodo 0
					if (pos == 0) nodoAEliminar = this->root;
					else nodoAEliminar = this->getNodoCache(pos);

					NodeDouble<T>* nodeSiguiente = nodoAEliminar->nextNode;
					NodeDouble<T>* nodeAnterior = nodoAEliminar->prevNode;
					// Modificamos los Nodes
					nodeAnterior->nextNode = nodeSiguiente;
					nodeSiguiente->prevNode = nodeAnterior;
					// Si es un caso especial
					if (pos == 0) this->root = nodeSiguiente;
					// Recolocamos el punto intermedio en el nodo siguiente y la posicion actual(que sera la actualizada de este)
					this->cache->object_0 = nodeSiguiente;
					this->cache->object_1 = pos;
				}
				delete(nodoAEliminar);
				this->length--;
				resultado = true;
			}
			return resultado;
		}
		// Funcion: Por defecto llama a remove()
		ll_bool_t del(const len_t& pos) { return this->remove(pos); }
	public:
		virtual void add(const T& object) {
			// Creamos el nodo
			NodeDouble<T>* nuevoNodo = new NodeDouble<T>(object);
			// Caso especial de que la lista este vacia
			if (this->length == 0)
				this->root = nuevoNodo;
			// Añadirmos al final
			else {
				// Guardamos los Nodes que vamos a modificar
				NodeDouble<T>* anteriorNodo = this->getNodoCache(this->length - 1);
				NodeDouble<T>* siguienteNodo = anteriorNodo->nextNode;

				// Apuntamos correctamente el nodo entre los otros Nodes
				nuevoNodo->nextNode = siguienteNodo;
				nuevoNodo->prevNode = anteriorNodo;
				// Hacemos que los otros Nodes apunten al nuevo
				anteriorNodo->nextNode = nuevoNodo;
				siguienteNodo->prevNode = nuevoNodo;
			}
			// Incrementamos el tama�o
			this->length++;
		}
		virtual ll_bool_t set(const T& object, const len_t& position) {
			ll_bool_t result = true;
			if(this->validPos(position))
				this->getNodoCache(position)->object_0 = object;
			else result = false;
			return result;
		}

};

} /* namespace Linkedlist */
} /* namespace Listlib */
} /* namespace Llanylib */

#endif /* L_H */
