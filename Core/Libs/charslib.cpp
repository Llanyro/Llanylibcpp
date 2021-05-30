/*
 * charslib.cpp
 *
 *  Created on: Mar 7, 2021
 *      Author: llanyro
 */

#include <assert.h>

#include "charslib.h"
#include "asciidefines.h"

namespace Llanylib {
namespace Core {
namespace Libs {
namespace Chars {

ll_int_t compareCharSimilar(const void* caracter1, const void* caracter2) {
	return compareCharSimilar((const char*)caracter1, (const char*)caracter2);
}
ll_int_t compareChar(const void* caracter1, const void* caracter2) {
	return compareChar((const char*)caracter1, (const char*)caracter2);
}

ll_int_t compareCharSimilar(const char* caracter1, const char*  caracter2) {
	assert(caracter1 != nullptr);
	assert(caracter2 != nullptr);
	ll_int_t resultado = 0;
	if (*caracter1 == *caracter2) resultado = 0;				// Ambos son iguales
	else {
		// Tipo de caracteres
		ll_int_t caracterType1 = isAlphabet(caracter1);
		ll_int_t caracterType2 = isAlphabet(caracter2);

		// Si ambos caracteres son del alfabeto
		// Si ambos son de tipo diferente(Mayus y minus)
		if (caracterType1 != 0 && caracterType2 != 0 && caracterType1 != caracterType2) {

			// Si la primera es mayus (La segunda minus)
			if (caracterType1 == 1 && (*caracter1 + DIFERENCIA_MAYUS_MINUS) == *caracter2)
				resultado = 0;
			// Si la primera es minus (La segunda mayus)
			else if (caracterType1 == -1 && (*caracter1 - DIFERENCIA_MAYUS_MINUS) == *caracter2)
				resultado = 0;
			else
				resultado = -2;
		}
		else if (*caracter1 > * caracter2) resultado = 1;			// Caracter 1 mayor
		else if (*caracter1 < *caracter2) resultado = -1;			// Caracter 2 mayor
		else
			resultado = -3;
	}
	return resultado;
}
ll_bool_t similarChar(const char* caracter1, const char* caracter2) {
	return compareCharSimilar(caracter1, caracter2) == 0;
}
ll_int_t compareChar(const char* caracter1, const char* caracter2) {
	assert(caracter1 != nullptr);
	assert(caracter2 != nullptr);
	int resultado = 0;
	if (*caracter1 == *caracter2) resultado = 0;		// Ambos son iguales
	else if (*caracter1 > *caracter2) resultado = 1;	// Caracter 1 mayor
	else if (*caracter1 < *caracter2) resultado = -1;	// Caracter 2 mayor
	else resultado = -2;								// Other
	return resultado;
}
ll_int_t isAlphabet(const char* caracter) {
	assert(caracter != nullptr);
	ll_int_t result = 0;											// Other
	if (*caracter > 64 && *caracter < 91) result = 1;		// Mayus
	else if (*caracter > 96 && *caracter < 123) result = -1;// Minus
	return result;
}
ll_int_t cambiarMayus(char* caracter) {
	assert(caracter != nullptr);

	ll_int_t resultado = isAlphabet(caracter) * -1;
	if(resultado == 1)
		*caracter -= DIFERENCIA_MAYUS_MINUS;
	return resultado;
}
ll_int_t cambiarMinus(char* caracter) {
	assert(caracter != nullptr);

	ll_int_t resultado = isAlphabet(caracter);
	if(resultado == 1)
		*caracter += DIFERENCIA_MAYUS_MINUS;
	return resultado;
}

} /* namespace Chars */
} /* namespace Libs */
} /* namespace Core */
} /* namespace Llanylib */
