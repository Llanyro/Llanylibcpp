/*
 * Vector3.h
 *
 *  Created on: Feb 6, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_MATHLIB_VECTORSPACE_VECTOR3_H_
#define LLANYLIB_CORE_MATHLIB_VECTORSPACE_VECTOR3_H_

#include "../../Mathlib/VectorSpace/Point3.h"
#include "../../Mathlib/VectorSpace/Vector2.h"

namespace Llanylib {
namespace Core {
namespace Math {
namespace VectorSpace {

class Vector3 : public Vector2, public Z {
	protected:
		virtual ll_coordinate_t getNorm() const override;
	public:
		Vector3();
		Vector3(const ll_coordinate_t& x);
		Vector3(const ll_coordinate_t& x, const ll_coordinate_t& y);
		Vector3(const ll_coordinate_t& x, const ll_coordinate_t& y, const ll_coordinate_t& z);
		Vector3(const Point& a, const Point& b);
		Vector3(const Point& a, const Point2& b);
		Vector3(const Point2& a, const Point& b);
		Vector3(const Point2& a, const Point2& b);

		Vector3(const Point& a, const Point3& b);
		Vector3(const Point2& a, const Point3& b);
		Vector3(const Point3& a, const Point3& b);
		Vector3(const Point3& a, const Point2& b);
		Vector3(const Point3& a, const Point& b);

		Vector3(const Vector& other);
		Vector3(const Vector2& other);
		Vector3(const Vector3& other);
		ll_bool_t operator=(const Vector& other);
		ll_bool_t operator=(const Vector2& other);
		ll_bool_t operator=(const Vector3& other);
		virtual ~Vector3();

		Vector3* operator+(const Vector& other) const;
		Vector3* operator-(const Vector& other) const;
		Vector3* operator+(const Vector2& other) const;
		Vector3* operator-(const Vector2& other) const;
		Vector3* operator+(const Vector3& other) const;
		Vector3* operator-(const Vector3& other) const;
		Vector3* operator*(const ll_coordinate_t& value) const;

		void operator+=(const Vector& other);
		void operator-=(const Vector& other);
		void operator+=(const Vector2& other);
		void operator-=(const Vector2& other);
		void operator+=(const Vector3& other);
		void operator-=(const Vector3& other);
		virtual void operator*=(const ll_coordinate_t& value) override;

		virtual ll_bool_t clear() override;
};

} /* namespace VectorSpace */
} /* namespace Math */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_MATHLIB_VECTORSPACE_VECTOR3_H_ */
