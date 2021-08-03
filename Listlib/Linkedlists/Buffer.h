/*
 * Buffer.h
 *
 *  Created on: Mar 3, 2021
 *      Author: llanyro
 */

#ifndef LISTLIB_LINKEDLISTS_BUFFER_H_
#define LISTLIB_LINKEDLISTS_BUFFER_H_

#include "Linkedlist.h"
#include "../Dynamiclist/VectorBuffer.h"

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
		len_t bufferPseudoSize;
		Linkedlist<Dynamiclist::VectorBuffer<T>> list;
		Dynamiclist::VectorBuffer<T>* lastVector;
	protected:
		void genNewVector() {
			this->list.add(Dynamiclist::VectorBuffer<T>(bufferPseudoSize));
			this->lastVector = this->list.begin();
		}
	public:
		Buffer() : Buffer(300) {}
		Buffer(const len_t& bufferPseudoSize) {
			this->bufferPseudoSize = bufferPseudoSize;
			this->lastVector = nullptr;
			this->genNewVector();
		}
		Buffer() : Buffer(300) {}
		virtual ~Buffer() { this->lastVector = nullptr; }
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
		virtual void add(const T& object) {
			if (!this->lastVector->add(object)) {
				this->genNewVector();
				this->lastVector->add(object);
			}
		}
		virtual void add(const T* vector, const len_t& length) {
			len_t objectsAdded = this->lastVector->add(vector, length);

			// Si no se han añadido todos los objetos
			if (objectsAdded < length) {
				




			}

			len_t result;

			while (result > 0) {

			}



		}
		virtual ll_bool_t set(const T& object, const len_t& position) { return false; }
};

} /* namespace Linkedlists */
} /* namespace Listlib */
} /* namespace Llanylib */

#endif /* LISTLIB_LINKEDLISTS_BUFFER_H_ */
