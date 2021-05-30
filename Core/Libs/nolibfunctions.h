/*
 * nolibfunctions.h
 *
 *  Created on: Mar 10, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_SIMPLELIBS_NOLIBFUNCTIONS_H_
#define LLANYLIB_CORE_SIMPLELIBS_NOLIBFUNCTIONS_H_

#include "llanytypeslib.h"

namespace Llanylib {
namespace Core {
namespace Structs { struct llanystring; }
namespace Libs {
namespace Nolib {

Structs::llanystring* getCommandsMain(int argc, char** argv, const ll_bool_t& ignoreFirst);

} /* namespace Nolib */
} /* namespace Libs */
} /* namespace Core */
} /* namespace Llanylibc */

#endif /* LLANYLIB_CORE_SIMPLELIBS_NOLIBFUNCTIONS_H_ */
