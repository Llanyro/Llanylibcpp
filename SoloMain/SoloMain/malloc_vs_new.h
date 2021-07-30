/*
malloc_gen_single function took 25 milliseconds
new_gen_single function took 28 milliseconds
malloc_gen_vector function took 40 milliseconds
new_gen_vector function took 35 milliseconds


malloc_gen_single function took 23 milliseconds
new_gen_single function took 25 milliseconds
malloc_gen_vector function took 25 milliseconds
new_gen_vector function took 26 milliseconds


malloc_gen_single function took 23 milliseconds
new_gen_single function took 24 milliseconds
malloc_gen_vector function took 26 milliseconds
new_gen_vector function took 25 milliseconds

malloc_gen_single function took 23 milliseconds
new_gen_single function took 25 milliseconds
malloc_gen_vector function took 30 milliseconds
new_gen_vector function took 25 milliseconds



*/

#pragma once

#include "../../Corelib/Libs/llanytypeslib.h"
#include "crono_functions.h"

#include <stdlib.h>

#define NUM_GEN 99999
#define NUM_GEN_VEC 100

void malloc_gen_single() {
	int* val = nullptr;

	for (len_t i = 0; i < NUM_GEN; i++) {
		val = (int*)malloc(sizeof(int) * 1);
		free(val);
	}
}
void malloc_gen_vector() {
	int* val = nullptr;
	for (len_t i = 0; i < NUM_GEN; i++) {
		val = (int*)malloc(sizeof(int) * NUM_GEN_VEC);
		free(val);
	}
}
void new_gen_single() {
	int* val = nullptr;

	for (len_t i = 0; i < NUM_GEN; i++) {
		val = new int();
		delete val;
	}
}
void new_gen_vector() {
	int* val = nullptr;
	for (len_t i = 0; i < NUM_GEN; i++) {
		val = new int[NUM_GEN_VEC];
		delete[] val;
	}
}

void malloc_vs_new() {
	execute_test(malloc_gen_single, "malloc_gen_single");
	execute_test(new_gen_single, "new_gen_single");
	execute_test(malloc_gen_vector, "malloc_gen_vector");
	execute_test(new_gen_vector, "new_gen_vector");
}