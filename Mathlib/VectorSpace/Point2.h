/*
 * Point2.h
 *
 *  Created on: Feb 6, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_MATHLIB_VECTORSPACE_POINT2_H_
#define LLANYLIB_CORE_MATHLIB_VECTORSPACE_POINT2_H_

#include "../../Mathlib/VectorSpace/Point.h"
#include "../../Mathlib/VectorSpace/Y.h"

namespace Llanylib {
namespace Core {
namespace Math {
namespace VectorSpace {

class Point2 : public Point, public Y {
	public:
		Point2();
		Point2(const ll_coordinate_t& x);
		Point2(const ll_coordinate_t& x, const ll_coordinate_t& y);
		Point2(const Point& other);
		Point2(const Point2& other);
		ll_bool_t operator=(const Point& other);
		ll_bool_t operator=(const Point2& other);
		virtual ~Point2();

		Point2* operator+(const Point& other) const;
		Point2* operator-(const Point& other) const;
		Point2* operator+(const Point2& other) const;
		Point2* operator-(const Point2& other) const;

		void operator+=(const Point& other);
		void operator-=(const Point& other);
		void operator+=(const Point2& other);
		void operator-=(const Point2& other);

		virtual ll_bool_t clear() override;
};

} /* namespace VectorSpace */
} /* namespace Math */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_MATHLIB_VECTORSPACE_POINT2_H_ */
