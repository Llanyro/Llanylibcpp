/*
 * mathlib.cpp
 *
 *  Created on: Nov 26, 2020
 *      Author: llanyro
 */

#include "mathlib.h"

#include <math.h>
#include <assert.h>

//#include "../Structs/llanylinkedlist.h"
//#include "../Classes/SimpleLists/List.h"

namespace Llanylib {
namespace Corelib {
namespace Libs {
namespace Math {

/* Comparadores y similares*/
ll_bool_t similar(const ll_ldouble_t& value_1, const ll_ldouble_t& value_2, const ll_ldouble_t& margen) {
	return betwenValuesX(value_2, value_1 - margen, value_1 + margen);
}
ll_bool_t similar(const ll_ldouble_t& value_1, const ll_ldouble_t& value_2) {
	return (((ll_longlong_t)value_1) == ((ll_longlong_t)value_2));
}
ll_int_t compare(const ll_ulong_t& a, const ll_ulong_t& b) {
	ll_int_t res = 0;
	if (a > b) res = 1;
	else if (b > a) res = -1;
	return res;
}
ll_int_t compare(const ll_ulonglong_t& a, const ll_ulonglong_t& b) {
	ll_int_t res = 0;
	if (a > b) res = 1;
	else if (b > a) res = -1;
	return res;
}
ll_int_t compare(const ll_longlong_t& a, const ll_longlong_t& b) {
	ll_int_t res = 0;
	if (a > b) res = 1;
	else if (b > a) res = -1;
	return res;
}
ll_int_t compare(const ll_ldouble_t& a, const ll_ldouble_t& b) {
	ll_int_t res = 0;
	if (a > b) res = 1;
	else if (b > a) res = -1;
	return res;
}
ll_bool_t isPrime(const ll_uint64_t& num) {
	/*
	 * if n ≤ 1 return FALSE
    else if n ≤ 3 return TRUE
    else if (n mod 2 = 0) or (n mod 3 = 0) return FALSE
    i = 5
    while (i*i ≤ n) {
      if (n mod i = 0) or (n mod (i + 2) = 0) return FALSE
      i = i + 6
    }
    return TRUE
	 *
	 *
	 * */
	ll_bool_t result = false;
	if(num <= 3)
		result = num > 1;
	else if(num % 2 != 0 && num % 3 != 0) {
		result = true;
		for (ll_uint64_t i = 5; result && (i * i) <= num; i += 6)
			result = !(num % i == 0 || num % (i + 2) == 0);
	}
	return result;
}
ll_uint64_t getDivisor(const ll_uint64_t& num) {
	ll_uint64_t result = 1;
	if (num % 2 == 0)
		result = 2;
	else if (num % 3 == 0)
		result = 3;
	else {
		for (ll_uint64_t i = 5; (i * i) <= num; i += 6)
			if (num % i == 0 || num % (i + 2) == 0) {
				result = i;
				i = num;
			}
	}
	return result;
}
ll_uint64_t isPrime_2(const ll_uint64_t& num) { return getDivisor(num); }


/* Operaciones simples O(1) */
ll_uint64_t sum(const ll_uint64_t* a, const ll_uint64_t* b) { return (*a + *b); }
ll_uint64_t sub(const ll_uint64_t* a, const ll_uint64_t* b) { return (*a - *b); }
ll_void sum(ll_uint64_t* a, const ll_uint64_t* b) { *a += *b; } // @suppress("No return")
ll_void sub(ll_uint64_t* a, const ll_uint64_t* b) { *a -= *b; } // @suppress("No return")
ll_uint64_t valorAbsoluto(const ll_uint64_t& valor) {
	ll_uint64_t resultado = 0;
	if (valor >= 0) resultado = valor;
	else resultado -= valor;
	return valor;
}


/* Operaciones simples O(n) */
ll_uint64_t factorial(const ll_uint64_t& value) { 
	return (value >= 0) ? (value * factorial(value - 1)) : 1;
}
//ll_uint64_t pow(const ll_uint64_t& base, const ll_uint64_t& exp) { return (exp > 0) ? (base * pow(base, exp - 1)) : 1; }
//ll_float_t powf(const ll_float_t& base, const ll_uint64_t& exp) { return (exp > 0) ? (base * powf(base, exp - 1)) : 1; }
//ll_double_t powd(const ll_double_t& base, const ll_uint64_t& exp) { return (exp > 0) ? (base * powd(base, exp - 1)) : 1; }
//ll_ldouble_t powld(const ll_ldouble_t& base, const ll_uint64_t& exp) { return (exp > 0) ? (base * powld(base, exp - 1)) : 1; }
ll_uint64_t mod(const ll_uint64_t& a, const ll_uint64_t& b) {
	assert(b != 0);
	return (a - ((a / b) * b));
}
ll_uint64_t sumatorioSimple(const ll_uint64_t& inicio, const ll_uint64_t& fin, const ll_uint64_t& n) {
	assert(inicio < fin);
	ll_uint64_t temp = 0;
	for (ll_uint64_t i = inicio; i < fin; i += n) temp += i;
	return temp;
}
ll_uint64_t euclidesSimple(const ll_uint64_t& num, const ll_uint64_t& num2) {
	assert(num >= num2);
	return (num2 != 0) ? (euclidesSimple(num2, num % num2)) : num;
}
ll_uint64_t numeroDeCifras(const ll_uint64_t& num) { return numeroDeCifras(num, 10); }
ll_uint64_t numeroDeCifras(const ll_uint64_t& num, const ll_uint64_t& num2) {
	assert(num >= 0);
	assert((num2 % 10) == 0);
	return (num != 0) ? (1 + numeroDeCifras(num - (num % num2), num2 * 10)) : 1;
}
ll_uint64_t generateCoprime(const ll_uint64_t& num, const ll_uint64_t& min, const ll_uint64_t& max) {
	ll_uint64_t result = min;
	if(result < 6) result = 6;
	while(result < num)
		if(euclidesSimple(num, result) == 1) break;
		else result++;
	return result;
}
ll_uint64_t generateCoprime(const ll_uint64_t& num) { return generateCoprime(num, 0, num); }


/* Funciones complejas (Neuronal) O(1) */
ll_float_t getSigmoid(const ll_float_t& value) {
	return (1 / (1 + expf(-1 * value)));
	//return (1 / (1 + elevarValor(E_VAL, (-1 * value))));
}
ll_float_t getSigmoidDeriv(const ll_float_t& value) { return (value * (1 - value)); }
ll_float_t getMaxVSZero(const ll_float_t& value) { return GET_MAX(0, value); }
ll_float_t isHigherThanZero(const ll_float_t& value) { return value > 0; }
ll_double_t getTanH(const ll_double_t& value) { return tanh(value); }
ll_float_t getTanHDeriv(const ll_float_t& value) { return 1 - (value * value); }
ll_float_t linearDeriv(const ll_float_t& value) { return 1.0; }

/* Funciones complejas propias O(1)*/
/*Classes::SimpleLists::List<ll_uint64_t>* uniqueDivisors(const ll_uint64_t& num) {
	assert(num != 0);

	Classes::SimpleLists::List<ll_uint64_t>* l = new Classes::SimpleLists::List<ll_uint64_t>();
	ll_bool_t continuar = true;
	ll_uint64_t temp = 0, modVal = num;

	// Agregamos el numero propio como divisor
	l->add(num);

	while (continuar) {
		// Encontramos un divisor cualquiera
		temp = getDivisor(modVal);

		// Si el divisor es igual que el numero -> es primo
		if (temp == modVal)
			continuar = false;

		// Dividimos el numero por su divisor
		modVal /= temp;

		// Si el numero no es primo
		if (temp != 1)
			// Dividimos el numero por su divisor hasta que no hayan mas divisores iguales
			while (modVal % temp == 0) modVal /= temp;
		// Si el numero es primo
		else {
			if (temp != modVal && modVal != num)
				// Agregamos el numero a la lista
				l->add(modVal);
			continuar = false;
		}

		// Agregamos el numero a la lista
		l->add(temp);
	}

	return l;
}*/
/*ll_uint64_t eulerFi(const ll_uint64_t& num) {
	/*SIMPLE_LISTS::List<ll_uint64_t>* l = SIMPLE_LISTS::newlist<ll_uint64_t>();
	ll_bool_t continuar = true;
	ll_uint64_t temp = 0, modVal = base;

	while (continuar) {
		// Encontramos un divisor cualquiera
		temp = isPrime_2(modVal);

		// Si no contiene el numero, lo agregamos a la lista
		if (!SIMPLE_LISTS::contains(l, &temp)) {

		}




	}









	ll_uint64_t* nums = new ll_uint64_t[base/2];
	len_t len = 0;
	ll_uint64_t temp = 0, modVal = base;
	ll_bool_t continuar = true;

	while(continuar) {
		// Encontramos un divisor cualquiera
		temp = isPrime_2(modVal);

		// Si
		if(temp != 1) {
			modVal /= temp;

			if(!MEM_LIB::contains(nums, 0, len, &temp, nullptr)) {
				nums[len] = temp;
				len++;
			}



		}
		else continuar = false;
	}*

	// Si la lista recibida de uniqueDivisors() es 0
	// El resultado es num - 1
	// Else FI = num * (1 - (1 / div_1)) ... * (1 - (1 / div_n))
	ll_uint64_t result = 0;
	Classes::SimpleLists::List<ll_uint64_t>* l = uniqueDivisors(num);

	if (l->len() == 0)
		result = num - 1;
	else {
		result = 1;
	}

	return result;
}*/
char* solveDiophantineEquationLinear(const ll_ulonglong_t& a, const ll_ulonglong_t& b, const ll_ulonglong_t& c) {
	//
	/*
	 * 16x + 70y = 300
	 * 16x == 70 mod 300
	 *
	 *
	 *
	 * */

	return nullptr;
}




} /* namespace Math */
} /* namespace Libs */
} /* namespace Core */
} /* namespace Llanylib */
