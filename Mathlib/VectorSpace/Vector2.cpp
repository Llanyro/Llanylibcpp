/*
 * Vector2.cpp
 *
 *  Created on: Feb 6, 2021
 *      Author: llanyro
 */

#include "../../Mathlib/VectorSpace/Vector2.h"

namespace Llanylib {
namespace Core {
namespace Math {
namespace VectorSpace {

ll_coordinate_t Vector2::getNorm() const { return Vector::getNorm() * Y::pow2(); }

Vector2::Vector2() : Vector2(0, 0){}
Vector2::Vector2(const ll_coordinate_t& x) : Vector2(x, 0) {}
Vector2::Vector2(const ll_coordinate_t& x, const ll_coordinate_t& y) : Vector(x), Y(y){}

Vector2::Vector2(const Point& a, const Point& b) : Vector2(b.getX() - a.getX(), 0){}
Vector2::Vector2(const Point& a, const Point2& b) : Vector2(b.getX() - a.getX(), b.getY()){}
Vector2::Vector2(const Point2& a, const Point& b) : Vector2(b.getX() - a.getX(), -a.getY()){}
Vector2::Vector2(const Point2& a, const Point2& b) : Vector2(b.getX() - a.getX(), b.getY() - a.getY()){}

Vector2::Vector2(const Vector& other) : Vector(other), Y(0) {}
Vector2::Vector2(const Vector2& other) : Vector2(other.x, other.y){}
ll_bool_t Vector2::operator=(const Vector& other) {
	Vector::operator=(other);
	Y::setY(0);
	return true;
}
ll_bool_t Vector2::operator=(const Vector2& other) {
	Vector::operator=(other);
	Y::setY(other.y);
	return true;
}
Vector2::~Vector2() {}

Vector2* Vector2::operator+(const Vector& other) const {
	Vector2* v = new Vector2(*this);
	v->operator+=(other);
	return v;
}
Vector2* Vector2::operator-(const Vector& other) const {
	Vector2* v = new Vector2(*this);
	v->operator-=(other);
	return v;
}
Vector2* Vector2::operator+(const Vector2& other) const {
	Vector2* v = new Vector2(*this);
	v->operator+=(other);
	return v;
}
Vector2* Vector2::operator-(const Vector2& other) const {
	Vector2* v = new Vector2(*this);
	v->operator-=(other);
	return v;
}
Vector2* Vector2::operator*(const ll_coordinate_t& value) const {
	Vector2* v = new Vector2(*this);
	v->operator*=(value);
	return v;
}

void Vector2::operator+=(const Vector& other) { Vector::operator+=(other); }
void Vector2::operator-=(const Vector& other) { Vector::operator-=(other); }
void Vector2::operator+=(const Vector2& other) {
	Vector::operator+=(other);
	Y::addY(other.y);
}
void Vector2::operator-=(const Vector2& other) {
	Vector::operator-=(other);
	Y::addY(-other.y);
}
void Vector2::operator*=(const ll_coordinate_t& value) {
	Vector::operator*=(value);
	this->y *= value;
}

ll_bool_t Vector2::clear() {
	Y::clear();
	return Vector::clear();
}

} /* namespace VectorSpace */
} /* namespace Math */
} /* namespace Core */
} /* namespace Llanylib */
