/*
 * filelib.cpp
 *
 *  Created on: Jun 8, 2021
 *      Author: llanyro
 */

#include "filelib.h"

#include "stringlib.h"

#include <stdio.h>
#include <sys/stat.h>

namespace Llanylib {
namespace Core {
namespace Libs {
namespace File {

ll_bool_t directory_exist(char const* const dirname) {
	struct stat st = {0};
	return stat(dirname, &st) != -1;
}
ll_bool_t file_exist(char const* const dirname) {
	FILE* file = fopen(dirname, "wx");
	ll_bool_t result = (file == nullptr);
	if(!result) fclose(file);
	return result;
}
ll_bool_t dir_exist_create(char const* const dirname) {
	ll_bool_t result = false;

	if(!directory_exist(dirname)) {
		const char* c = "mkdir -p";




		ll_uint64_t c_len = STRLEN_DEFINED_STRING(c);



		ll_uint64_t dir_len = String::vectorLen(dirname);
		ll_uint64_t len = dir_len + c_len + 1;
		char* command = new char[len];
		Mem::copiarMemoria(command, c, 0, c_len, sizeof(char));
		Mem::copiarMemoria(command + c_len, dirname, 0, dir_len, sizeof(char));
		command[len - 1] = '\0';
		system(command);
	}
	else result = false;
	return result;
}
ll_bool_t remove_file(char const* const filename) { return remove(filename) == 0; }

} /* namespace File */
} /* namespace Libs */
} /* namespace Core */
} /* namespace Llanylib */
