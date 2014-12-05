#ifndef __W_REDIRECT_H__
#define __W_REDIRECT_H__

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "fileio.h"

#define REDIRECT_SYMBOL_I   '<'
#define REDIRECT_SYMBOL_O   '>'

/**
 *  Sets _FILENAME if _CMNDS has _INDEX that specify redirection.
 *  Otherwise, the _FILENAME is a set of NULL characters.
 *
 *      _CMNDS  -> commands                                 : char array
 *      _INDEX  -> index of redirection that _CMNDS has, 
 *                 otherwise 0                              : int
 *      _LENGTH -> _CMNDS length                            : int
 *      _V_FILE -> variable name that stores filename
 *      _V_SZ   -> variable name that stores filename size
 *
 */
#define SET_REDIRECT_FILENAME(_CMNDS, _INDEX, _LENGTH, _V_FILE, _V_SZ)\
int     _V_SZ = (0 < _INDEX) ? strlen(_CMNDS[_INDEX]) : _LENGTH;\
char    _V_FILE[_V_SZ - 1];\
\
memset(&_V_FILE[0],  0, sizeof(_V_FILE));\
if (0 < _INDEX) wsubstr(_CMNDS[_INDEX], _V_FILE, 1, _V_SZ)


/** 
 *  Macro for handling dup2
 *
 *      STDIN_FILENO    0
 *      STDOUT_FILENO   1
 *      STDERR_FILENO   2
 *
 *      _FN     -> filename
 */
#define REDIRECT(FD, STD, _FN)\
if (STD == STDIN_FILENO) {\
    FILE_OPEN(FD, _FN, O_RDONLY);\
} else {\
    FILE_OPEN(FD, _FN, O_WRONLY);\
}\
if (-1 == dup2(FD, STD)) {\
    perror("dup2 error");\
    exit(1);\
}

#endif
