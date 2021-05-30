/*
 * Point.h
 *
 *  Created on: Feb 6, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_MATHLIB_VECTORSPACE_POINT_H_
#define LLANYLIB_CORE_MATHLIB_VECTORSPACE_POINT_H_

#include "../../Mathlib/VectorSpace/X.h"

namespace Llanylib {
namespace Core {
namespace Math {
namespace VectorSpace {

class Point : public X {
	public:
		Point();
		Point(const ll_coordinate_t& x);
		Point(const Point& other);
		ll_bool_t operator=(const Point& other);
		virtual ~Point();

		Point* operator+(const Point& other) const;
		Point* operator-(const Point& other) const;

		void operator+=(const Point& other);
		void operator-=(const Point& other);

		virtual ll_bool_t clear() override;
};

} /* namespace VectorSpace */
} /* namespace Math */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_MATHLIB_VECTORSPACE_POINT_H_ */
