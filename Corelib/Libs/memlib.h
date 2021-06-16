/*
 * memlib.h
 *
 *  Created on: Nov 16, 2020
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORELIB_SIMPLELIBS_MEMLIB_H_
#define LLANYLIB_CORELIB_SIMPLELIBS_MEMLIB_H_

#include "llanytypeslib.h"

#define MEM_LIB Llanylib::Core::Libs::Mem

namespace Llanylib {
namespace Corelib {
namespace Libs {
namespace Mem {

/* Classic */
/* Punteros */
// Realiza un calculo para devolver el puntero a la direccion de memoria deseada dentro de un bloque de memoria
// Es muy util cuando se usa algoritmos de void*
// Version: Beta
// Precondiciones:
//		memBlock != nullptr
//		posicion >= 0, sizeType > 0
// Retorno: La direccion de memoria deseada
// Complejidad temporal y espacial: O(1) y M(1)
void* autoPointer(
	// Bloque de memoria donde se quiere realizar el AutoPointer
	const void* memBlock,
	// Posicion del bloque de emmoria a la que queremos castear
	const len_t& posicion,
	// Bytes del tipo de cada elemento
	const len_t& sizeType);
// DESCONOZCO SI FUNCIONA BIEN O COMPLETAMENTE BIEN (NO DEBUGEADO)
// Realiza un calculo para devolver el puntero a la direccion de memoria deseada dentro de un bloque de memoria
// Es muy util cuando se usa algoritmos de void**
// Importante: Recuerda que solo funciona para bloques de memoria que contienen subBloques de memoria que poseen el mismo tamaño entre ellos
//		Por lo que no funcionara con un bloque que posea 2 subbloques de 10 y 11 de tamaño respectivamente
// Los parametros: posicionX -> al desacer el primer puntero, posicionY -> al desacer el segundo puntero
// Precondiciones:
//		memBlock != nullptr
//		posicionX >= 0, posicionY >= 0, sizeType > 0
// Retorno: La direccion de memoria deseada
// Complejidad temporal y espacial: O(1) y M(1)
void* autoPointer(
	// Bloque de memoria donde se quiere realizar el AutoPointer
	const void* memBlock,
	// SubBloque de memoria al que queremos acceder (Primer AutoPointer)
	const len_t& posicionX,
	// Dato del SubBloque de memoria al que queremos acceder (Segundo AutoPointer)
	const len_t& posicionY,
	// Bytes del tipo de cada elemento
	const len_t& sizeType,
	// Bytes del tipo de subBloque
	const len_t& sizeSubBlockType,
	// Tamaño de los subbloques contenidos en el bloque
	const len_t& sizeSubBlock);
/* Control de memoria */
// Reserva tanta memoria como pedimos usando "malloc"
// Retorno: Un puntero al inicio del bloque de datos(void*)
// Precondicion:
//		bytes > 0
// Extra: Si falla "malloc" devuelve null
// Complejidad temporal y espacial: O(1) y M(n)
void* reservarMem(
	// Numero de bytes a reservar
	const len_t& bytes);
// Copia tanta memoria de un bloque o item de datos a un void*
// Retorno: La memoria copiada
// Precondiciones:
//		inicio >= 0, fin >= 0, sizeType > 0
//		source != nullptr && dest != nullptr
//		inicio < fin
// Complejidad temporal y espacial: O(n) y M(1)
void* copiarMemoria(
	// Destino donde se va ha copiar la memoria
	void* dest,
	// Bloque de memoria que se va a copiar
	const void* memBlock,
	// Posicion inicial del comienzo de la copia(Posicion incluida)
	const len_t& inicio,
	// Posicion final de la copia
	const len_t& fin,
	// Tamaño en bytes del tipo de la memoria
	const len_t& sizeType);
