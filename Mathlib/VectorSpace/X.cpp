/*
 * X.cpp
 *
 *  Created on: Feb 6, 2021
 *      Author: llanyro
 */

#include "../../Mathlib/VectorSpace/X.h"

namespace Llanylib {
namespace Core {
namespace Math {
namespace VectorSpace {

X::X() : X(0) {}
X::X(const ll_coordinate_t& x) { this->x = x; }
X::~X() { this->x = 0; }
ll_coordinate_t X::getX() const { return this->x; }
void X::setX(const ll_coordinate_t& val) { this->x = val; }
void X::addX(const ll_coordinate_t& val) { this->x += val; }
ll_coordinate_t X::pow2() const { return this->x * this->x; }
ll_bool_t X::clear() {
	this->x = 0;
	return true;
}

} /* namespace VectorSpace */
} /* namespace Math */
} /* namespace Core */
} /* namespace Llanylib */
