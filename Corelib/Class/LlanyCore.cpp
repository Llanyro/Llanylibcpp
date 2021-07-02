/*
 * LlanyCore.cpp
 *
 *  Created on: Nov 27, 2020
 *      Author: llanyro
 */

#include "LlanyCore.h"

namespace Llanylib {
namespace Corelib {
namespace Classes {

LlanyCore::LlanyCore() {}
LlanyCore::~LlanyCore() {}

ll_bool_t LlanyCore::clear() { return false; }
dynamic LlanyCore::hash() const { return nullptr; }
dynamic LlanyCore::toString() const { return nullptr; }
dynamic LlanyCore::serialize() const { return nullptr; }
void* LlanyCore::clone() const { return nullptr; }

} /* namespace Classes */
} /* namespace Corelib */
} /* namespace Llanylib */
