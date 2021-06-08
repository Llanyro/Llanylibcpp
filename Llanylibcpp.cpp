
#include <iostream>
#include <chrono>
#include <list>

#include "Core/Libs/llanysimpleprint.h"

#include "Core/Libs/randomlib.h"
#include "Core/Libs/filelib.h"

//#include "Core/Structs/llanylinkedlist.h"
//#include "Listlib/Linkedlists/SmartLinkedlist.h"
//#include "Listlib/Linkedlists/Linkedlist.h"

using namespace Llanylib::Core::Structs;

/*#define NUM 9999

void test_func() {
	/*SmartLinkedlist<int>* list = new SmartLinkedlist<int>();

	for (int i = 0; i < 10; ++i) list->add(new int(i));

	int* temp;
	for (int i = 0; i < list->len(); ++i) {
		temp = list->get(i);
		if (temp != nullptr) PRINT2LN("Num:", *temp);
	}

	delete list;*

	BASIC_STRUCTS::llanyList<ll_uint64_t>* list_2 = BASIC_STRUCTS::newlist<ll_uint64_t>();

	for (ll_uint64_t i = 0; i < NUM; ++i) {
		//std::cout << i << ", ";
		BASIC_STRUCTS::add(list_2, i);
		//if(i % 500 == 0) std::cout << std::endl;
	}
	//std::cout << std::endl;

	/*ll_uint64_t* temp;
	std::cout << "l = { ";
	for (int i = 0; i < list_2->length; ++i) {
		temp = BASIC_STRUCTS::getValue(list_2, i);
		if (temp != nullptr) std::cout << *temp << ", ";
	}
	std::cout << "};\n";*

	BASIC_STRUCTS::removelist(&list_2);
}
void test_func_std() {
	std::list<ll_uint64_t>* list = new std::list<ll_uint64_t>();

	for (ll_uint64_t i = 0; i < NUM; ++i) {
		//std::cout << i << ", ";
		list->push_back(i);
		//if(i % 500 == 0) std::cout << std::endl;
	}
	//std::cout << std::endl;


	/*std::cout << "l = { ";
	for (int n : (*list)) std::cout << n << ", ";
	std::cout << "};\n";*

	delete list;
}*/

void execute_test(void* func(void)) {
	std::cout << "Start\n";
	auto t1 = std::chrono::high_resolution_clock::now();
	func();
	auto t2 = std::chrono::high_resolution_clock::now();
	std::cout << "test_func function took "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
		<< " milliseconds\n";
}


int main(int argc, char **argv) {
	std::cout << FILE_LIB::dir_exist_create("/FolderFolder2/Test") << std::endl;
	return 0;
}
