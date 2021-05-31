
#include "Core/Libs/llanysimpleprint.h"

#include "Core/Libs/randomlib.h"
#include "Listlib/Linkedlists/SmartLinkedlist.h"
#include "Listlib/Linkedlists/Linkedlist.h"

using namespace Llanylib::Listlib::Linkedlists;

int main(int argc, char **argv) {
	SmartLinkedlist<int>* list = new SmartLinkedlist<int>();

	for (int i = 0; i < 10; ++i) list->add(new int(i));

	int* temp;
	for (int i = 0; i < list->len(); ++i) {
		temp = list->get(i);
		if(temp != nullptr) PRINT2LN("Num:", *temp);
	}

	delete list;

	Linkedlist<int>* list_2 = new Linkedlist<int>();

	for (int i = 0; i < 10; ++i) list_2->add(i);

	for (int i = 0; i < list_2->len(); ++i) {
		temp = list_2->get(i);
		if (temp != nullptr) PRINT2LN("Num:", *temp);
	}

	delete list_2;

	return 0;
}
