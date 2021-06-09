/*
 * stringlib.cpp
 *
 *  Created on: Mar 7, 2021
 *      Author: llanyro
 */

#include <stdlib.h>

#include "stringlib.h"
#include "asciidefines.h"
#include "charslib.h"
#include "memlib.h"

#include "../Structs/basicstructs.h"

namespace Llanylib {
namespace Core {
namespace Libs {
namespace String {

ll_bool_t strcmp(const char* str_1, const char* str_2) { return strcmp(str_1, stringlenght(str_1), str_2, stringlenght(str_2)); }
ll_bool_t strcmp(const char* str_1, const len_t& len, const char* str_2) { return strcmp(str_1, len, str_2, stringlenght(str_2)); }
ll_bool_t strcmp(const char* str_1, const char* str_2, const len_t& len) { return strcmp(str_1, stringlenght(str_1), str_2, len); }

ll_bool_t strcmp_similar(const char* str_1, const char* str_2) { return strcmp_similar(str_1, stringlenght(str_1), str_2, stringlenght(str_2)); }
ll_bool_t strcmp_similar(const char* str_1, const len_t& len, const char* str_2) { return strcmp_similar(str_1, len, str_2, stringlenght(str_2)); }
ll_bool_t strcmp_similar(const char* str_1, const char* str_2, const len_t& len) { return strcmp_similar(str_1, stringlenght(str_1), str_2, len); }

ll_bool_t contains_char(const char* str, const char* character) { return contains_char(str, stringlenght(str), character); }

ll_bool_t strcmp(const char* str_1, const len_t& len_1, const char* str_2, const len_t len_2) {
	ll_bool_t result = true;
	if (len_1 != len_2) result = false;
	else
		for (len_t i = 0; i < len_1 && result; ++i)
			result = (str_1[i] == str_2[i]);
	return result;
}
ll_bool_t strcmp_similar(const char* str_1, const len_t& len_1, const char* str_2, const len_t len_2) {
	ll_bool_t result = true;
	if (len_1 != len_2) result = false;
	else
		for (len_t i = 0; i < len_1 && result; ++i)
			result = (CHARS_LIB::compareCharSimilar(str_1 + i, str_2 + i) == 0);
	return result;
}
ll_bool_t start_with(const char* str_1, const len_t& len_1, const char* str_2, const len_t len_2) {
	ll_bool_t result = true;
	len_t len = len_1;
	if(len_1 > len_2) len = len_2;
	for (len_t i = 0; i < len && result; ++i)
		result = (str_1[i] == str_2[i]);
	return result;
}
ll_bool_t start_with_similar(const char* str_1, const len_t& len_1, const char* str_2, const len_t len_2) {
	ll_bool_t result = true;
	len_t len = len_1;
	if(len_1 > len_2) len = len_2;
	for (len_t i = 0; i < len && result; ++i)
		result = (CHARS_LIB::compareCharSimilar(str_1 + i, str_2 + i) == 0);
	return result;
}

ll_bool_t contains_char(const char* str, const len_t& len, const char* character) {
	ll_bool_t result = false;
	for (len_t i = 0; i < len && !result; ++i)
		result = (str[i] == *character);
	return result;
}
ll_bool_t is_number(const char* str, const len_t& len) {
	ll_bool_t result = true;
	for (len_t i = 0; i < len && result; ++i)
		result = contains_char(CHARS_NUMS, CHARS_NUMS_LEN, str + i);
	return result;
}
ll_bool_t is_float(const char* str, const len_t& len) {
	ll_bool_t result = true;
	for (len_t i = 0; i < len && result; ++i)
		result = contains_char(IP_CHARS, CHARS_NUMS_LEN, str + i);
	return result;
}

len_t stringlenght(const char* str) {
	len_t result = MEM_LIB::sizeBlock_b((void*)str);
	if (result >= 24) result -= 24;
	while (str[result] != '\0') result++;
	return result;
}
/* Return the length of the null-terminated string STR.  Scan for
   the null terminator quickly by testing four bytes at a time.  */
len_t stringlenght_low(const char* str) {
	const char* char_ptr;
	const unsigned long int* longword_ptr;
	unsigned long int longword, himagic, lomagic;
	/* Handle the first few characters by reading one character at a time.
	   Do this until CHAR_PTR is aligned on a longword boundary.  */
	for (char_ptr = str; ((unsigned long int) char_ptr
		& (sizeof(longword) - 1)) != 0;
		++char_ptr)
		if (*char_ptr == '\0')
			return char_ptr - str;
	/* All these elucidatory comments refer to 4-byte longwords,
	   but the theory applies equally well to 8-byte longwords.  */
	longword_ptr = (unsigned long int*) char_ptr;
	/* Bits 31, 24, 16, and 8 of this number are zero.  Call these bits
	   the "holes."  Note that there is a hole just to the left of
	   each byte, with an extra at the end:
	   bits:  01111110 11111110 11111110 11111111
	   bytes: AAAAAAAA BBBBBBBB CCCCCCCC DDDDDDDD
	   The 1-bits make sure that carries propagate to the next 0-bit.
	   The 0-bits provide holes for carries to fall into.  */
	himagic = 0x80808080L;
	lomagic = 0x01010101L;
	if (sizeof(longword) > 4) {
		/* 64-bit version of the magic.  */
		/* Do the shift in two steps to avoid a warning if long has 32 bits.  */
		himagic = ((himagic << 16) << 16) | himagic;
		lomagic = ((lomagic << 16) << 16) | lomagic;
	}
	if (sizeof(longword) > 8)
		abort();
	/* Instead of the traditional loop which tests each character,
	   we will test a longword at a time.  The tricky part is testing
	   if *any of the four* bytes in the longword in question are zero.  */
	for (;;) {
		longword = *longword_ptr++;
		if (((longword - lomagic) & ~longword & himagic) != 0) {
			/* Which of the bytes was the zero?  If none of them were, it was
			   a misfire; continue the search.  */
			const char* cp = (const char*)(longword_ptr - 1);
			if (cp[0] == 0)
				return cp - str;
			if (cp[1] == 0)
				return cp - str + 1;
			if (cp[2] == 0)
				return cp - str + 2;
			if (cp[3] == 0)
				return cp - str + 3;
			if (sizeof(longword) > 4) {
				if (cp[4] == 0)
					return cp - str + 4;
				if (cp[5] == 0)
					return cp - str + 5;
				if (cp[6] == 0)
					return cp - str + 6;
				if (cp[7] == 0)
					return cp - str + 7;
			}
		}
	}
	return 0;
}
//libc_hidden_builtin_def(strlen)


} /* namespace String */
} /* namespace Libs */
} /* namespace Core */
} /* namespace Llanylibc */
