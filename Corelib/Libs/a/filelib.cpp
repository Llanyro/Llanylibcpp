#include "filelib.h"

#include <stdio.h>

LLANY_STRING::llanystring* readFile(char* filename) {
	/*LLANY_STRING::llanystring* result = nullptr;
	FILE* f = fopen(filename, "rb");
	if (f != nullptr) {
		// Nos colocamos al final del file
		fseek(f, 0, SEEK_END);
		result = LLANY_STRING::newLlanyString((len_t)ftell(f));
		// Nos colocamos al inicio del file
		fseek(f, 0, SEEK_SET);
		// Copiamos el file
		fread(result->str, 1, result->len, f);
		LLANY_STRING::fixLlanyString(result);
		fclose(f);
	}
	return result;*/
	return nullptr;
}



#include <iostream>

using namespace std;;

int main44() {
	std::cout << "Hola mundo!" << std::endl;
	return 0;
}
