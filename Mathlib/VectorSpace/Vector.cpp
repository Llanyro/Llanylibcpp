/*
 * Vector.cpp
 *
 *  Created on: Feb 6, 2021
 *      Author: llanyro
 */

#include "../../Mathlib/VectorSpace/Vector.h"

namespace Llanylib {
namespace Core {
namespace Math {
namespace VectorSpace {

ll_coordinate_t Vector::getNorm() const { return X::pow2(); }

Vector::Vector() : Vector(0){}
Vector::Vector(const ll_coordinate_t& x) : X(x){}
Vector::Vector(const Point& a, const Point& b) : Vector(b.getX() - a.getX()){}
Vector::Vector(const Vector& other) : Vector(other.x){}
ll_bool_t Vector::operator=(const Vector& other) {
	X::setX(other.x);
	return true;
}
Vector::~Vector() {}

Vector* Vector::operator+(const Vector& other) const {
	Vector* v = new Vector(*this);
	v->operator+=(other);
	return v;
}
Vector* Vector::operator-(const Vector& other) const {
	Vector* v = new Vector(*this);
	v->operator-=(other);
	return v;
}
Vector* Vector::operator*(const ll_coordinate_t& value) const {
	Vector* v = new Vector(*this);
	v->operator*=(value);
	return v;
}

void Vector::operator+=(const Vector& other) { X::addX(other.x); }
void Vector::operator-=(const Vector& other) { X::addX(-other.x); }
void Vector::operator*=(const ll_coordinate_t& value) { this->x *= value; }

ll_coordinate_t Vector::norm() const { return this->getNorm(); }

ll_bool_t Vector::clear() { return X::clear(); }

} /* namespace VectorSpace */
} /* namespace Math */
} /* namespace Core */
} /* namespace Llanylib */
