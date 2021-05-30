/*
 * X.h
 *
 *  Created on: Feb 6, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_MATHLIB_VECTORSPACE_X_H_
#define LLANYLIB_CORE_MATHLIB_VECTORSPACE_X_H_

#include "../../Simplelibs/llanymathtypeslib.h"
#include "../../Classes/Heritables/LlanyCore.h"

namespace Llanylib {
namespace Core {
namespace Math {
namespace VectorSpace {

class X : Classes::Heritables::LlanyCore {
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
