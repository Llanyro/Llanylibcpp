/*
	Test de prubas de herencia y de liberacion de punteros

	Este test ha sido creado para probar las siguientes cosas:
		Que pasa cuando se hereda una clase, la cual posee un puntero el cual gestiona y la clase hija es liberada
		Que pasa si se pasa por parametro una clase Padre o abuela, y esta se libera con delete


	Explicacion del ejemplo:
		En el siguiente ejemplo tenemos 3 clases: Abuelo, Padre e Hijo.
		Hijo hereda de Padre y Padre a su vez de Abuelo.
		Cada clase define en si misma un puntero a un dato en concreto(indiferente cual)
		Se crea una funcion que trabajara solo con clases de tipo 'Abuelo' [delete_abu]
		En la funcion main, creamos el objeto Hijo, que sera con el cual trabajaremos
		Como la funcion 'delete_abu' solo trabaja con Abuelo, el objeto que tenemos, hay que castearlo a Abuelo, ya que este hereda de Padre y a su vez de Abuelo, se hace automaticamente
		La funcion 'delete_abu'
			Deberia de:
				Liberar el puntero del objeto Hijo que hemos creado asi como lo heredado
			O bien:
				Liberar solo la parte correspondiente de Abuelo

	Resultados:
		Siempre y cuando la todas las clases tengan el destuctor como virtual, pasara por todos los destructores
		Si una clase heredada o similar, no tiene destructor virtual, al llamar a la clase hija casteada como clase padre o superior, se llamara al destructor de la clase padre o superior
			haciendo que, puedan quedar datos por liberar

*/
#pragma once
class Abuelo {
	protected:
		int* edad;
	public:
		Abuelo(int edad) { this->edad = new int(edad); }
		virtual ~Abuelo() { delete this->edad; }
};

class Padre : public Abuelo {
	protected:
		char* sexo;
	public:
		Padre(int edad, char sexo) : Abuelo(edad) { this->sexo = new char(sexo); }
		virtual ~Padre() { delete this->sexo; }
};

class Hijo : public Padre {
	protected:
		float* value;
	public:
		Hijo(int edad, char sexo, float value) : Padre(edad, sexo) { this->value = new float(value); }
		virtual ~Hijo() { delete this->value; }
};

void delete_abu(Abuelo* abu) { delete abu; }

int herencia_and_delete() {
	Hijo* h = new Hijo(10, 'c', 0.1f);

	delete_abu(h);

	return 0;
}