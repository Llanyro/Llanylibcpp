/*
 * Vector.h
 *
 *  Created on: Feb 6, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_MATHLIB_VECTORSPACE_VECTOR_H_
#define LLANYLIB_CORE_MATHLIB_VECTORSPACE_VECTOR_H_

#include "../../Mathlib/VectorSpace/Point.h"

namespace Llanylib {
namespace Core {
namespace Math {
namespace VectorSpace {

class Vector : public X {
	protected:
		virtual ll_coordinate_t getNorm() const;
	public:
		Vector();
		Vector(const ll_coordinate_t& x);
		Vector(const Point& a, const Point& b);
		Vector(const Vector& other);
		ll_bool_t operator=(const Vector& other);
		virtual ~Vector();

		Vector* operator+(const Vector& other) const;
		Vector* operator-(const Vector& other) const;
		Vector* operator*(const ll_coordinate_t& value) const;

		void operator+=(const Vector& other);
		void operator-=(const Vector& other);
		virtual void operator*=(const ll_coordinate_t& value);

		ll_coordinate_t norm() const;

		virtual ll_bool_t clear() override;
};

} /* namespace VectorSpace */
} /* namespace Math */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_MATHLIB_VECTORSPACE_VECTOR_H_ */
