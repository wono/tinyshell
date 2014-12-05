#ifndef __W_STR_HANDLER_H__
#define __W_STR_HANDLER_H__

#include <stdio.h>
#include <string.h>

/** replaces last occurence character a to b */
size_t replace_char_last(char line[], size_t last_index, char a, char b);

/** copies string src to dst but char c following a or b */
void wstring_copy_except(
    char src[], char dst[], const char a, const char b, const char c);

/** copies elements between a and b indices of s to d */
void wsubstr(char s[], char d[], size_t a, size_t b);

#endif
