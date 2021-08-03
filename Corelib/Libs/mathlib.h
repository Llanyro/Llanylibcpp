/*
 * mathlib.h
 *
 *  Created on: Nov 26, 2020
 *      Author: llanyro
 */

#ifndef CORELIB_LIBS_MATHLIB_H_
#define CORELIB_LIBS_MATHLIB_H_

#include "llanytypeslib.h"
#include "llanymathtypeslib.h"

#define MATH_LIB Llanylib::Corelib::Libs::Math

namespace Llanylib {
namespace Corelib {

namespace Classes {
	namespace SimpleLists {
		template<class T>
		class List;
	}
}

namespace Libs {
namespace Math {

/* Comparadores y similares*/

// Funcion: Usa un algoritmo simple para comprobar si el valor 2 esta a rango de del valor 2
// Version: Final/Beta/Alfa/PreAlfa
// Retorno:
//		True:  Si el value 2 esta entre [value 1 y value 1 + margen] y entre [value 1 y value 1 - margen]
//		False: Value 2 no esta cerca de value 1
// Complejidad temporal y espacial: O(1) y M(1)
ll_bool_t similar(const ll_ldouble_t& value_1, const ll_ldouble_t& value_2, const ll_ldouble_t& margen);
// Funcion: Castea alos valores a un valor entero y comprueba que son el mismo
// Extra: Se pueden perder datos! 16 bits -> 8 bits
// Version: Final/Beta/Alfa/PreAlfa
// Retorno:
//		True:  Si ambos valores son el mismo
//		False: Si ambos valores son distintos
// Complejidad temporal y espacial: O(1) y M(1)
ll_bool_t similar(const ll_ldouble_t& value_1, const ll_ldouble_t& value_2);
ll_int_t compare(const ll_ulong_t& a, const ll_ulong_t& b);
ll_int_t compare(const ll_ulonglong_t& a, const ll_ulonglong_t& b);
ll_int_t compare(const ll_longlong_t& a, const ll_longlong_t& b);
ll_int_t compare(const ll_ldouble_t& a, const ll_ldouble_t& b);
template<class T>
ll_int_t compare(const T* a, const T* b) {
	ll_int_t res = 0;
	if (*a > *b) res = 1;
	else if (*b > *a) res = -1;
	return res;
}
// Funcion: Usa un algoritmo que no recuerdo para ver si es un primo
// Extra: Nada
// Version: Final
// Precondiciones:
//		num != 0
// Retorno:
//		true: Es primo
//		false: No es primo
// Complejidad temporal y espacial: O(1) y M(1)
ll_bool_t isPrime(const ll_uint64_t& num);
// Funcion: Usa un algoritmo para encontrar el primer divisor
// Version: Final
// Precondiciones:
//		num != 0
// Retorno:
//		1: Es primo y no tiene divisores
//		n: No es primo y n es divisor
// Complejidad temporal y espacial: O(1) y M(1)
ll_uint64_t getDivisor(const ll_uint64_t& num);
ll_uint64_t isPrime_2(const ll_uint64_t& num);
// Funcion: Realiza una comprobacion simple para ver si un valor esta comprendido entre otros 2
// Extra: Los extremos (min/max) cuentan para la comprobacion
// Version: Final/Beta/Alfa/PreAlfa
// Retorno:
//		True: Si el valor esta entre min y max
//		False: !True
// Complejidad temporal y espacial: O(1) y M(1)
template<class T>
ll_bool_t betwenValues(const T& value, const T& min, const T& max) {
	return (value >= min && value <= max);
}
// Funcion: Realiza una comprobacion simple para ver si un valor esta comprendido entre otros 2
// Extra: Los extremos (min/max) no cuentan
// Version: Final/Beta/Alfa/PreAlfa
// Retorno:
//		True: Si el valor esta entre min y max
//		False: !True
// Complejidad temporal y espacial: O(1) y M(1)
template<class T>
ll_bool_t betwenValuesX(const T& value, const T& min, const T& max) {
	return (value > min && value < max);
}
// Funcion: Calcula el sumatorio de un conjunto de numeros
// Version: Final
// Precondiciones:
//		set != nullptr
// Retorno: El sumatorio de los numeros del conjunto
// Complejidad temporal y espacial: O(n) y M(1)
template<class T>
T sumSet(const T* set, const len_t& size) {
	T result = 0;
	for (len_t i = 0; i < size; ++i)
		result += set[i];
	return result;
}
// Funcion: Calcula el producto de un conjunto de numeros
// Version: Final
// Precondiciones:
//		set != nullptr
// Retorno: El producto de los numeros del conjunto
// Complejidad temporal y espacial: O(n) y M(1)
template<class T>
T prodSet(const T* set, const len_t& size) {
	T result = 1;
	for (len_t i = 0; i < size; ++i)
		result *= set[i];
	return result;
}

/* Operaciones simples O(1) */
ll_uint64_t sum(const ll_uint64_t* a, const ll_uint64_t* b);
ll_uint64_t sub(const ll_uint64_t* a, const ll_uint64_t* b);
ll_void sum(ll_uint64_t* a, const ll_uint64_t* b);
ll_void sub(ll_uint64_t* a, const ll_uint64_t* b);
// Funcion: Procesa un valor para dejarlo en su forma absoluta
// Version: Beta
// Retorno: El valor absoluto del valor introduciodo
// Complejidad temporal y espacial: O(1) y M(1)
ll_uint64_t valorAbsoluto(const ll_uint64_t& valor);
// Fast 1 / sqrt(x)
// Error: 1%
// Url: https://www.youtube.com/watch?v=p8u_k2LIZyo
ll_float_t q_rsqrt(const ll_float_t& number);

/* Operaciones simples O(n) */

// Funcion: Realiza los calculos para obtener el factorial de un numero
// Version: Beta
// Retorno: Factorial de el numero procesado
//		Si value == 0 devuelve 1
// Complejidad temporal y espacial: O(value) y M(1)
ll_uint64_t factorial(const ll_uint64_t& value);
// Funcion: Multiplica un numero por si mismo tantas veces como el exponente indica
// Version: Beta
// Retorno: El valor del numero procesado
//		Resultado
//		Si base es 0 devuelve 0 siempre
//		Si el exponente es 0 devuelve 1 siempre(exceptuando caso anterior)
// Complejidad temporal y espacial: O(exp) y M(1)
//ll_uint64_t pow(const ll_uint64_t& base, const ll_uint64_t& exp);
//ll_float_t powf(const ll_float_t& base, const ll_uint64_t& exp);
//ll_double_t powd(const ll_double_t& base, const ll_uint64_t& exp);
//ll_ldouble_t powld(const ll_ldouble_t& base, const ll_uint64_t& exp);
template<class T>
T pow(const T& base, const ll_uint64_t& exp) { return (base > 0) ? ((exp > 0) ? (base * pow<T>(base, exp - 1)) : 1) : 0; }
ll_uint64_t mod(const ll_uint64_t& a, const ll_uint64_t& b);
template<class T>
T mod(const T& a, const T& b) {
	T result = 0;
	if(a < 0) result = b + ( (a - ((a / b) * b)));
	else result = (a - ((a / b) * b));
	return result;
}
// Funcion: Realiza un sumatorio de inicio hasta fin de n en n
// Version: Beta
// Precondiciones:
//		inicio < fin
// Retorno: Valor del sumatorio
// Complejidad temporal y espacial: O( (fin - inicio) / n) y M(1)
ll_uint64_t sumatorioSimple(const ll_uint64_t& inicio, const ll_uint64_t& fin, const ll_uint64_t& n);
// Funcion: Realiza el calculo para obtener el MCD de dos elementos
// Version: Alfa
// Precondiciones:
//		num > 0 && num2 > 0
//		num >= num2
// Retorno: El maximo comun divisor de dos numeros
// Complejidad temporal y espacial: O(?) y M(1)
ll_uint64_t euclidesSimple(const ll_uint64_t& num, const ll_uint64_t& num2);
// Funcion: Procesa un numero para ver de cuantas cifras es (Sin decimales)
// Version: Beta
// Retorno: Numero de cifras de un numero
// Complejidad temporal y espacial: O(numero de cifras) y M(1)
ll_uint64_t numeroDeCifras(const ll_uint64_t& num);
// Funcion: Procesa un numero para ver de cuantas cifras es
// Version: Beta
// Precondiciones:
//		num2 == 10
// Retorno: Numero de cifras de un numero
// Complejidad temporal y espacial: O(numero de cifras) y M(1)
ll_uint64_t numeroDeCifras(const ll_uint64_t& num, const ll_uint64_t& num2);
ll_uint64_t generateCoprime(const ll_uint64_t& num, const ll_uint64_t& min, const ll_uint64_t& max);
ll_uint64_t generateCoprime(const ll_uint64_t& num);


/* Funciones complejas (Neuronal) O(1) */
ll_float_t getSigmoid(const ll_float_t& value);
ll_float_t getSigmoidDeriv(const ll_float_t& value);
ll_float_t getMaxVSZero(const ll_float_t& value);
ll_float_t isHigherThanZero(const ll_float_t& value);
ll_double_t getTanH(const ll_double_t& value);
ll_float_t getTanHDeriv(const ll_float_t& value);
ll_float_t linearDeriv(const ll_float_t& value);

/* Funciones complejas propias O(1) */
// Si devuelve len 0 -> es un numero primo
//Classes::SimpleLists::FixedVector<ll_float_t, 4>* uniqueDivisors(const ll_uint64_t& base);
ll_uint64_t eulerFi(const ll_uint64_t& base);



ll_ulonglong_t modPow();
char* solveDiophantineEquationLinear(const ll_uint64_t& a, const ll_uint64_t& b, const ll_ulonglong_t& c);




ll_uint64_t gerneratePrime();

} /* namespace Math */
} /* namespace Libs */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* CORELIB_LIBS_MATHLIB_H_ */
