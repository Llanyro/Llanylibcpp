/*
 * List.h
 *
 *  Created on: Jun 9, 2021
 *      Author: llanyro
 */

#ifndef CORE_CLASSES_SIMPLELISTS_LIST_H_
#define CORE_CLASSES_SIMPLELISTS_LIST_H_

#include "../Countable.h"

namespace Llanylib {
namespace Core {
namespace Classes {
namespace SimpleLists {

template<class T>
class Node {
	public:
		T object;
		Node<T>* next;
		Node<T>* prev;
	public:
		Node(const T& item) {
			this->object = item;
			this->next = nullptr;
			this->prev = nullptr;
		}
		~Node() {}
};
template<class T>
class SmartNode {
	public:
		T* object;
		SmartNode<T>* next;
		SmartNode<T>* prev;
	public:
		SmartNode(T* item) {
			this->object = item;
			this->next = nullptr;
			this->prev = nullptr;
		}
		~SmartNode() {
			if(this->object != nullptr)
				delete this->object;
		}
};

template<class T>
class List : public Countable {
	protected:
		Node<T>* root;
		BASIC_STRUCTS::cachelist<Node<T>*, len_t>* cache_node;
	protected:
		// Funcion: Comprueba si la posicion dada se puede encontrar en la lista
		// Version: Final
		// Precondiciones:
		//		Ninguna
		// Retorno:
		//		 true: Si la posicion dada esta en la lista
		//		false: Si la posicion dada no esta en la lista
		// Complejidad temporal y espacial: O(1) y M(1)
		virtual ll_bool_t valid_pos(const len_t& pos) const { return pos < this->length; }
		// Funcion: Busca el la lista el nodo solicitado
		// Extra: Guarda el ultimo nodo visitado
		// Version: Beta
		// Precondiciones:
		//		position != nullptr
		// Retorno: Nodo solicitado
		// Complejidad temporal y espacial: O(n/2) y M(1)
		Node<T>* get_node_no_cache(const len_t& position) const {
			Node<T>* nodeActual = nullptr;
			if (this->valid_pos(position)) {
				nodeActual = this->root;
				if (position < this->length / 2)
					for (len_t i = 0; i < position; i++)
						nodeActual = nodeActual->next;
				else
					for (len_t i = 0; i < this->length - position; i++)
						nodeActual = nodeActual->prev;
				// Guardamos el ultimo accedido
				this->set_cache_node(nodeActual, position);
			}
			return nodeActual;
		}
		// Funcion: Busca el la lista el nodo solicitado ademas de contar con el ultimo buscado
		// Version: Beta
		// Precondiciones:
		//		position != nullptr
		// Retorno: Nodo solicitado
		// Complejidad temporal y espacial peor: O(n/2) y M(1)
		// Complejidad temporal y espacial mejor: O(1) y M(1)
		Node<T>* get_node_cache(const len_t& position) const {
			Node<T>* nodeActual = nullptr;
			if (this->valid_pos(position)) {
				if (position == 0)
					nodeActual = this->root;
				else if (position == (this->length - 1))
					nodeActual = this->root->prev;
				else if (this->cache_node->cache != nullptr) {
					nodeActual = this->cache_node->cache;
					if (position > this->cache_node->position)
						for (len_t i = this->cache_node->position; i < position; i++)
							nodeActual = nodeActual->next;
					else
						for (len_t i = 0; i < this->cache_node->position - position; i++)
							nodeActual = nodeActual->prev;
					// Guardamos el ultimo accedido
					this->set_cache_node(nodeActual, position);
				}
				else nodeActual = this->get_node_no_cache(position);
			}
			return nodeActual;
		}
	public:
		List() : Countable() {
			this->root = nullptr;
			this->cache_node = new BASIC_STRUCTS::cachelist<Node<T>*, len_t>();
			this->set_cache_node(nullptr, 0);
		}
		virtual ~List() {
			this->clear();
			delete this->cache_node;
		}
		virtual ll_bool_t clear() override {
			Node<T>* temp = nullptr;
			Node<T>* nodeRemove = this->root->prev;
			while (nodeRemove != this->root) {
				temp = nodeRemove->prev;
				delete nodeRemove;
				nodeRemove = temp;
			}
			delete this->root;
			this->cache_node->cache = nullptr;
			this->cache_node->position = 0;
			return Classes::Countable::clear();
		}
		virtual void set_cache_node(Node<T>* node, const len_t& position) const {
			this->cache_node->cache = node;
			this->cache_node->position = position;
		}
		virtual ll_bool_t contains(const T* item, Compare_bool compare) const {
			ll_bool_t result = false;
			Node<T>* node = this->root;
			// Si tenemos la funcion de comparacion
			if(compare != nullptr) {
				for (len_t i = 0; !result && i < this->length; i++) {
					result = compare(item, &node->object);
					node = node->next;
				}
			}
			// Si no tenemos, usamos ==
			else {
				for (len_t i = 0; !result && i < this->length; i++) {
					result = (*item == node->object);
					node = node->next;
				}
			}
			return result;
		}
		virtual T* get(const len_t& pos) const {
			T* item = nullptr;
			if(this->valid_pos(pos))
				item = &this->get_node_cache(pos)->object;
			return item;
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
			ll_bool_t result = true;
			if (this->valid_pos(pos)) {
				// Nodes a modificar
				Node<T>* node_del = nullptr;
				if (this->length == 1) {
					node_del = this->root;
					this->root = nullptr;
					this->set_cache_node(nullptr, 0);
				}
				else {
					// Hacemos esto para aumentar al eficiencia al eliminar el node 0
					if (pos == 0) node_del = this->root;
					else node_del = this->get_node_cache(pos);

					Node<T>* node_next = node_del->next;
					Node<T>* node_prev = node_del->prev;
					// Modificamos los Nodes
					node_prev->next = node_next;
					node_next->prev = node_prev;
					// Si es un caso especial
					if (pos == 0) this->root = node_next;
					// Recolocamos el punto intermedio en el node siguiente y la posicion actual(que sera la actualizada de este)
					this->set_cache_node(node_next, pos);
				}
				delete node_del;
				this->length--;
			}
			else result = false;
			return result;
		}
		// Funcion: Por defecto llama a remove()
		ll_bool_t del(const len_t& pos) { return this->remove(pos); }
		virtual void add(const T& object) {
			// Creamos el nodo
			Node<T>* node = new Node<T>(object);
			// Caso especial de que la lista este vacia
			if (this->length == 0) {
				this->root = node;
				node->next = node;
				node->prev = node;
			}
			// Añadirmos al final
			else {
				// Guardamos los Nodes que vamos a modificar
				Node<T>* node_prev = this->get_node_cache(this->length - 1);
				Node<T>* node_next = node_prev->next;

				// Apuntamos correctamente el nodo entre los otros Nodes
				node->next = node_next;
				node->prev = node_prev;
				// Hacemos que los otros Nodes apunten al nuevo
				node_prev->next = node;
				node_next->prev = node;
			}
			// Incrementamos el tama�o
			this->length++;
		}
		virtual ll_bool_t set(const T& object, const len_t& position) {
			ll_bool_t result = true;
			if(this->valid_pos(position))
				this->get_node_cache(position)->object = object;
			else result = false;
			return result;
		}
};
template<class T>
class SmartList : public Countable {
	protected:
		SmartNode<T>* root;
		BASIC_STRUCTS::cachelist<SmartNode<T>*, len_t>* cache_node;
	protected:
		// Funcion: Comprueba si la posicion dada se puede encontrar en la lista
		// Version: Final
		// Precondiciones:
		//		Ninguna
		// Retorno:
		//		 true: Si la posicion dada esta en la lista
		//		false: Si la posicion dada no esta en la lista
		// Complejidad temporal y espacial: O(1) y M(1)
		virtual ll_bool_t valid_pos(const len_t& pos) const { return pos < this->length; }
		// Funcion: Busca el la lista el nodo solicitado
		// Extra: Guarda el ultimo nodo visitado
		// Version: Beta
		// Precondiciones:
		//		position != nullptr
		// Retorno: Nodo solicitado
		// Complejidad temporal y espacial: O(n/2) y M(1)
		SmartNode<T>* get_node_no_cache(const len_t& position) const {
			SmartNode<T>* nodeActual = nullptr;
			if (this->valid_pos(position)) {
				nodeActual = this->root;
				if (position < this->length / 2)
					for (len_t i = 0; i < position; i++)
						nodeActual = nodeActual->next;
				else
					for (len_t i = 0; i < this->length - position; i++)
						nodeActual = nodeActual->prev;
				// Guardamos el ultimo accedido
				this->set_cache_node(nodeActual, position);
			}
			return nodeActual;
		}
		// Funcion: Busca el la lista el nodo solicitado ademas de contar con el ultimo buscado
		// Version: Beta
		// Precondiciones:
		//		position != nullptr
		// Retorno: Nodo solicitado
		// Complejidad temporal y espacial peor: O(n/2) y M(1)
		// Complejidad temporal y espacial mejor: O(1) y M(1)
		SmartNode<T>* get_node_cache(const len_t& position) const {
			SmartNode<T>* nodeActual = nullptr;
			if (this->valid_pos(position)) {
				if (position == 0)
					nodeActual = this->root;
				else if (position == (this->length - 1))
					nodeActual = this->root->prev;
				else if (this->cache_node->cache != nullptr) {
					nodeActual = this->cache_node->cache;
					if (position > this->cache_node->position)
						for (len_t i = this->cache_node->position; i < position; i++)
							nodeActual = nodeActual->next;
					else
						for (len_t i = 0; i < this->cache_node->position - position; i++)
							nodeActual = nodeActual->prev;
					// Guardamos el ultimo accedido
					this->set_cache_node(nodeActual, position);
				}
				else nodeActual = this->get_node_no_cache(position);
			}
			return nodeActual;
		}
	public:
		SmartList() : Countable() {
			this->root = nullptr;
			this->cache_node = new BASIC_STRUCTS::cachelist<SmartNode<T>*, len_t>();
			this->set_cache_node(nullptr, 0);
		}
		virtual ~SmartList() {
			this->clear();
			delete this->cache_node;
		}
		virtual ll_bool_t clear() override {
			SmartNode<T>* temp = nullptr;
			SmartNode<T>* nodeRemove = this->root->prev;
			while (nodeRemove != this->root) {
				temp = nodeRemove->prev;
				delete nodeRemove;
				nodeRemove = temp;
			}
			delete this->root;
			this->cache_node->cache = nullptr;
			this->cache_node->position = 0;
			return Classes::Countable::clear();
		}
		virtual void set_cache_node(SmartNode<T>* node, const len_t& position) const {
			this->cache_node->cache = node;
			this->cache_node->position = position;
		}
		virtual ll_bool_t contains(const T* item, Compare_bool compare) const {
			ll_bool_t result = false;
			SmartNode<T>* node = this->root;
			// Si tenemos la funcion de comparacion
			if(compare != nullptr) {
				for (len_t i = 0; !result && i < this->length; i++) {
					result = compare(item, node->object);
					node = node->next;
				}
			}
			// Si no tenemos, usamos ==
			else {
				for (len_t i = 0; !result && i < this->length; i++) {
					result = (*item == *node->object);
					node = node->next;
				}
			}
			return result;
		}
		virtual T* get(const len_t& pos) const {
			T* item = nullptr;
			if(this->valid_pos(pos))
				item = this->get_node_cache(pos)->object;
			return item;
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
			ll_bool_t result = true;
			if (this->valid_pos(pos)) {
				// Nodes a modificar
				SmartNode<T>* node_del = nullptr;
				if (this->length == 1) {
					node_del = this->root;
					this->root = nullptr;
					this->set_cache_node(nullptr, 0);
				}
				else {
					// Hacemos esto para aumentar al eficiencia al eliminar el node 0
					if (pos == 0) node_del = this->root;
					else node_del = this->get_node_cache(pos);

					SmartNode<T>* node_next = node_del->next;
					SmartNode<T>* node_prev = node_del->prev;
					// Modificamos los Nodes
					node_prev->next = node_next;
					node_next->prev = node_prev;
					// Si es un caso especial
					if (pos == 0) this->root = node_next;
					// Recolocamos el punto intermedio en el node siguiente y la posicion actual(que sera la actualizada de este)
					this->set_cache_node(node_next, pos);
				}
				delete node_del;
				this->length--;
			}
			else result = false;
			return result;
		}
		// Funcion: Por defecto llama a remove()
		ll_bool_t del(const len_t& pos) { return this->remove(pos); }
		virtual void add(T* object) {
			// Creamos el nodo
			SmartNode<T>* node = new SmartNode<T>(object);
			// Caso especial de que la lista este vacia
			if (this->length == 0) {
				this->root = node;
				node->next = node;
				node->prev = node;
			}
			// Añadirmos al final
			else {
				// Guardamos los Nodes que vamos a modificar
				SmartNode<T>* node_prev = this->get_node_cache(this->length - 1);
				SmartNode<T>* node_next = node_prev->next;

				// Apuntamos correctamente el nodo entre los otros Nodes
				node->next = node_next;
				node->prev = node_prev;
				// Hacemos que los otros Nodes apunten al nuevo
				node_prev->next = node;
				node_next->prev = node;
			}
			// Incrementamos el tama�o
			this->length++;
		}
		virtual ll_bool_t set(T* object, const len_t& position) {
			ll_bool_t result = true;
			if(this->valid_pos(position))
				this->get_node_cache(position)->object = object;
			else result = false;
			return result;
		}
		virtual T* extract(const len_t& position) {
			SmartNode<T>* node = get_node_cache(position);
			T* object = nullptr;
			if(node != nullptr) {
				object = node->object;
				node->object = nullptr;
				this->remove(position);
			}
			return object;
		}
};

} /* namespace SimpleLists */
} /* namespace Classes */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* CORE_CLASSES_SIMPLELISTS_LIST_H_ */
