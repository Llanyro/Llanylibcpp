/*
 * randomlib.h
 *
 *  Created on: Nov 25, 2020
 *      Author: llanyro
 */

#ifndef LLANYLIB_BASIC_SIMPLELIBS_RANDOMLIB_H_
#define LLANYLIB_BASIC_SIMPLELIBS_RANDOMLIB_H_

#include "llanytypeslib.h"

#define RANDOM_LIB Llanylib::Core::Libs::Random

namespace Llanylib {
namespace Core {

namespace Classes {
	namespace SimpleLists {
		template<class T, const len_t lenght>
		class FixedVector;
	}
}

namespace Libs {
namespace Random {

void setSeed(const ll_uint32_t* seed);
ll_uint32_t getRAND_MAX();

// Funcion: Genera un numero entero random entre 0 y RAND_MAX
// Version: Final
// Retorno: Numero aleatorio
// Complejidad temporal y espacial: O(1) y M(1)
ll_uint32_t random();
// Funcion: Genera un numero entero random entre 0 y value
// Version: Final
// Retorno: Numero aleatorio
// Complejidad temporal y espacial: O(1) y M(1)
ll_uint32_t range(const ll_uint32_t& value);
// Funcion: Devuelve un numero entero random entre min y max
// Version: Final
// Retorno: Numero aleatorio
// Complejidad temporal y espacial: O(1) y M(1)
ll_uint32_t range(const ll_uint32_t& min, const ll_uint32_t& max);

// Funcion: Genera un numero flotante random entre 0 y 1
// Version: Final
// Retorno: Numero aleatorio
// Complejidad temporal y espacial: O(1) y M(1)
ll_ldouble_t randomf();
// Funcion: Genera un numero flotante random entre 0 y value o -value
// Version: Final
// Retorno: Numero aleatorio
// Complejidad temporal y espacial: O(1) y M(1)
ll_ldouble_t rangef(const ll_ldouble_t& value);
// Funcion: Genera un numero flotante random entre min y max
// Version: Final
// Retorno: Numero aleatorio
// Complejidad temporal y espacial: O(1) y M(1)
ll_ldouble_t rangef(const ll_ldouble_t& min, const ll_ldouble_t& max);

ll_bool_t randomBool();

char getRandomChar(char const* const items, const len_t& len);
char getRandomChar(void* items, const len_t& len, const len_t& size);

char randomASCIIChar();
char randomCharAbecedario();
char randomCharEspecial();
char randomCharNumber();
char randomCharAbecedarioOrNumber();
char randomCharVisible();

Classes::SimpleLists::FixedVector<ll_float_t, 4>* randomBoxMuller();
// Sobrescribe un grupo de valores anteriormente usado para no regenerar la memoria
ll_bool_t randomBoxMuller(Classes::SimpleLists::FixedVector<ll_float_t, 4>* values);


} /* namespace Random */
} /* namespace Libs */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* LLANYLIB_BASIC_SIMPLELIBS_RANDOMLIB_H_ */
