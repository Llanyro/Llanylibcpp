/*
 * Y.cpp
 *
 *  Created on: Feb 6, 2021
 *      Author: llanyro
 */

#include "../../Mathlib/VectorSpace/Y.h"

namespace Llanylib {
namespace Core {
namespace Math {
namespace VectorSpace {

Y::Y() : Y(0) {}
Y::Y(const ll_coordinate_t& y) { this->y = y; }
Y::~Y() { this->y = 0; }
ll_coordinate_t Y::getY() const { return this->y; }
void Y::setY(const ll_coordinate_t& val) { this->y = val; }
void Y::addY(const ll_coordinate_t& val) { this->y += val; }
ll_coordinate_t Y::pow2() const { return this->y * this->y; }
ll_bool_t Y::clear() {
	this->y = 0;
	return true;
}

} /* namespace VectorSpace */
} /* namespace Math */
} /* namespace Core */
} /* namespace Llanylib */
