
#include <iostream>
#include <chrono>
#include <list>

#include "Core/Libs/llanysimpleprint.h"

#include "Core/Libs/randomlib.h"
#include "Listlib/Linkedlists/SmartLinkedlist.h"
#include "Listlib/Linkedlists/Linkedlist.h"

using namespace Llanylib::Listlib::Linkedlists;

/*#define NUM 999999

void test_func() {
	/SmartLinkedlist<int>* list = new SmartLinkedlist<int>();

	for (int i = 0; i < 10; ++i) list->add(new int(i));

	int* temp;
	for (int i = 0; i < list->len(); ++i) {
		temp = list->get(i);
		if (temp != nullptr) PRINT2LN("Num:", *temp);
	}

	delete list;*

	Linkedlist<ll_uint64_t>* list_2 = new Linkedlist<ll_uint64_t>();

	for (ll_uint64_t i = 0; i < NUM; ++i) {
		//std::cout << i << ", ";
		list_2->add(i);
		//if(i % 500 == 0) std::cout << std::endl;
	}
	//std::cout << std::endl;

	/*int* temp;
	std::cout << "l = { ";
	for (int i = 0; i < list_2->len(); ++i) {
		temp = list_2->get(i);
		if (temp != nullptr) std::cout << *temp << ", ";
	}
	std::cout << "};\n";*

	delete list_2;
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
}



int main(int argc, char **argv) {
	std::cout << "Start\n";
	auto t1 = std::chrono::high_resolution_clock::now();
	test_func();
	auto t2 = std::chrono::high_resolution_clock::now();
	std::cout << "test_func function took "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
		<< " milliseconds\n";

	auto t3 = std::chrono::high_resolution_clock::now();
	test_func_std();
	auto t4 = std::chrono::high_resolution_clock::now();
	std::cout << "test_func_std function took "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(t4 - t3).count()
		<< " milliseconds\n";

	return 0;
}*/
