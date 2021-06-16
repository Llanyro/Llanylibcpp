/*
 * llanystring.h
 *
 *  Created on: Nov 28, 2020
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORELIB_SIMPLESTRUCTS_LLANYSTRING_H_
#define LLANYLIB_CORELIB_SIMPLESTRUCTS_LLANYSTRING_H_

#include "../Libs/llanytypeslib.h"

#define LLANY_STRING Llanylib::Core::Structs::String

namespace Llanylib {
namespace Corelib {
namespace Structs {
namespace String {

struct string {
	char* str = nullptr;
	len_t len = 0;
	ll_bool_t free = false; // Comentario
};

// Funcion: Genera un llanystring con un vector de tamaño len [len + 1]
// Extra: Se reserva una posicion mas para el '\0'[len + 1]
// Version: Final
// Retorno: SimpleString con tamaño solicitado
// Complejidad temporal y espacial: O(1) y M(n + 1)
string* newLlanyString(const len_t& len);
// Funcion: Genera un SimpleString, apuntando el contenido a conststr
// Extra: Recuerda que el contenido consta como constante por lo que no se libera
// Version: Final
// Precondiciones:
//		conststr != nullptr
// Retorno: SimpleString con el str y el tamaño apuntados
// Complejidad temporal y espacial: O(1) y M(1)
string* newLlanyString(char const* const conststr);
// Funcion: Setea el valor de la ultima posicion a '\0'
// Version: Final
// Complejidad temporal y espacial: O(1) y M(1)
void fixLlanyString(string* str);
// Funcion: Elimina el objeto y libera el string contenido
// Version: Final
// Complejidad temporal y espacial: O(1) y M(1)
void deleteLlanyString(string* str);

string* cloneLlanyString(const string* str);
ll_bool_t compareLlanyString(string* str, string* str2);

} /* namespace String */
} /* namespace Structs */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORELIB_SIMPLESTRUCTS_LLANYSTRING_H_ */
