#pragma once
#include "ListaContigua.h"
#include "string"

using namespace std;

// Grafo dirigido, puede haber ciclos, pseudografo, no multigrafo, no conexo, no etiquetado.
class Grafo
{
protected:
	ListaContigua *matriz; // Apuntador al comienzo de un array de objetos de tipo lista. Cada uno ser� una fila de la matriz de adyacencia
	int n; // Numero de nodos
	string nombresNodos; // Lista de nombres de los nodos. Como el nombre de cada nodo es un car�cter, la lista es un string

	// Comprobamos si existe un arco entre dos nodos
	// Par�metros: 
	// - indiceNodoOrigen: el indice del nodo origen
	// - indiceNodoDestino: el indice del nodo destino
	// Retorno: true si existe el arco, false si no
	// Precondici�n: indiceNodoOrigen e indiceNodoDestino pertenece a [0, n-1]
	// Complejidad temporal y espacial: O(1)
	bool existeArco (int indiceNodoOrigen, int indiceNodoDestino);

	// Comprueba si existe un nodo en el grafo
	// Par�metro: nombre del nodo que queremos comprobar si est� en el grafo
	// Retorno: true si el nodo existe, false si no
	// Complejidad temporal: O(n) porque recorremos el vector de nombres para encontrar el nodo (b�squeda secuencial, pues los nodos est�n desordenados)
	// Complejidad espacial: O(1)
	bool existeNodo (char nombreNodo);

	// Obtiene el indice de un nodo (n�mero de columna o fila de la matriz de adyacencia en donde est�)
	// Par�metro: nombre del nodo cuyo �ndice se quiere obtener
	// Retorno: el �ndice del nodo (de 0 a n-1)
	// Precondici�n: el nodo cuyo nombre se proporciona existe dentro del grafo
	// Complejidad temporal: O(n) porque buscamos secuencialmente el nodo en la lista de nombres de nodos
	// Complejidad espacial: O(1)
	int obtenerIndice (char nombreNodo);

	// Devuelve el recorrido en profundidad del grafo
	// Par�metros: 
	// - �ndice del nodo inicial por el que empezar
	// - vistos: array en el cual en cada posicion es true si el nodo de esa posici�n ya ha sido visto, o false en caso contrario
	// Retorno: lista de caracteres con el recorrido en profundidad
	// Precondiciones: indiceNodoInicial pertenece a [0, n-1], vistos != NULL
	// Complejidad temporal: O(n^2) porque hay que sacar todos los nodos a una lista, y cada uno de ellos lo a�adimos 
	// al final de la lista (a�adir al final es O(n))
	// Complejidad espacial: O(n) si el grafo es lineal (un nodo detr�s de otro), porque como m�ximo tenemos n llamadas 
	// recursivas vivas a la vez. Adem�s creamos un array de n componentes (es lo que devolvemos)
	string recorrerEnProfundidadRecursivo(int indiceNodoInicial, bool *vistos);

public:

	// Crea un grafo vac�o
	// Complejidad temporal y espacial: O(1)
	Grafo();

	// Imprime el grafo por pantalla en forma de matriz de adyacencia, imprimiendo t�tulos de las columnas y filas
	// OJO: este m�todo viola el principio de separaci�n entre interfaz y modelo
	// Complejidad temporal: O(n^2) porque imprimimos todos los posibles arcos
	// Complejidad espacial: O(1)
	void imprimir();

	// Inserta un nodo desconectado en el grafo
	// Par�metro: nombre del nuevo nodo que queremos insertar
	// Precondici�n: no existe ning�n nodo en el grafo que tenga dicho nombre
	// Complejidad temporal y espacial: O(n^2) porque por dentro usamos una matriz temporal en la cual copiamos la matriz original 
	void insertarNodo (char nombreNodo);

	// Inserta un arco en el grafo
	// Par�metros: nombres del nodo origen y del nodo destino del arco que queremos a�adir
	// Precondici�n: los dos nodos deben existir previamente en el grafo
	// Complejidad temporal: O(n) porque hay que obtener el indice del nodo a partir de su nombre
	// Complejidad espacial: O(1)
	void insertarArco (char nodoOrigen, char nodoDestino);

	// Borra un arco del nodo
	// Par�metros: nombres del nodo origen y del nodo destino del arco que queremos eliminar
	// Precondici�n: los dos nodos deben existir previamente en el grafo
	// Complejidad temporal: O(n) porque hay que obtener el indice del nodo a partir de su nombre
	// Complejidad espacial: O(1)
	void borrarArco (char nodoOrigen, char nodoDestino);

	// Borrar un nodo del grafo. Borramos autom�ticamente todos los arcos que llegan y que parten del nodo a eliminar
	// Par�metro: nombre del nodo a eliminar
	// Precondici�n: el nodo debe previamente existir
	// Complejidad temporal y espacial: O(n^2) porque por dentro usamos una matriz temporal en la cual copiamos la matriz original 
	void borrarNodo (char nombreNodo);

	// Devuelve el recorrido en profundidad del grafo
	// Par�metro: 
	// - nombre del nodo por el que empezar el recorrido
	// - tamanoRecorrido: la funci�n depositar� aqu� el numero de nodos que tiene el recorrido
	// Retorno: puntero a comienzo de zona de memoria en donde se guarda el recorrido en forma de array de caracteres
	// Precondici�n: el nodo de comienzo debe existir en el grafo
	// Complejidad temporal: O(n^2) porque hay que sacar todos los nodos a una lista, y cada uno de ellos lo a�adimos 
	// al final de la lista (a�adir al final es O(n))
	// Complejidad espacial: O(n) si el grafo es lineal (un nodo detr�s de otro), porque como m�ximo tenemos n llamadas 
	// recursivas vivas a la vez. Adem�s creamos un array de n componentes (es lo que devolvemos)
	char *recorrerEnProfundidad(char nodoInicial, int *tamanoRecorrido);

	// Devuelve el n�mero de nodos del grafo
	// Retorno: n�mero de nodos del grafo
	// Complejidad temporal y espacial: O(1)
	int getN();
	
	// Destruye el grafo y libera la memoria de todos sus nodos
	// Complejidad temporal: O(n) porque hay que llamar al destructor de cada fila, el cual es O(1)
	// Complejidad espacial: O(1)
	~Grafo();
};

