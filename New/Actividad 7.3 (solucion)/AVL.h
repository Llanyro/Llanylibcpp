#pragma once
#include "Nodo.h"

// �rbol binario de b�squeda del tipo AVL. Se permiten duplicados, y �stos van hacia la izquierda
class AVL
{
	Nodo *raiz; // Raiz del �rbol, o NULL si el arbol est� vac�o
	int n; // Numero de nodos del arbol

public:

	// Construye un �rbol binario de b�squeda vac�o
	// Complejidad temporal y espacial: O(1)
	AVL();

	// Inserta un elemento, asegurandose de que el �rbol siga siendo AVL al terminar
	// Par�metro: nuevo elemento a insertar. 
	// Complejidad temporal y espacial: O(lgn)
	void insertar(int nuevoElemento);

	// Imprime el �rbol en forma de esquema tabulado
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(lgn)
	void imprimir();

	// Destruye el �rbol, liberando la memoria de todos los nodos
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(lgn)
	~AVL();

protected:

	// Inserta un elemento (siempre se insertar� como hoja), como si fuera un arbol binario de busqueda normal
	// Par�metro: nuevo elemento a insertar. Lo coloca en su sitio adecuado
	// Retorno: puntero al nodo insertado
	// Complejidad temporal y espacial: O(lgn)
	Nodo* insertarHoja(int nuevoElemento);
	
	// Reequilibra el arbol AVL despues de insertar una hoja, empezando por dicha hoja y ascendiendo hasta la raiz
	// Par�metro: hoja desde la que empezamos a subir
	// Precondicion: hoja != NULL
	// Complejidad temporal: O(logn)
	// Complejidad espacial: O(1)
	void reequilibrar(Nodo *hoja);

	// Imprime un subarbol por pantalla en forma de esquema, sangrando los hijos con una tabulaci�n. Esta pensado para ser recursivo
	// Par�metros:
	// - subarbol: nodo ra�z del subarbol que queremos imprimir
	// - numeroTabulaciones: numero de tabulaciones con la que imprimimos la raiz. Los hijos directos tendr�n una tabulaci�n m�s
	// - orientacion indica si subarbol (primer parametro) es un hijo izquierdo de su padre (-1) o es derecho (+1) o no tiene padre (0)
	// Precondicion: subarbol != NULL
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(lgn)
	// (n es el n�mero de nodos del subarbol)
	void imprimirRecursivo(Nodo *subarbol, int numeroTabulaciones, int orientacion);

	// Elimina recursivamente los nodos de un subarbol
	// Par�metro: el nodo ra�z del subarbol a eliminar
	// Precondici�n: subarbol != NULL
	// Complejidad temporal: O(n)
	// Complejidad espacial: O(lgn)
	// (n es el n�mero de nodos del subarbol)
	void eliminarSubarbol(Nodo *subarbol);

	// Busca recursivamente el padre del hueco en donde podemos insertar un nuevo elemento dado
	// Par�metros:
	// - raizSubarbol indica la ra�z del subarbol en donde buscar
	// - elementoABuscar indica el elemento que nos gustar�a insertar y cuyo hueco queremos encontrar
	// Retorno: puntero al nodo padre del hueco en donde podr�amos poner elementoAInsertar
	// Precondicion: raizSubarbol != NULL
	// Complejidad temporal y espacial: O(lgn), n es el n�mero de nodos del subarbol
	Nodo *buscarHueco(Nodo *raizSubarbol, int elementoAInsertar);

	// Implementa, en un subarbol, una rotaci�n simple a la izquierda
	// Parametro: ra�z del nodo ra�z del subarbol en donde se har� la rotaci�n
	// Retorno: puntero a la nueva raiz del subarbol
	// Precondiciones:
	// - El nodo ra�z existe y tiene un factor de equilibrio de 2
	// - Su hijo derecho existe y tiene un factor de equilibrio de 1
	// Complejidad temporal y espacial: O(1)
	Nodo* rotarSimpleIzquierda(Nodo *raizSubarbol);

	// Implementa, en un subarbol, una rotaci�n simple a la derecha
	// Parametro: ra�z del nodo ra�z del subarbol en donde se har� la rotaci�n
	// Retorno: puntero a la nueva raiz del subarbol
	// Precondiciones:
	// - El nodo ra�z existe y tiene un factor de equilibrio de -2
	// - Su hijo izquierdo existe y tiene un factor de equilibrio de -1
	// Complejidad temporal y espacial: O(1)
	Nodo* rotarSimpleDerecha(Nodo *raizSubarbol);

	// Implementa, en un subarbol, una rotaci�n compuesta derecha-izquierda
	// Parametro: ra�z del nodo ra�z del subarbol en donde se har� la rotaci�n
	// Retorno: puntero a la nueva raiz del subarbol
	// Precondiciones:
	// - El nodo ra�z existe y tiene un factor de equilibrio de 2
	// - Su hijo derecho existe y tiene un factor de equilibrio de -1
	// Complejidad temporal y espacial: O(1)
	Nodo* rotarCompuestaDerechaIzquierda(Nodo *raizSubarbol);

	// Implementa, en un subarbol, una rotaci�n compuesta izquierda-derecha
	// Parametro: ra�z del nodo ra�z del subarbol en donde se har� la rotaci�n
	// Retorno: puntero a la nueva raiz del subarbol
	// Precondiciones:
	// - El nodo ra�z existe y tiene un factor de equilibrio de -2
	// - Su hijo izquierdo existe y tiene un factor de equilibrio de 1
	// Complejidad temporal y espacial: O(1)
	Nodo* rotarCompuestaIzquierdaDerecha(Nodo *raizSubarbol);

	// Hace que el padre de antiguoHijo apunte en su lugar a nuevoHijo
	// Par�metros:
	// - antiguoHijo: nodo cuyo padre dejar� de apuntarle
	// - nuevoHijo: queremos que el padre de antiguoHijo pase a apuntar a nuevoHijo
	// Precondici�n: antiguoHijo != NULL
	// Complejidad temporal y espacial: O(1)
	void cambiarHijo(Nodo *antiguoHijo, Nodo *nuevoHijo);

};



