/*
 * Point3.h
 *
 *  Created on: Feb 6, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_MATHLIB_VECTORSPACE_POINT3_H_
#define LLANYLIB_CORE_MATHLIB_VECTORSPACE_POINT3_H_

#include "../../Mathlib/VectorSpace/Point2.h"
#include "../../Mathlib/VectorSpace/Z.h"

namespace Llanylib {
namespace Core {
namespace Math {
namespace VectorSpace {

class Point3 : public Point2, public Z {
	public:
		Point3();
		Point3(const ll_coordinate_t& x);
		Point3(const ll_coordinate_t& x, const ll_coordinate_t& y);
		Point3(const ll_coordinate_t& x, const ll_coordinate_t& y, const ll_coordinate_t& z);
		Point3(const Point& other);
		Point3(const Point2& other);
		Point3(const Point3& other);
		ll_bool_t operator=(const Point& other);
		ll_bool_t operator=(const Point2& other);
		ll_bool_t operator=(const Point3& other);
		virtual ~Point3();

		Point3* operator+(const Point& other) const;
		Point3* operator-(const Point& other) const;
		Point3* operator+(const Point2& other) const;
		Point3* operator-(const Point2& other) const;
		Point3* operator+(const Point3& other) const;
		Point3* operator-(const Point3& other) const;

		void operator+=(const Point& other);
		void operator-=(const Point& other);
		void operator+=(const Point2& other);
		void operator-=(const Point2& other);
		void operator+=(const Point3& other);
		void operator-=(const Point3& other);

		virtual ll_bool_t clear() override;
};

} /* namespace VectorSpace */
} /* namespace Math */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_MATHLIB_VECTORSPACE_POINT3_H_ */