// Copia tanta memoria de un bloque o item de datos a un void*
// Retorno: La memoria creada y copiada
// Precondiciones:
//		inicio >= 0, fin >= 0, sizeType > 0
//		source != nullptr
//		inicio < fin
// Complejidad temporal y espacial: O(n) y M(n) (En bytes)
void* reservarYCopiar(
	// Bloque de memoria a copiar
	const void* memBlock,
	// Posicion inicial del comienzo de la copia(Posicion incluida)
	const len_t& inicio,
	// Posicion final de la copia
	const len_t& fin,
	// Tamaño en bytes del tipo de la memoria
	const len_t& sizeType);
// Realoca el bloque de memoria a otro lugar con otro tamaño
// Precondiciones:
//		sizeBlock > 0
//		sizeType > 0
// Complejidad temporal y espacial: O(n) y M(n)
void* resize(
	// Bloque a realocar(realloc)
	void* memBlock,
	// Tamaño del bloque
	const len_t& sizeBlock,
	// Tamaño en bytes del tipo de la memoria
	const len_t& sizeType);
// Funcion: Analiza un bloque de memoria dinamica para saber su tamaño
// Version: Final/Beta/Alfa/PreAlfa
// Precondiciones:
//		memBlock != nullptr
//		memblock is a dynamic vector
// Retorno: Void/Si se ha realizado todo correctamente
//		Resultado
// Complejidad temporal y espacial: O(1) y M(1)
len_t sizeBlock_b(void* memBlock);
// Libera la memoria ocupada
// Usa la funcion free()
// Precondiciones:
//		pointerToMemBlock != nullptr
// Complejidad temporal y espacial: O(1) y M(1)
void liberar(
	// Direccion de memoria del objeto que apunta a la memoria a liberar
	void** pointerToMemBlock);
// Libera la memoria ocupada
// Usa la funcion free()
// Precondiciones:
//		pointerToMemBlock != nullptr
// Complejidad temporal y espacial: O(1) y M(1)
void liberarSimple(
	// Direccion de memoria a liberar
	void* pointerToMemBlock);
// DESCONOZCO SI FUNCIONA BIEN O COMPLETAMENTE BIEN (NO DEBUGEADO) (Usa la Liberar)
// Cambia los datos de dos bloques de memoria usando un espacio de memoria auxiliar
// Precondiciones:
//		memBlock_a != nullptr && memBlock_b != nullptr
//		sizeBlock > 0 && sizeType > 0
// Complejidad temporal y espacial: O(1) y M(n)
void swap(
	// Item o bloque 1
	void* memBlock_a,
	// Item o bloque 2
	void* memBlock_b,
	// Tamaño del bloque de memoria (Numero de items)
	const len_t& sizeBlock,
	// Bytes del tipo de cada elemento
	const len_t& sizeType);
ll_int8_t compareMemoryBlocks(
		const void* block1,
		const len_t& size_1,
		const void* block2,
		const len_t& size_2,
		const len_t& sizeType,
		Compare_int compare);
/* Busquedas */
// Busca item dentro de un bloque de memoria
// Empieza a buscar desde: inicio hasta final
// Precondiciones:
//		memBlock != nullptr, item != nullptr
//		posInicial < posFinal, sizeType > 0
// Retorno: Si ha encontrado el elemento (True)
// Complejidad temporal y espacial: O(posFinal - posInicial) y M(1)
ll_bool_t buscarObjeto(
	// Bloque de datos a analizar
	const void* memBlock,
	// Posicion inicial al analizar (Incluida)
	const len_t& inicio,
	// Posicion final a analizar
	const len_t& fin,
	// Tamaño en bytes del tipo a analizar
	const len_t& sizeType,
	// Item a comparar
	const void* item,
	// Funcion de comparacion de items (Recuerda que debe de devolver [1,0,-1])
	Compare_int compare);
