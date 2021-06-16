/*
 * filelib.cpp
 *
 *  Created on: Jun 8, 2021
 *      Author: llanyro
 */

#include "filelib.h"

#include "stringlib.h"
#include "memlib.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

#ifdef _WIN32
#pragma warning(disable:4996)
#endif // _WIN32

namespace Llanylib {
namespace Corelib {
namespace Libs {
namespace File {

ll_bool_t directory_exist(const char* dirname) {
	struct stat st = {0};
	return stat(dirname, &st) != -1;
}
ll_bool_t file_exist(const char* filename) {
	FILE* file = fopen(filename, "wx");
	ll_bool_t result = (file == nullptr);
	if(!result) fclose(file);
	return result;
}
ll_bool_t dir_exist_create(const char* dirname, const len_t& lenght) {
	ll_bool_t result = false;
	if(!directory_exist(dirname)) {
		const char* c = nullptr;
		#ifdef _WIN32
		c = "mkdir ";
		#elif __unix__
		c = "mkdir -p ";
		#endif // _WIN32
		ll_uint64_t c_len = STRLEN_DEFINED_STRING(c);
		ll_uint64_t len = lenght + c_len + 1;
		char* command = new char[len];
		Mem::copiarMemoria(command, c, 0, c_len, sizeof(char));
		Mem::copiarMemoria(command + c_len, dirname, 0, lenght, sizeof(char));
		command[len - 1] = '\0';
		system(command);
		delete command;
	}
	else result = false;
	return result;
}
ll_bool_t remove_file(const char* filename) { return remove(filename) == 0; }

} /* namespace File */
} /* namespace Libs */
} /* namespace Core */
} /* namespace Llanylib */
