/*
 * filelib.h
 *
 *  Created on: Jun 8, 2021
 *      Author: llanyro
 */

#ifndef CORE_LIBS_FILELIB_H_
#define CORE_LIBS_FILELIB_H_

#include "llanytypeslib.h"

#define FILE_LIB Llanylib::Core::Libs::File

namespace Llanylib {
namespace Corelib {
namespace Libs {
namespace File {

ll_bool_t directory_exist(const char* dirname);
ll_bool_t file_exist(const char* filename);
ll_bool_t dir_exist_create(const char* dirname, const len_t& lenght);
ll_bool_t remove_file(const char* filename);

} /* namespace File */
} /* namespace Libs */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* CORE_LIBS_FILELIB_H_ */
