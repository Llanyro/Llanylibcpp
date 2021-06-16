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
String* LlanyCore::hash() const { return nullptr; }
String* LlanyCore::toString() const { return nullptr; }
String* LlanyCore::serialize() const { return nullptr; }
void* LlanyCore::clone() const { return nullptr; }

} /* namespace Classes */
} /* namespace Corelib */
} /* namespace Llanylib */
