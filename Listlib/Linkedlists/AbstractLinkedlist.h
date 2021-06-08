/*
 * AbstractLinkedlist.h
 *
 *  Created on: May 30, 2021
 *      Author: llanyro
 */

#ifndef LISTLIB_LINKEDLISTS_ABSTRACTLINKEDLIST_H_
#define LISTLIB_LINKEDLISTS_ABSTRACTLINKEDLIST_H_

#include "../Corelist/List.h"

namespace Llanylib {
namespace Listlib {
namespace Linkedlists {

template<class T, class T_NODE>
class AbstractLinkedlist : public Corelist::List<T> {
	protected:
		T_NODE* raiz;
		BASIC_STRUCTS::cachelist<T_NODE*, len_t>* cache;
	protected:
		AbstractLinkedlist() : Corelist::List<T>() {
			this->raiz = nullptr;
			this->cache = new BASIC_STRUCTS::cachelist<T_NODE*, len_t>();
		}
		virtual ~AbstractLinkedlist() { this->clear(); }
		void changeCacheNode(T_NODE* node, const len_t& position) const {
			this->cache->cache = node;
			this->cache->position = position;
		}
		void clearCache() const { this->changeCacheNode(nullptr, 0); }
		// Funcion: Busca el la lista el nodo solicitado
		// Extra: Guarda el ultimo nodo visitado
		// Version: Beta
		// Precondiciones:
		//		position != nullptr
		// Retorno: Nodo solicitado
		// Complejidad temporal y espacial: O(n/2) y M(1)
		T_NODE* getNodoNoCache(const len_t& position) const {
			T_NODE* nodoActual = nullptr;
			if (this->validPos(position)) {
				nodoActual = this->raiz;
				if (position < this->length / 2)
					for (len_t i = 0; i < position; i++)
						nodoActual = nodoActual->getSiguienteNodo();
				else
					for (len_t i = 0; i < this->length - position; i++)
						nodoActual = nodoActual->getAnteriorNodo();
				// Guardamos el ultimo accedido
				this->changeCacheNode(nodoActual, position);
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
		T_NODE* getNodoCache(const len_t& position) const {
			T_NODE* nodoActual = nullptr;
			if (this->validPos(position)) {
				if (position == 0)
					nodoActual = this->raiz;
				else if (position == (this->length - 1))
					nodoActual = this->raiz->getAnteriorNodo();
				else if (this->cache->cache != nullptr) {
					nodoActual = this->cache->cache;
					if (position > this->cache->position)
						for (len_t i = this->cache->position; i < position; i++)
							nodoActual = nodoActual->getSiguienteNodo();
					else
						for (len_t i = 0; i < this->cache->position - position; i++)
							nodoActual = nodoActual->getAnteriorNodo();
					// Guardamos el ultimo accedido
					this->changeCacheNode(nodoActual, position);
				}
				else nodoActual = this->getNodoNoCache(position);
			}
			return nodoActual;
		}
	public:
		virtual ll_bool_t contains(const T* item, Compare_bool compare) const override {
			ll_bool_t resultado = false;
			T_NODE* nodoActual = this->raiz;
			// Si tenemos la funcion de comparacion
			if(compare != nullptr) {
				for (len_t i = 0; !resultado && i < this->length; i++) {
					resultado = compare(item, nodoActual->get_0());
					nodoActual = nodoActual->getSiguienteNodo();
				}
			}
			// Si no tenemos, usamos ==
			else {
				for (len_t i = 0; !resultado && i < this->length; i++) {
					resultado = (*item == *nodoActual->get_0());
					nodoActual = nodoActual->getSiguienteNodo();
				}
			}
			return resultado;
		}
		virtual T* get(const len_t& pos) const override {
			T* item = nullptr;
			if(this->validPos(pos))
				item = this->getNodoCache(pos)->get_0();
			return item;
		}
		virtual T* operator[](const len_t& pos) override { return this->get(pos); }
		virtual ll_bool_t clear() override {
			delete this->cache;
			this->raiz->deleteRecursivo(nullptr);
			return Corelist::List<T>::clear();
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
		virtual ll_bool_t remove(const len_t& pos)  {
			bool resultado = false;
			if (this->validPos(pos)) {
				// Nodes a modificar
				T_NODE* nodoAEliminar = nullptr;
				if (this->length == 1) {
					nodoAEliminar = this->raiz;
					this->raiz = nullptr;
					this->clearCache();
				}
				else {
					// Hacemos esto para aumentar al eficiencia al eliminar el nodo 0
					if (pos == 0) nodoAEliminar = this->raiz;
					else nodoAEliminar = this->getNodoCache(pos);

					T_NODE* nodeSiguiente = nodoAEliminar->getSiguienteNodo();
					T_NODE* nodeAnterior = nodoAEliminar->getAnteriorNodo();
					// Modificamos los Nodes
					nodeAnterior->setSiguienteNodo(nodeSiguiente);
					nodeSiguiente->setAnteriorNodo(nodeAnterior);
					// Si es un caso especial
					if (pos == 0) this->raiz = nodeSiguiente;
					// Recolocamos el punto intermedio en el nodo siguiente y la posicion actual(que sera la actualizada de este)
					this->changeCacheNode(nodeSiguiente, pos);
				}
				delete(nodoAEliminar);
				this->length--;
				resultado = true;
			}
			return resultado;
		}
		// Funcion: Por defecto llama a remove()
		ll_bool_t del(const len_t& pos) { return this->remove(pos); }
};

} /* namespace Linkedlist */
} /* namespace Listlib */
} /* namespace Llanylib */

#endif /* LISTLIB_LINKEDLISTS_ABSTRACTLINKEDLIST_H_ */