// Busca item dentro de un bloque de memoria
// Empieza a buscar desde: final hasta inicio
// Precondiciones:
//		memBlock != nullptr, item != nullptr
//		posInicial < posFinal, sizeType > 0
// Retorno: Si ha encontrado el elemento (True)
// Complejidad temporal y espacial: O(posFinal - posInicial) y M(1)
ll_bool_t buscarObjetoInvertido(
	// Bloque de datos a analizar
	const void* memBlock,
	// Posicion inicial al analizar (Incluida)
	const len_t& inicio,
	// Posicion final a analizar
	const len_t& fin,
	// Tamaño en bytes del tipo a analizar
	const len_t& sizeType,
	// Item a comparar
	const void* item,
	// Funcion de comparacion de items (Recuerda que debe de devolver [1,0,-1])
	Compare_int compare);
// Busca item dentro de un bloque de memoria (El menor)
// Empieza a buscar desde: inicio hasta final
// Precondiciones:
//		memBlock != nullptr
//		posInicial < posFinal, sizeType > 0
// Retorno: Posicion del item menor(Si hay varios devuelve el ultimo)
// Complejidad temporal y espacial: O(sizeBlock - posInicial) y M(1)
len_t buscarPosicionObjetoMenor(
	// Bloque de datos a analizar
	const void* memBlock,
	// Posicion inicial al analizar (Incluida)
	const len_t& inicio,
	// Posicion final a analizar
	const len_t& fin,
	// Tamaño en bytes del tipo a analizar
	const len_t& sizeType,
	// Funcion de comparacion de items (Recuerda que debe de devolver [1,0,-1])
	Compare_int compare);
// Busca item dentro de un bloque de memoria (El mayor)
// Empieza a buscar desde: inicio hasta final
// Precondiciones:
//		memBlock != nullptr
//		posInicial < posFinal, sizeType > 0
// Retorno: Posicion del item mayor(Si hay varios devuelve el ultimo)
// Complejidad temporal y espacial: O(sizeBlock - posInicial) y M(1)
len_t buscarPosicionObjetoMayor(
	// Bloque de datos a analizar
	const void* memBlock,
	// Posicion inicial al analizar (Incluida)
	const len_t& inicio,
	// Posicion final a analizar
	const len_t& fin,
	// Tamaño en bytes del tipo a analizar
	const len_t& sizeType,
	// Funcion de comparacion de items (Recuerda que debe de devolver [1,0,-1])
	Compare_int compare);
template<class T>
ll_bool_t contains(
	// Bloque de datos a analizar
	const T* memBlock,
	// Posicion inicial al analizar (Incluida)
	const len_t& inicio,
	// Posicion final a analizar
	const len_t& fin,
	// Item a comparar
	const T* item,
	// Funcion de comparacion de items (Recuerda que debe de devolver [1,0,-1])
	Compare_int compare) {
	ll_bool_t result = false;
	if(compare == nullptr)
		for (len_t i = inicio; i < fin && !result; i++)
			result = (*item == memBlock[i]);
	else
		for (len_t i = inicio; i < fin && !result; i++)
			result = (compare(item, memBlock + i) == 0);
	return result;
}
template<class T>
ll_int_t genericCompare_int(const void* item_a, const void* item_b) {
	ll_int_t result = 0;
	if ((*(T*)item_a) > (*(T*)item_b)) result = 1;
	else if ((*(T*)item_a) > (*(T*)item_b)) result = -1;
	return result;
}
template<class T>
ll_bool_t genericCompare_bool(const void* item_a, const void* item_b) {
	return (*(T*)item_a) == (*(T*)item_b);
}



/* Movimientos de memoria */
// Esta funcion es una version de "MemMove" que rellena los huecos vacios despues de mover datos
// Mueve datos de un bloque de memoria de posicion
// Usa la funcion "CopiarMemoria" y no "swap" para mover datos
// El signo de "unidadesDesplazar" selecciona la direccion donde se van a mover los items (+ ->) (- <-)
// Precondiciones:
//		memBlock != nullptr, nullValue != nullptr
//		posInicial >= 0, posFinal >= 0, sizeType > 0
//		posInicial < posFinal
//		unidadesDesplazar != 0
//		sizeType > 0
// Complejidad temporal y espacial: O(posFinal - posInicial + abs(unidadesDesplazar)) y M(1)
void memMoveEsp(
	// Bloque de memoria donde se quiere realizar el movimiento
	const void* memBlock,
	// Posicion inicial del comienzo del movimiento(Posicion incluida)
	const len_t& inicio,
	// Posicion final del movimiento
	const len_t& fin,
	// Tamaño en bytes del tipo de la memoria
	const len_t& sizeType,
	// Posiciones a desplazar y que direccion
	const len_t& unidadesDesplazar,
	// Si es en sentido positivo
	const ll_bool_t& adelante,
	// Objeto null del tipo guardado para rellenar los huecos
	const void* nullValue);
