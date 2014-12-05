#include "util.h"

/** 
 *  returns first occurence index of argv whose first character matches with 
 *  c, otherwise returns -1 
 */ 
int searchIndex(int argc, char *argv[], char c) {
    int i;
    for (i = 0; i < argc; i++) {
        if (c == argv[i][0]) {
            return i;
        }
    }
    
    return -1;
}
