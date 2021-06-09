/*
 * Test.h
 *
 *  Created on: Jun 9, 2021
 *      Author: llanyro
 */

#ifndef CORE_CLASSES_CONTAINERS_TEST_H_
#define CORE_CLASSES_CONTAINERS_TEST_H_

namespace Llanylib {
namespace Core {
namespace Classes {
namespace Containers {

class Test {
public:
	Test();
	virtual ~Test();
	Test& operator=(Test &&other);
	Test& operator=(const Test &other);
	Test(Test &&other);
	Test(const Test &other);
};

} /* namespace Containers */
} /* namespace Classes */
} /* namespace Core */
} /* namespace Llanylib */

#endif /* CORE_CLASSES_CONTAINERS_TEST_H_ */
