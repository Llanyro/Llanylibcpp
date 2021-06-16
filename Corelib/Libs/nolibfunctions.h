/*
 * nolibfunctions.h
 *
 *  Created on: Mar 10, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORELIB_SIMPLELIBS_NOLIBFUNCTIONS_H_
#define LLANYLIB_CORELIB_SIMPLELIBS_NOLIBFUNCTIONS_H_

#include "llanytypeslib.h"

namespace Llanylib {
namespace Corelib {
namespace Classes { class String; }
namespace Libs {
namespace Nolib {

Classes::String* getCommandsMain(int argc, char** argv, const ll_bool_t& ignoreFirst);

} /* namespace Nolib */
} /* namespace Libs */
} /* namespace Core */
} /* namespace Llanylibc */

#endif /* LLANYLIB_CORELIB_SIMPLELIBS_NOLIBFUNCTIONS_H_ */
