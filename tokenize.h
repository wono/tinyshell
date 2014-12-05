#ifndef __W_TOKENIZE_H__
#define __W_TOKENIZE_H__

#include <string.h>

/** returns num of commands added into buffer */
size_t tokenize(char line[], char *buffer[], const char *delimiter);
#endif
