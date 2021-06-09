/*
 * randomlib.cpp
 *
 *  Created on: Nov 25, 2020
 *      Author: llanyro
 */

#include "randomlib.h"

#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <float.h>
#include <math.h>

//#include "llanymathtypeslib.h"
#include "asciidefines.h"
#include "memlib.h"
#include "../Classes/SimpleLists/Vector.h"

//#include "../SimpleStructs/llanymultireturn.h"

namespace Llanylib {
namespace Core {
namespace Libs {
namespace Random {

void setSeed(const ll_uint32_t* seed) {
	if(seed == nullptr) srand(time(NULL));
	else srand(*seed);
}
ll_uint32_t getRAND_MAX() { return RAND_MAX; }

ll_uint32_t random() { return rand(); }
ll_uint32_t range(const ll_uint32_t& value) { return (rand() % value); }
ll_uint32_t range(const ll_uint32_t& min, const ll_uint32_t& max) {
	assert(max > min);
	return (range(max - min) + min);
}

ll_ldouble_t randomf() { return (((ll_ldouble_t)rand()) / RAND_MAX); }
ll_ldouble_t rangef(const ll_ldouble_t& value) { return randomf() * value; }
ll_ldouble_t rangef(const ll_ldouble_t& min, const ll_ldouble_t& max) {
	ll_ldouble_t result = 0;
	if(max >= min) { // 2, 5 // -5, -2 , -2, 5
		// Ambos positivos
		if(min >= 0 && max >= 0) // 2, 5
			result = (rangef(max - min) + min);
		else if(min < 0 && max < 0) // -5, -2
			result = (rangef(max - min) + min);
		else
			result = rangef(max - min) + min;
	}
	else
		result = rangef(max, min);
	return result;
}

ll_bool_t randomBool() { return (range(2) == 0) ? true : false; }

char getRandomChar(char const* const items, const len_t& len) {
	return items[range(len)];
}
char getRandomChar(void* items, const len_t& len, const len_t& size) {
	return *(char*)MEM_LIB::autoPointer(items, range(len), size);
}

char randomASCIIChar() { return (char)range(ASCII_CHARS); }
char randomCharAbecedario() { return getRandomChar(ABECEDARIO_1, ABECEDARIO_1_LEN); }
char randomCharEspecial() {
	char c = 33;
	switch (range(3)) {
		case 0:
			c = (char)range(33, 43);
			break;
		case 1:
			c = (char)range(58, 65);
			break;
		case 2:
			c = (char)range(123, 127);
			break;
	}
	return c;
}
char randomCharNumber() { return getRandomChar(CHARS_NUMS, CHARS_NUMS_LEN); }
char randomCharAbecedarioOrNumber() { return getRandomChar(ABECEDARIO_NUMS_1, ABECEDARIO_NUMS_1_LEN); }
char randomCharVisible() { return getRandomChar(VISIBLE_CHARS, VISIBLE_CHARS_LEN); }

Classes::SimpleLists::FixedVector<ll_float_t, 4>* randomBoxMuller() {
    /*do {
        result.results[0] = randomf();
        result.results[1] = randomf();
    } while (result.results[0] <= FLT_MIN);

	ll_float_t raiz = sqrt(-2 * log(result.results[0]));
	ll_float_t two_pi_u2 = TWO_PI_VAL * result.results[1];

	result.results[2] = raiz * cos(two_pi_u2);
	result.results[3] = raiz * sin(two_pi_u2);*/
	/*
	 * result.results[0] = random float 1
	 * result.results[1] = random float 2
	 * result.results[2] = r * cos(FI) = sqrt(-2 * ln(U1)) * cos(2 * PI * U2);
	 * result.results[3] = r * sin(FI) = sqrt(-2 * ln(U1)) * sin(2 * PI * U2);
	 **/
	Classes::SimpleLists::FixedVector<ll_float_t, 4>* result = new Classes::SimpleLists::FixedVector<ll_float_t, 4>();
	randomBoxMuller(result);
	return result;
}
ll_bool_t randomBoxMuller(Classes::SimpleLists::FixedVector<ll_float_t, 4>* values) {
	ll_bool_t resultado = false;
	if(values != nullptr) {
	    do {
	    	values->set(randomf(), 0);
	    	values->set(randomf(), 1);
	    } while (values->operator[](0) <= FLT_MIN);

		ll_float_t raiz = sqrt(-2 * log(values->operator [](0)));
		ll_float_t two_pi_u2 = TWO_PI_VAL * values->operator[](1);

		values->set(raiz * cos(two_pi_u2), 2);
		values->set(raiz * sin(two_pi_u2), 3);
	}
	return resultado;
}


} /* namespace Random */
} /* namespace Libs */
} /* namespace Core */
} /* namespace Llanylib */
