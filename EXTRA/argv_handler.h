#ifndef __ARGV_HANDLER_H__
#define __ARGV_HANDLER_H__

#include <stdlib.h>
#include <string.h>

// maximum length of each argument
#define _ARGUMENT_LENGTH_MAX    16

/** 
 *  Copies _ARGV to _V_DEST as much as _ARGC.
 *
 *      _ARGC   -> argument count.
 *                 determines _ARGV_D length    : int
 *      _ARGV   -> source                       : char [][_ARGUMENT_LENGTH_MAX]
 *      _V_DEST -> destination                  : variable
 *
 */
#define COPY_ARGV(_ARGC, _ARGV, _V_CMNDS)\
char _V_CMNDS[_ARGC+1][_ARGUMENT_LENGTH_MAX];\
int _i;\
for (_i = 0; _i < _ARGC; _i++) {\
    memset(&_V_CMNDS[_i][0], 0, sizeof(_V_CMNDS[0]));\
    strcpy(_V_CMNDS[_i], _ARGV[_i]);\
}\
memset(&_V_CMNDS[_i][0], 0, sizeof(_V_CMNDS[0]))

#endif
