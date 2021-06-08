/*
 * SmartList.h
 *
 *  Created on: Jun 7, 2021
 *      Author: llanyro
 */

#ifndef LISTLIB_CORELIST_ABSTRACTSMARTLIST_H_
#define LISTLIB_CORELIST_ABSTRACTSMARTLIST_H_

#include "../../Core/Libs/memlib.h"

namespace Llanylib {
namespace Listlib {
namespace Corelist {

template<class T>
class AbstractSmartList {
	protected:
		AbstractSmartList() {}
		virtual ~AbstractSmartList() {}
	public:
		virtual void addSmart(T* object, Destructor destructor) {}
		virtual ll_bool_t setSmart(T* object, Destructor destructor, const len_t& position, const ll_bool_t& smart) const { return false; }
		virtual ll_bool_t removeSmart(const len_t& pos, const ll_bool_t& smart) { return false; }

		void add(T* object) { this->addSmart(object, (Destructor) MEM_LIB::__delete__); }
		ll_bool_t set(T* object, const len_t& position, const ll_bool_t& smart) const { return this->setSmart(object, (Destructor) MEM_LIB::__delete__, position, smart); }
		ll_bool_t set(T* object, const len_t& position) const { return this->setSmart(object, (Destructor) MEM_LIB::__delete__, position, true); }
		ll_bool_t set(T* object, Destructor destructor, const len_t& position) const { return this->setSmart(object, destructor, position, true); }
		ll_bool_t remove(const len_t& pos) { return this->removeSmart(pos, true); }
};

} /* namespace Corelist */
} /* namespace Listlib */
} /* namespace Llanylibc */

#endif /* LISTLIB_CORELIST_ABSTRACTSMARTLIST_H_ */
