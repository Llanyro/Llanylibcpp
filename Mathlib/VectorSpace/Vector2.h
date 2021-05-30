/*
 * Vector2.h
 *
 *  Created on: Feb 6, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_MATHLIB_VECTORSPACE_VECTOR2_H_
#define LLANYLIB_CORE_MATHLIB_VECTORSPACE_VECTOR2_H_

#include "../../Mathlib/VectorSpace/Point2.h"
#include "../../Mathlib/VectorSpace/Vector.h"

namespace Llanylib {
namespace Core {
namespace Math {
namespace VectorSpace {

class Vector2 : public Vector, public Y {
	protected:
		virtual ll_coordinate_t getNorm() const override;
	public:
		Vector2();
		Vector2(const ll_coordinate_t& x);
		Vector2(const ll_coordinate_t& x, const ll_coordinate_t& y);
		Vector2(const Point& a, const Point& b);
		Vector2(const Point& a, const Point2& b);
		Vector2(const Point2& a, const Point& b);
		Vector2(const Point2& a, const Point2& b);
		Vector2(const Vector& other);
		Vector2(const Vector2& other);
		ll_bool_t operator=(const Vector& other);
		ll_bool_t operator=(const Vector2& other);
		virtual ~Vector2();

		Vector2* operator+(const Vector& other) const;
		Vector2* operator-(const Vector& other) const;
		Vector2* operator+(const Vector2& other) const;
		Vector2* operator-(const Vector2& other) const;
		Vector2* operator*(const ll_coordinate_t& value) const;

		void operator+=(const Vector& other);
		void operator-=(const Vector& other);
		void operator+=(const Vector2& other);
		void operator-=(const Vector2& other);
		virtual void operator*=(const ll_coordinate_t& value) override;

		virtual ll_bool_t clear() override;
};

} /* namespace VectorSpace */
} /* namespace Math */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_MATHLIB_VECTORSPACE_VECTOR2_H_ */
