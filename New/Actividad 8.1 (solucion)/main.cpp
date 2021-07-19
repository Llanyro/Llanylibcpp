#include "iostream"
#include "Grafo.h"
#include "string"

using namespace std;

// Prueba: introducir el grafo de la diapositiva 19 (OJO: al ser no dirigido, hay que meter los dos sentidos por cada arco) y recorrerlo en profundidad desde C y desde E

void main () {

	// Creamos el grafo
	Grafo grafo;

	int opcion;
	do {

		char nuevoNombre; // Nuevo nombre de un nodo
		char nodoABorrar; // Nombre de un nodo a borrar
		char nodoOrigen, nodoDestino; // Nodos origen y destino de un arco
		int tamanoRecorrido; // Guardará el número de nodos del recorrido en profundidad

		cout << "0. Salir" << endl;
		cout << "1. Insertar nuevo nodo" << endl;
		cout << "2. Insertar nuevo arco" << endl;
		cout << "3. Borrar nodo" << endl;
		cout << "4. Borrar arco" << endl;
		cout << "5. Imprimir" << endl;
		cout << "6. Recorrer en profundidad" << endl;
		cout << "Introduce opcion: ";
		cin >> opcion;

		switch (opcion) {
		case (0): // Terminar programa
			break;
		case (1):
			cout << "Escriba el nuevo nombre del nodo (una letra): ";
			cin >> nuevoNombre;
			grafo.insertarNodo(nuevoNombre);
			break;
		case (2):
			cout << "Escriba el nombre del nodo origen del arco (debe existir): ";
			cin >> nodoOrigen;
			cout << "Escriba el nombre del nodo destino del arco (debe existir): ";
			cin >> nodoDestino;
			grafo.insertarArco(nodoOrigen, nodoDestino);
			break;
		case (3):
			cout << "Escriba el nombre del nodo a borrar (una letra): ";
			cin >> nodoABorrar;
			grafo.borrarNodo(nodoABorrar);
			break;
		case (4):
			cout << "Escriba el nombre del nodo origen del arco a borrar: ";
			cin >> nodoOrigen;
			cout << "Escriba el nombre del nodo destino del arco a borrar: ";
			cin >> nodoDestino;
			grafo.borrarArco(nodoOrigen, nodoDestino);
			break;
		case (5):
			grafo.imprimir();
			break;
		case (6):
			if (grafo.getN() == 0) cout << "El grafo esta vacio y por lo tanto no hay recorrido en profundidad\n";
			else {
				cout << "Escriba el nombre del nodo origen del recorrido en profundidad: ";
				cin >> nodoOrigen;
				char *recorrido = grafo.recorrerEnProfundidad(nodoOrigen, &tamanoRecorrido); // Guarda el recorrido en profundidad en forma de array de caracteres
				cout << "Recorrido en profundidad: " << recorrido[0];
				for (int i=1; i<tamanoRecorrido; i++) cout << ", " << recorrido[i];
				cout << endl;
			}
			break;
		default:
			cout << "Opcion incorrecta" << endl;
			break;
		}
	} while (opcion != 0);


}
