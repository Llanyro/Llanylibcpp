
#include "Core/Libs/llanysimpleprint.h"

#include "Core/Libs/randomlib.h"
#include "Listlib/Linkedlists/SmartLinkedlist.h"

using namespace Llanylib::Listlib::Linkedlists;

int main(int argc, char **argv) {
	SmartLinkedlist<int>* list = new SmartLinkedlist<int>();

	for (int i = 0; i < 10; ++i)
		list->add(new int(RANDOM_LIB::range(20)));

	int* temp;
	for (int i = 0; i < list->length(); ++i) {
		temp = list->get(i);
		if(temp != nullptr) PRINT2LN("", *temp);
	}

	delete list;


	return 0;
}
