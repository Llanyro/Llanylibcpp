/*
 * Point3.cpp
 *
 *  Created on: Feb 6, 2021
 *      Author: llanyro
 */

#include "../../Mathlib/VectorSpace/Point3.h"

namespace Llanylib {
namespace Core {
namespace Math {
namespace VectorSpace {


Point3::Point3() : Point3(0, 0, 0) {}
Point3::Point3(const ll_coordinate_t& x) : Point3(x, 0, 0) {}
Point3::Point3(const ll_coordinate_t& x, const ll_coordinate_t& y) : Point3(x, y, 0) {}
Point3::Point3(const ll_coordinate_t& x, const ll_coordinate_t& y, const ll_coordinate_t& z) : Point2(x, y), Z(z) {}
Point3::Point3(const Point& other) : Point2(other), Z(0) {}
Point3::Point3(const Point2& other) : Point2(other), Z(0) {}
Point3::Point3(const Point3& other) : Point3(other.getX(), other.getY(), other.getZ()) {}
ll_bool_t Point3::operator=(const Point& other) {
	Point3::clear();
	Point::operator=(other);
	return true;
}
ll_bool_t Point3::operator=(const Point2& other) {
	Point3::clear();
	Point2::operator=(other);
	return true;
}
ll_bool_t Point3::operator=(const Point3& other) {
	Point2::operator=(other);
	Z::setZ(other.z);
	return true;
}
Point3::~Point3() {}

Point3* Point3::operator+(const Point& other) const {
	Point3* v = new Point3(*this);
	v->operator+=(other);
	return v;
}
Point3* Point3::operator-(const Point& other) const {
	Point3* v = new Point3(*this);
	v->operator-=(other);
	return v;
}
Point3* Point3::operator+(const Point2& other) const {
	Point3* v = new Point3(*this);
	v->operator+=(other);
	return v;
}
Point3* Point3::operator-(const Point2& other) const {
	Point3* v = new Point3(*this);
	v->operator-=(other);
	return v;
}
Point3* Point3::operator+(const Point3& other) const {
	Point3* v = new Point3(*this);
	v->operator+=(other);
	return v;
}
Point3* Point3::operator-(const Point3& other) const {
	Point3* v = new Point3(*this);
	v->operator-=(other);
	return v;
}

void Point3::operator+=(const Point& other) { Point::operator+=(other); }
void Point3::operator-=(const Point& other) { Point::operator-=(other); }
void Point3::operator+=(const Point2& other) { Point2::operator+=(other); }
void Point3::operator-=(const Point2& other) { Point2::operator+=(other); }
void Point3::operator+=(const Point3& other) {
	Point2::operator+=(other);
	Z::addZ(other.y);
}
void Point3::operator-=(const Point3& other) {
	Point2::operator-=(other);
	Z::addZ(-other.y);
}

ll_bool_t Point3::clear() {
	Z::clear();
	return Point2::clear();
}

} /* namespace VectorSpace */
} /* namespace Math */
} /* namespace Core */
} /* namespace Llanylib */
