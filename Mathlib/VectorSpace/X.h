/*
 * X.h
 *
 *  Created on: Feb 6, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_MATHLIB_VECTORSPACE_X_H_
#define LLANYLIB_CORE_MATHLIB_VECTORSPACE_X_H_

#include "../../Core/Libs/llanymathtypeslib.h"
#include "../../Core/Classes/LlanyCore.h"


namespace Llanylib {
namespace Core {
namespace Math {
namespace VectorSpace {

class X : CORE::LlanyCore {
	protected:
		ll_coordinate_t x;
	public:
		X();
		X(const ll_coordinate_t& x);
		virtual ~X();

		ll_coordinate_t getX() const;
		void setX(const ll_coordinate_t& x);
		void addX(const ll_coordinate_t& x);
		ll_coordinate_t pow2() const;

		virtual ll_bool_t clear() override;
};

} /* namespace VectorSpace */
} /* namespace Math */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_MATHLIB_VECTORSPACE_X_H_ */
