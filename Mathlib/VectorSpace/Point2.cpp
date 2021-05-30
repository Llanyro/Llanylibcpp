/*
 * Point2.cpp
 *
 *  Created on: Feb 6, 2021
 *      Author: llanyro
 */

#include "../../Mathlib/VectorSpace/Point2.h"

namespace Llanylib {
namespace Core {
namespace Math {
namespace VectorSpace {

Point2::Point2() : Point2(0, 0) {}
Point2::Point2(const ll_coordinate_t& x) : Point2(x, 0) {}
Point2::Point2(const ll_coordinate_t& x, const ll_coordinate_t& y) : Point(x), Y(y) {}
Point2::Point2(const Point& other) : Point(other), Y(0) {}
Point2::Point2(const Point2& other) : Point2(other.x, other.y) {}
ll_bool_t Point2::operator=(const Point& other) {
	Point::operator=(other);
	Y::setY(0);
	return true;
}
ll_bool_t Point2::operator=(const Point2& other) {
	Point::operator=(other);
	Y::setY(other.y);
	return true;
}
Point2::~Point2() {}
Point2* Point2::operator+(const Point& other) const {
	Point2* v = new Point2(*this);
	v->operator+=(other);
	return v;
}
Point2* Point2::operator-(const Point& other) const {
	Point2* v = new Point2(*this);
	v->operator-=(other);
	return v;
}
Point2* Point2::operator+(const Point2& other) const {
	Point2* v = new Point2(*this);
	v->operator+=(other);
	return v;
}
Point2* Point2::operator-(const Point2& other) const {
	Point2* v = new Point2(*this);
	v->operator-=(other);
	return v;
}
void Point2::operator+=(const Point& other) { Point::operator+=(other); }
void Point2::operator-=(const Point& other) { Point::operator-=(other); }
void Point2::operator+=(const Point2& other) {
	Point::operator+=(other);
	Y::addY(other.y);
}
void Point2::operator-=(const Point2& other) {
	Point::operator-=(other);
	Y::addY(-other.y);
}

ll_bool_t Point2::clear() {
	Y::clear();
	return Point::clear();
}

} /* namespace VectorSpace */
} /* namespace Math */
} /* namespace Core */
} /* namespace Llanylib */
