#include "str_handler.h"

/** replaces last occurence character a to b */
size_t replace_char_last(char line[], size_t last_index, char a, char b) {
    if (a == line[last_index]) {
        line[last_index] = b;
        last_index = 0;
    }
    
    return  0 == last_index
        ?   0
        :   replace_char_last(line, last_index-1, a, b);
}

/** copies string src to dst but char c following a or b */
void wstring_copy_except(
    char src[], char dst[], const char a, const char b, const char c) {
    int i, j;

    for (i = j = 0; (src[i]); i++) {
        if (c == src[i] && 0 < i-1 && (a == src[i-1] || b == src[i-1])) {
            ++i;
        }
        dst[j++] = src[i];
    }
    
    dst[j] = 0;
}

/** copies elements between a and b indices of s to d */
void wsubstr(char s[], char d[], size_t a, size_t b) {
    size_t i, j=0;
    for (i = a; i < b; i++) {
        d[j++] = s[i];
    }
    
    for (i = strlen(d); j < i; j++) {
        d[j] = 0;
    }
}
