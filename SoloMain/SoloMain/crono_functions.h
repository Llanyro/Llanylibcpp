#pragma once

#include <iostream>
#include <chrono>

void execute_test(void func(void), const char* const val) {
	auto t1 = std::chrono::high_resolution_clock::now();
	func();
	auto t2 = std::chrono::high_resolution_clock::now();
	std::cout
		<< val 
		<< " function took "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
		<< " milliseconds\n";
}