// Mueve datos de un bloque de memoria de posicion
// Usa la funcion "CopiarMemoria" y no "swap" para mover datos
// El signo de "unidadesDesplazar" selecciona la direccion donde se van a mover los items
// Precondiciones:
//		memBlock != nullptr
//		posInicial >= 0, posFinal >= 0, sizeType > 0
//		posInicial < posFinal
//		unidadesDesplazar != 0
// Complejidad temporal y espacial: O(posFinal - posInicial) y M(1)
void memMove(
	// Bloque de memoria donde se quiere realizar el movimiento
	const void* memBlock,
	// Posicion inicial del comienzo del movimiento(Posicion incluida)
	const len_t& inicio,
	// Posicion final del movimiento
	const len_t& fin,
	// Tamaño en bytes del tipo de la memoria
	const len_t& sizeType,
	// Posiciones a desplazar y que direccion
	const len_t& unidadesDesplazar,
	// Si es en sentido positivo
	const ll_bool_t& adelante);
// Cambia la posicion de los items de un vector contiguo (0 -> sizeBlock - 1) , (1 -> sizeBlock - 2)...
// Usa la funcion "Swap" por lo que, salirse de memoria dara error
// Precondiciones:
//		memBlock != nullptr
//		sizeBlock >= 0, sizeType > 0
// Complejidad temporal y espacial: O(sizeBlock/2) y M(sizeType)
void invertirBloque(
	// Bloque de memoria donde se quiere realizar el movimiento
	void* memBlock,
	// Tamaño de bloque
	const len_t& sizeBlock,
	// Tamaño del tipo en bytes
	const len_t& sizeType);
/* Memoria compartida */
// Funcion: Genera un puntero a una memoria compartida
// Extra: Solo funciona en unix
// Precondiciones:
//		bytes != 0
// Retorno: El puntero a la memoria compartida
// Complejidad temporal y espacial: O(1) y M(1)
void* reservarMemoriaCompartida(const len_t& bytes);
/* Templates */

template<class T>
T* __new__() { return new T(); }
template<class T>
T* __newArray__(const len_t& size) {
	T* result = nullptr;
	if(size > 0)
		result = new T[size];
	return result;
}
template<class T>
void __delete__(T** pointer) {
	if(pointer != nullptr && *pointer != nullptr) {
		delete *pointer;
		*pointer = nullptr;
	}
}
template<class T>
void __deleteArray__(T** pointer) {
	if(pointer != nullptr && *pointer != nullptr) {
		delete[] *pointer;
		*pointer = nullptr;
	}
}
template<class T>
void __del__(void** pointer) { __delete__(pointer); }
template<class T>
void __delArray__(void** pointer) { __deleteArray__(pointer); }

template<class T>
T* autoPointer(const T* memBlock, const len_t& posicion) {
	return (T*)autoPointer(memBlock, posicion, sizeof(T));
}
template<class T>
void swapContent(T* a, T* b) {
	T temp = *a;
	*a = *b;
	*b = temp;
}
template<class T>
void swapPointers(T* pointer_1, T* pointer_2) {
	T* temp = pointer_1;
	pointer_1 = pointer_2;
	pointer_2 = temp;
}

template<class T>
T* typerFunction(void* item) { return (T*)item; }


} /* namespace Mem */
} /* namespace Libs */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORELIB_SIMPLELIBS_MEMLIB_H_ */
