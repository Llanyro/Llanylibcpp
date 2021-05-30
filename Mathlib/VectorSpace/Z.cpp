/*
 * Z.cpp
 *
 *  Created on: Feb 6, 2021
 *      Author: llanyro
 */

#include "../../Mathlib/VectorSpace/Z.h"

namespace Llanylib {
namespace Core {
namespace Math {
namespace VectorSpace {

Z::Z() : Z(0) {}
Z::Z(const ll_coordinate_t& z) { this->z = z; }
Z::~Z() { this->z = 0; }
ll_coordinate_t Z::getZ() const { return this->z; }
void Z::setZ(const ll_coordinate_t& val) { this->z = val; }
void Z::addZ(const ll_coordinate_t& val) { this->z += val; }
ll_coordinate_t Z::pow2() const { return this->z * this->z; }
ll_bool_t Z::clear() {
	this->z = 0;
	return true;
}

} /* namespace VectorSpace */
} /* namespace Math */
} /* namespace Core */
} /* namespace Llanylib */
