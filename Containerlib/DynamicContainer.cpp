/*
 * DynamicContainer.cpp
 *
 *  Created on: Jul 14, 2021
 *      Author: llanyro
 */

#include "DynamicContainer.h"

namespace Llanylib {
namespace Containerlib {
namespace Containers {

DynamicContainer::DynamicContainer() {
	this->object = nullptr;
	this->destructor = nullptr;
}
DynamicContainer::~DynamicContainer() { this->clear(); }
void DynamicContainer::clear() {
	if(this->destructor != nullptr && this->object != nullptr) {
		this->destructor(&this->object);
		this->destructor = nullptr;
	}
}

dynamic DynamicContainer::getObjectDynamic() { return this->object; }
ll_bool_t DynamicContainer::getReadOnly() const { return this->destructor == nullptr; }
Destructor DynamicContainer::getDestructor() const { return this->destructor; }

ll_bool_t DynamicContainer::setProtected(dynamic object, Destructor destructor) {
	this->object = object;
	this->destructor = destructor;
	return true;
}
ll_bool_t DynamicContainer::set(dynamic object, Destructor destructor) {
	ll_bool_t resultado = false;
	if(object != nullptr && destructor == nullptr)
		resultado = false;
	else
		resultado = this->setProtected(object, destructor);
	return resultado;
}

} /* namespace Containers */
} /* namespace Containerlib */
} /* namespace Llanylib */
