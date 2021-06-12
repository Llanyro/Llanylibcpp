/*
 * BoxNode.h
 *
 *  Created on: Jun 12, 2021
 *      Author: llanyro
 */

#ifndef GARBAGE_COLLECTOR_URANIUM_POINTER_COLLECTOR_BOXNODE_H_
#define GARBAGE_COLLECTOR_URANIUM_POINTER_COLLECTOR_BOXNODE_H_

namespace Llanylib {
namespace GC {
namespace UPC {

class BoxNode {
public:
	BoxNode();
	virtual ~BoxNode();
	BoxNode(const BoxNode &other);
	BoxNode(BoxNode &&other);
	BoxNode& operator=(const BoxNode &other);
	BoxNode& operator=(BoxNode &&other);
};

} /* namespace UPC */
} /* namespace GC */
} /* namespace Llanylib */

#endif /* GARBAGE_COLLECTOR_URANIUM_POINTER_COLLECTOR_BOXNODE_H_ */
