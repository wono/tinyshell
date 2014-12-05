#include "tokenize.h"

/** returns num of commands added into buffer */
size_t tokenize(char line[], char *buffer[], const char *delimiter) {
    
    char *token = buffer[0] = strtok(line, delimiter);
    
    size_t i = 1;
    while(token) {
        token = strtok(NULL, delimiter);
        buffer[i++] = token;
    }
    
    buffer[i] = NULL;
    
    return i;
}
