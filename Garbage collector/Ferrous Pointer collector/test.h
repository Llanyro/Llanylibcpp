/*
 * test.h
 *
 *  Created on: Dec 1, 2020
 *      Author: llanyro
 */

#ifndef LLANYLIB_BASIC_GARBAGE_COLLECTOR_FERROUS_POINTER_COLLECTOR_TEST_H_
#define LLANYLIB_BASIC_GARBAGE_COLLECTOR_FERROUS_POINTER_COLLECTOR_TEST_H_

#include "../../Simplelibs/llanytypeslib.h"

#include <stdlib.h>

void easyFree(void* pointer) {
	free(pointer);
}

class Nodo {
	protected:
		len_t numObjects;				// Numero de objetos
		ll_uint32_t sizePerObject;		// Tamaño en bytes de cada objeto (No importa cuanto haya)
		void* itemPointer;				// Puntero al objeto guardado
		void (*funFree)(void*);			// Funcion de liberacion de memoria

		Nodo* padre;					// Puntero al padre
		Nodo* hijoDerecho;				// Puntero al hijo derecho
		Nodo* hijoIzquierdo;			// PUntero al hijo izquierdo

	protected:
		// Calcula la altura del subarbol izquierdo, o -1 si no hay subarbol izquierdo
		// Retorno: altura del subarbol izquierdo, o -1 si no hay
		// Complejidad temporal y espacial: O(1)
		ll_int64_t getAlturaSubarbolIzquierdo() const {
			// Altura del hijo izquierdo
			ll_int64_t alturaHijoIzquierdo;
			if (this->hijoIzquierdo == nullptr)
				alturaHijoIzquierdo = -1;
			else
				alturaHijoIzquierdo = this->hijoIzquierdo->getAltura();
			return alturaHijoIzquierdo;
		}
		// Calcula la altura del subarbol derecho, o -1 si no hay subarbol derecho
		// Retorno: altura del subarbol derecho, o -1 si no hay
		// Complejidad temporal y espacial: O(1)
		ll_int64_t getAlturaSubarbolDerecho() const {
			// Altura del hijo derecho
			ll_int64_t alturaHijoDerecho;
			if (this->hijoDerecho == nullptr)
				alturaHijoDerecho = -1;
			else
				alturaHijoDerecho = this->hijoDerecho->getAltura();
			return alturaHijoDerecho;
		}
	public:
		Nodo() {
			this->funFree = easyFree;
			this->numObjects = 0;
			this->sizePerObject = 0;
			this->itemPointer = nullptr;
			this->padre = nullptr;
			this->hijoDerecho = nullptr;
			this->hijoIzquierdo = nullptr;
		}
		virtual ~Nodo() {
			if(this->itemPointer != nullptr)
				this->funFree(this->itemPointer);

			this->funFree = nullptr;
			this->numObjects = 0;
			this->sizePerObject = 0;
			this->itemPointer = nullptr;
			this->padre = nullptr;
			this->hijoDerecho = nullptr;
			this->hijoIzquierdo = nullptr;
		}

};

struct List {

};

#endif /* LLANYLIB_BASIC_GARBAGE_COLLECTOR_FERROUS_POINTER_COLLECTOR_TEST_H_ */
