/*
 * filelib.h
 *
 *  Created on: Jun 8, 2021
 *      Author: llanyro
 */

#ifndef CORE_LIBS_FILELIB_H_
#define CORE_LIBS_FILELIB_H_

#include "llanytypeslib.h"

namespace Llanylib {
namespace Core {
namespace Libs {
namespace File {

ll_bool_t directory_exist(char const* const dirname);
ll_bool_t file_exist(char const* const dirname);
ll_bool_t dir_exist_create(char const* const dirname);
ll_bool_t remove_file(char const* const filename);

} /* namespace File */
} /* namespace Libs */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* CORE_LIBS_FILELIB_H_ */
