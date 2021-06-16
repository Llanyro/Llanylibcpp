/*
 * Number.h
 *
 *  Created on: Jun 15, 2021
 *      Author: llanyro
 */

#ifndef MATHLIB_CORE_NUMBER_H_
#define MATHLIB_CORE_NUMBER_H_

#include "Enums/Bases.h"

namespace Llanylib {
namespace Mathlib {
namespace Core {


/*
 * Controla y gestiona un numero con el valor desde -INF hasta INF
 * Utiliza un algoritmo u otro, segun la base indocada
 * Las bases que soporta en este momento son:
 * 	B256 y B4294967295
 *
 * */
class Number {
public:
	Number();
	Number(const Enums::EnumBases& base);
	virtual ~Number();
	Number(const Number &other);
	Number(Number &&other);
	Number& operator=(const Number &other);
	Number& operator=(Number &&other);
};

} /* namespace Core */
} /* namespace Mathlib */
} /* namespace Llanylib */

#endif /* MATHLIB_CORE_NUMBER_H_ */
