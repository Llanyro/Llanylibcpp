/*
 * Point.cpp
 *
 *  Created on: Feb 6, 2021
 *      Author: llanyro
 */

#include "../../Mathlib/VectorSpace/Point.h"

namespace Llanylib {
namespace Core {
namespace Math {
namespace VectorSpace {

Point::Point() : Point(0) {}
Point::Point(const ll_coordinate_t& x) : X(x) {}
Point::Point(const Point& other) : Point(other.x) {}
ll_bool_t Point::operator=(const Point& other) {
	X::setX(other.x);
	return true;
}
Point::~Point() {}

Point* Point::operator+(const Point& other) const {
	Point* v = new Point(*this);
	v->operator+=(other);
	return v;
}
Point* Point::operator-(const Point& other) const {
	Point* v = new Point(*this);
	v->operator-=(other);
	return v;
}

void Point::operator+=(const Point& other) { X::addX(other.x); }
void Point::operator-=(const Point& other) { X::addX(-other.x); }

ll_bool_t Point::clear() { return X::clear(); }

} /* namespace VectorSpace */
} /* namespace Math */
} /* namespace Core */
} /* namespace Llanylib */
