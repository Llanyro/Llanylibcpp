/*
 * Z.h
 *
 *  Created on: Feb 6, 2021
 *      Author: llanyro
 */

#ifndef LLANYLIB_CORE_MATHLIB_VECTORSPACE_Z_H_
#define LLANYLIB_CORE_MATHLIB_VECTORSPACE_Z_H_

#include "../../Simplelibs/llanymathtypeslib.h"
#include "../../Classes/Heritables/LlanyCore.h"

namespace Llanylib {
namespace Core {
namespace Math {
namespace VectorSpace {

class Z : Classes::Heritables::LlanyCore {
	protected:
		ll_coordinate_t z;
	public:
		Z();
		Z(const ll_coordinate_t& z);
		virtual ~Z();

		ll_coordinate_t getZ() const;
		void setZ(const ll_coordinate_t& val);
		void addZ(const ll_coordinate_t& val);
		ll_coordinate_t pow2() const;

		virtual ll_bool_t clear() override;
};

} /* namespace VectorSpace */
} /* namespace Math */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* LLANYLIB_CORE_MATHLIB_VECTORSPACE_Z_H_ */
