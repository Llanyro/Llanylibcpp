/*
 * Container.h
 *
 *  Created on: Jun 16, 2021
 *      Author: llanyro
 */

#ifndef CORELIB_TEMPLATES_CONTAINER_H_
#define CORELIB_TEMPLATES_CONTAINER_H_

namespace Llanylib {
namespace Corelib {
namespace Templates {

template<class T>
class Container {
	public:
		T __object_0;
	public:
		Container() {
			this->__object_0 = T();
		}
		Container(const T& object) {
			this->__object_0 = T();
		}
		virtual ~Container();
		Container(const Container &other);
		Container(Container &&other);
		Container& operator=(const Container &other);
		Container& operator=(Container &&other);
};

} /* namespace Templates */
} /* namespace Corelib */
} /* namespace Llanylib */

#endif /* CORELIB_TEMPLATES_CONTAINER_H_ */
