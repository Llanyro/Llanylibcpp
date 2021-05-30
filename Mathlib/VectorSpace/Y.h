/*
 * Y.h
 *
 *  Created on: Feb 6, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_MATHLIB_VECTORSPACE_Y_H_
#define LLANYLIB_CORE_MATHLIB_VECTORSPACE_Y_H_

#include "../../Simplelibs/llanymathtypeslib.h"
#include "../../Classes/Heritables/LlanyCore.h"

namespace Llanylib {
namespace Core {
namespace Math {
namespace VectorSpace {

class Y : Classes::Heritables::LlanyCore {
	protected:
		ll_coordinate_t y;
	public:
		Y();
		Y(const ll_coordinate_t& y);
		virtual ~Y();

		ll_coordinate_t getY() const;
		void setY(const ll_coordinate_t& y);
		void addY(const ll_coordinate_t& y);
		ll_coordinate_t pow2() const;

		virtual ll_bool_t clear() override;
};

} /* namespace VectorSpace */
} /* namespace Math */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_MATHLIB_VECTORSPACE_Y_H_ */
