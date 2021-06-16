/*
 * memlib.cpp
 *
 *  Created on: Nov 16, 2020
 *      Author: llanyro
 */

#include "memlib.h"

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

namespace Llanylib {
namespace Core {
namespace Libs {
namespace Mem {

/* Punteros */
void* autoPointer(const void* memBlock, const len_t& posicion, const len_t& sizeType) {
	assert(memBlock != nullptr);
	assert(sizeType > 0);
	assert(posicion >= 0);
	return ((char*)memBlock) + (sizeType * posicion);
}
void* autoPointer(const void* memBlock,
	const len_t& posicionX, const len_t& posicionY, const len_t& sizeType,
	const len_t& sizeSubBlockType, const len_t& sizeSubBlock) {
	assert(memBlock != nullptr);
	assert(sizeType > 0);
	assert(sizeSubBlockType > 0);
	assert(sizeSubBlock > 0);
	assert(posicionX >= 0);
	assert(posicionY >= 0);
	return autoPointer(autoPointer(memBlock, posicionX, sizeSubBlock * sizeSubBlockType), posicionY, sizeType);
}
/* Control de memoria */
void* reservarMem(const len_t& bytes) {
	assert(bytes > 0);
	return malloc(bytes);
}
void* copiarMemoria(void* dest, const void* memBlock,
	const len_t& inicio, const len_t& fin, const len_t& sizeType) {
	assert(dest != nullptr);
	assert(memBlock != nullptr);
	assert(inicio >= 0);
	assert(fin >= 0);
	assert(fin > inicio);
	assert(sizeType > 0);
	if(inicio > 0)
		dest = memcpy(dest, autoPointer(memBlock, inicio, sizeType), (fin - inicio) * sizeType);
	else
		dest = memcpy(dest, memBlock, (fin - inicio) * sizeType);
	return dest;
}
void* reservarYCopiar(const void* memBlock,
	const len_t& inicio, const len_t& fin, const len_t& sizeType) {
	assert(memBlock != nullptr);
	assert(inicio >= 0);
	assert(fin >= 0);
	assert(fin > inicio);
	assert(sizeType > 0);
	void* memRes = reservarMem((fin - inicio) * sizeType);
	copiarMemoria(memRes, memBlock, inicio, fin, sizeType);
	return memRes;
}
void* resize(void* memBlock, const len_t& sizeBlock, const len_t& sizeType) {
	assert(memBlock != nullptr);
	assert(sizeType > 0);
	assert(sizeBlock >= 0);
	return realloc(memBlock, sizeBlock * sizeType);
}
len_t sizeBlock_b(void* memBlock) {
	assert(memBlock != nullptr);
	#ifdef _WIN32
	return _msize(memBlock);
	#elif __unix__
	return malloc_usable_size(memBlock);
	#endif // _WIN32
}
void liberarSimple(void* pointerToMemBlock) {
	assert(pointerToMemBlock != nullptr);
	free(pointerToMemBlock);
}
void liberar(void** pointerToMemBlock) {
	assert(pointerToMemBlock != nullptr);
	assert(*pointerToMemBlock != nullptr);
	free(*pointerToMemBlock);
	*pointerToMemBlock = nullptr;
}
void swap(void* memBlock_a, void* memBlock_b,
	const len_t& sizeBlock, const len_t& sizeType) {
	assert(memBlock_a != nullptr);
	assert(memBlock_b != nullptr);
	assert(sizeType > 0);
	assert(sizeBlock > 0);

	//Reservamos el espacio en memoria que queremos mover y lo copiamos
	void* memtemp = reservarYCopiar(memBlock_a, 0, 1, sizeBlock * sizeType);
	//Realizamos el swap con memcpy
	memcpy(memBlock_a, memBlock_b, sizeBlock * sizeType);
	memcpy(memBlock_b, memtemp, sizeBlock * sizeType);

	//Libaremos la memoria reservada temporal
	liberar(&memtemp);
}
ll_int8_t compareMemoryBlocks(const void* block1, const len_t& size_1, const void* block2, const len_t& size_2, const len_t& sizeType, Compare_int compare) {
	assert(compare != nullptr);
	ll_int8_t result = 0;
	if (block1 == nullptr && block2 == nullptr) result = 0;	// Iguales
	else if (block1 == nullptr) result = -1;				// Bloque 2 mayor
	else if (block2 == nullptr) result = 1;					// Bloque 1 mayor
	else if (size_1 > size_2) result = 1;					// Bloque 1 mayor
	else if (size_1 < size_2) result = -1;					// Bloque 2 mayor
	else {														// Mismo tama�o
		for (size_t i = 0; result == 0 && i < size_1; i++)
			result = compare(
				autoPointer(block1, i, sizeType),
				autoPointer(block2, i, sizeType));
	}
	return result;
}
/* Busquedas */
ll_bool_t buscarObjeto(const void* memBlock,
	const len_t& inicio, const len_t& fin, const len_t& sizeType,
	const void* item, Compare_int compare) {
	assert(memBlock != nullptr);
	assert(item != nullptr);
	assert(compare != nullptr);
	assert(sizeType > 0);
	assert(inicio >= 0);
	assert(fin >= 0);
	assert(fin > inicio);
	ll_bool_t result = false;
	for (len_t i = inicio; i < fin && !result; i++)
		result = (compare(autoPointer(memBlock, i, sizeType), item) == 0);
	return result;
}
ll_bool_t buscarObjetoInvertido(const void* memBlock,
	const len_t& inicio, const len_t& fin, const len_t& sizeType,
	const void* item, Compare_int compare) {
	assert(memBlock != nullptr);
	assert(item != nullptr);
	assert(compare != nullptr);
	assert(sizeType > 0);
	assert(inicio >= 0);
	assert(fin >= 0);
	assert(fin > inicio);
	ll_bool_t result = false;
	for (len_t i = fin - 1; i > inicio && !result; i--)
		result = (compare(autoPointer(memBlock, i, sizeType), item) == 0);
	return result;
}
len_t buscarPosicionObjetoMenor(const void* memBlock,
	const len_t& inicio, const len_t& fin, const len_t& sizeType,
	Compare_int compare) {
	assert(memBlock != nullptr);
	assert(compare != nullptr);
	assert(sizeType > 0);
	assert(inicio >= 0);
	assert(fin >= 0);
	assert(fin > inicio);
	len_t posMenor = inicio;
	for (len_t i = inicio + 1; i < fin; i++)
		if (compare(
			autoPointer(memBlock, posMenor, sizeType),
			autoPointer(memBlock, i, sizeType)) == 1)
			posMenor = i;
	return posMenor;
}
/* Movimientos de memoria */
void memMoveEsp(const void* memBlock,
	const len_t& inicio, const len_t& fin, const len_t& sizeType,
	const len_t& unidadesDesplazar, const bool& adelante, const void* nullValue) {
	assert(memBlock != nullptr);
	assert(nullValue != nullptr);
	assert(inicio >= 0);
	assert(fin >= 0);
	assert(fin > inicio);
	assert(sizeType > 0);
	memMove(memBlock, inicio, fin, sizeType, unidadesDesplazar, adelante);
	if (adelante) {
		//O(unidadesDesplazar)
		for (len_t i = inicio; i < inicio + unidadesDesplazar; i++)
			copiarMemoria(
				autoPointer(memBlock, i, sizeType), nullValue, 0, 1, sizeType);
	}
	else {
		//O(unidadesDesplazar)
		for (len_t i = fin - unidadesDesplazar; i < fin; i++)
			copiarMemoria(
				autoPointer(memBlock, i, sizeType), nullValue, 0, 1, sizeType);
	}
}
void memMove(const void* memBlock,
	const len_t& inicio, const len_t& fin, const len_t& sizeType,
	const len_t& unidadesDesplazar, const bool& adelante) {
	assert(memBlock != nullptr);
	assert(inicio >= 0);
	assert(fin >= 0);
	assert(fin > inicio);
	assert(sizeType > 0);
	if (adelante) {
		//O(fin - inicio)
		for (len_t i = fin - 1; i > inicio; i--)
			copiarMemoria(
				autoPointer(memBlock, i, sizeType),
				autoPointer(memBlock, i - unidadesDesplazar, sizeType), 0, 1, sizeType);
	}
	else {
		//O(fin - inicio)
		for (len_t i = inicio; i < fin - 1; i++)
			copiarMemoria(
				autoPointer(memBlock, i, sizeType),
				autoPointer(memBlock, i + unidadesDesplazar, sizeType), 0, 1, sizeType);
	}
}
void invertirBloque(void* memBlock,
	const len_t& sizeBlock, const len_t& sizeType) {
	assert(memBlock != nullptr);
	assert(sizeType > 0);
	assert(sizeBlock > 0);
	for (len_t i = 0; i < (sizeBlock / 2); i++)
		swap(
			autoPointer(memBlock, i, sizeType),
			autoPointer(memBlock, sizeBlock - 1 - i, sizeType), 1, sizeType);
}
/* Memoria compartida */
void* reservarMemoriaCompartida(const len_t& bytes) {
	assert(bytes > 0);
	void* memoria = nullptr;
	#ifdef _WIN32

	#elif __unix__
	//memoria = mmap(NULL, bytes, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	#endif // _WIN32
	return memoria;
}

} /* namespace Mem */
} /* namespace Libs */
} /* namespace Core */
} /* namespace Llanylibc */
