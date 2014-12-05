#ifndef __W_EXECUTE_BY_CHILD_H__
#define __W_EXECUTE_BY_CHILD_H__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "fileio.h"
#include "redirect.h"
#include "str_handler.h"
#include "util.h"

/** executes commands by child process forked */
void execute_by_child(
    char *program, char *commands[], char *filenameI, char *filenameO);

#endif
