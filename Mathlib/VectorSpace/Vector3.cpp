/*
 * Vector3.cpp
 *
 *  Created on: Feb 6, 2021
 *      Author: llanyro
 */

#include "../../Mathlib/VectorSpace/Vector3.h"

namespace Llanylib {
namespace Core {
namespace Math {
namespace VectorSpace {

ll_coordinate_t Vector3::getNorm() const { return Vector2::getNorm() * Z::pow2(); }

Vector3::Vector3() : Vector3(0, 0, 0){}
Vector3::Vector3(const ll_coordinate_t& x) : Vector3(x, 0, 0){}
Vector3::Vector3(const ll_coordinate_t& x, const ll_coordinate_t& y) : Vector3(x, y, 0){}
Vector3::Vector3(const ll_coordinate_t& x, const ll_coordinate_t& y, const ll_coordinate_t& z) : Vector2(x, y), Z(z) {}

Vector3::Vector3(const Point& a, const Point& b) : Vector3(b.getX() - a.getX(), 0, 0){}
Vector3::Vector3(const Point& a, const Point2& b) : Vector3(b.getX() - a.getX(), b.getY(), 0){}
Vector3::Vector3(const Point2& a, const Point& b) : Vector3(b.getX() - a.getX(), -a.getY(), 0){}
Vector3::Vector3(const Point2& a, const Point2& b) : Vector3(b.getX() - a.getX(), b.getY() - a.getY(), 0){}
Vector3::Vector3(const Point& a, const Point3& b) : Vector3(b.getX() - a.getX(), b.getY(), b.getZ()){}
Vector3::Vector3(const Point2& a, const Point3& b) : Vector3(b.getX() - a.getX(), b.getY() - a.getY(), b.getZ()){}
Vector3::Vector3(const Point3& a, const Point3& b) : Vector3(b.getX() - a.getX(), b.getY() - a.getY(), b.getZ() - a.getZ()){}
Vector3::Vector3(const Point3& a, const Point2& b) : Vector3(b.getX() - a.getX(), b.getY() - a.getY(), -a.getZ()){}
Vector3::Vector3(const Point3& a, const Point& b) : Vector3(b.getX() - a.getX(), -a.getY(), -a.getZ()){}

Vector3::Vector3(const Vector& other) : Vector2(other), Z(0) {}
Vector3::Vector3(const Vector2& other) : Vector2(other), Z(0) {}
Vector3::Vector3(const Vector3& other) : Vector3(other.x, other.y, other.z){}
ll_bool_t Vector3::operator=(const Vector& other) {
	Vector::operator=(other);
	Y::setY(0);
	Z::setZ(0);
	return true;
}
ll_bool_t Vector3::operator=(const Vector2& other) {
	Vector2::operator=(other);
	Z::setZ(0);
	return true;
}
ll_bool_t Vector3::operator=(const Vector3& other) {
	Vector2::operator=(other);
	Z::setZ(other.z);
	return true;
}
Vector3::~Vector3() {}

Vector3* Vector3::operator+(const Vector& other) const {
	Vector3* v = new Vector3(*this);
	v->operator+=(other);
	return v;
}
Vector3* Vector3::operator-(const Vector& other) const {
	Vector3* v = new Vector3(*this);
	v->operator+=(other);
	return v;
}
Vector3* Vector3::operator+(const Vector2& other) const {
	Vector3* v = new Vector3(*this);
	v->operator+=(other);
	return v;
}
Vector3* Vector3::operator-(const Vector2& other) const {
	Vector3* v = new Vector3(*this);
	v->operator+=(other);
	return v;
}
Vector3* Vector3::operator+(const Vector3& other) const {
	Vector3* v = new Vector3(*this);
	v->operator+=(other);
	return v;
}
Vector3* Vector3::operator-(const Vector3& other) const {
	Vector3* v = new Vector3(*this);
	v->operator+=(other);
	return v;
}
Vector3* Vector3::operator*(const ll_coordinate_t& value) const {
	Vector3* v = new Vector3(*this);
	v->operator*=(value);
	return v;
}

void Vector3::operator+=(const Vector& other) { Vector::operator+=(other); }
void Vector3::operator-=(const Vector& other) { Vector::operator-=(other); }
void Vector3::operator+=(const Vector2& other) { Vector2::operator+=(other); }
void Vector3::operator-=(const Vector2& other) { Vector2::operator-=(other); }
void Vector3::operator+=(const Vector3& other) {
	Vector2::operator+=(other);
	Z::addZ(other.z);
}
void Vector3::operator-=(const Vector3& other) {
	Vector2::operator-=(other);
	Z::addZ(-other.z);
}
void Vector3::operator*=(const ll_coordinate_t& value) {
	Vector2::operator*=(value);
	this->z *= value;
}

ll_bool_t Vector3::clear() {
	Z::clear();
	return Vector2::clear();
}


} /* namespace VectorSpace */
} /* namespace Math */
} /* namespace Core */
} /* namespace Llanylib */
