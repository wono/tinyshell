#ifndef __C3940_UTIL_H__
#define __C3940_UTIL_H__

#include <string.h>
/** 
 *  returns first occurence index of argv whose first character matches with 
 *  c, otherwise returns -1 
 */ 
int searchIndex(int argc, char *argv[], char c);
#endif
