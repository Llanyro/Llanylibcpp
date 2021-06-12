/*
 * Box.h
 *
 *  Created on: Jun 12, 2021
 *      Author: llanyro
 */

#ifndef GARBAGE_COLLECTOR_URANIUM_POINTER_COLLECTOR_BOX_H_
#define GARBAGE_COLLECTOR_URANIUM_POINTER_COLLECTOR_BOX_H_

namespace Llanylib {
namespace GC {
namespace UPC {

// Tree
class Box {
	public:
		Box();
		virtual ~Box();
		Box(const Box &other);
		Box(Box &&other);
		Box& operator=(const Box &other);
		Box& operator=(Box &&other);
};

} /* namespace UPC */
} /* namespace GC */
} /* namespace Llanylib */

#endif /* GARBAGE_COLLECTOR_URANIUM_POINTER_COLLECTOR_BOX_H_ */
