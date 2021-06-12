
#include <iostream>
#include <chrono>
#include <list>
#include <memory>

#include "Core/Libs/llanysimpleprint.h"
#include "Core/Libs/randomlib.h"
#include "Core/Libs/filelib.h"
#include "Core/Libs/stringlib.h"

//#include "Core/Classes/Containers/SmartPointer.h"
//#include "Core/Classes/SimpleLists/List.h"

//#include "Core/Structs/llanylinkedlist.h"
#include "../OldMoludes/Listlib/Linkedlists/SmartLinkedlist.h"
//#include "Listlib/Linkedlists/Linkedlist.h"

//using namespace Llanylib::Core::Structs;
using namespace Llanylib::Core::Classes::SimpleLists;
using namespace Llanylib::Listlib::Linkedlists;
//using namespace Llanylib::Core::Classes::Containers;

#define STR "./Folder/Folder2/Test"

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


	/*
	std::cout << "l = { ";
	for (int n : (*list)) std::cout << n << ", ";
	std::cout << "};\n";*

	delete list;
}*/

void execute_test(void func(void)) {
	std::cout << "Start\n";
	auto t1 = std::chrono::high_resolution_clock::now();
	func();
	auto t2 = std::chrono::high_resolution_clock::now();
	std::cout << "test_func function took "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
		<< " milliseconds\n";
}


/*SmartPointer<int> tests() {
	SmartPointer<int> s(new int(7));
	return s;
}
void testSmart() {
	SmartPointer<int> s = tests();
}*/


#define SIZE_TEST 99999

void testSmartList() {
	SmartLinkedlist<len_t>* list = new SmartLinkedlist<len_t>();
	for (len_t i = 0; i < SIZE_TEST; i++)
		list->add(new len_t(i));
	len_t* temp;
	for (len_t i = 0; i < list->len(); i++) {
		temp = list->get(i);
		//std::cout << *temp << ", ";
	}
	delete list;
}
void testSmartListSTD() {
	std::list<std::unique_ptr<len_t>>* list = new std::list<std::unique_ptr<len_t>>();

	for (len_t i = 0; i < SIZE_TEST; i++)
		list->push_back(std::unique_ptr<len_t>(new len_t(i)));

	len_t* temp;
	std::list<std::unique_ptr<len_t>>::iterator it = list->begin();
	while (it != list->end()) {
		temp = (*it).get();
		//std::cout << *temp << ", ";
		std::advance(it, 1);
	}

	delete list;
}

/*template<class T>
struct data_pack {
	T data;
	std::list<std::unique_ptr<void*>> containers;
};
std::list<data_pack<len_t>>* list_pointers = new std::list<data_pack<len_t>>();

template<class T>
T* not_new() {

}
template<class T>
void testMem(T** container) {
	data_pack<T> data;
	data.data = T();
	//data.containers.push_back(container);
	list_pointers->push_back(data);


	delete list_pointers;
}

void testmem(void* mem) {
	printf("%p\n", mem);
}
void testmem2() {
	int a = 7;
	printf("%p\n", &a);
	testmem(&a);
}

*/

int main(int argc, char **argv) {
	//testSmart();
	//FILE_LIB::dir_exist_create(STR, STRLEN_DEFINED_STRING(STR));

	execute_test(testSmartList);
	execute_test(testSmartListSTD);
	//testmem2();

	return 0;
}
