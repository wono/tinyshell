#include "execute_by_child.h"

/** executes commands by child process forked */
void execute_by_child(
    char *program, char *commands[], char *filenameI, char *filenameO) {
    
    int status = 0;
    pid_t child_pid = fork();
    
    if (child_pid < 0) {
        perror("forking error");
        exit(-1);
    }
    
    if (0 == child_pid) {
        int fdi, fdo;
        
#       ifdef DEBUG
        printf("FI: %s\t FO: %s\n", filenameI, filenameO);
#       endif

        if (0 != filenameI[0]) { REDIRECT(fdi, STDIN_FILENO,  filenameI); }
        if (0 != filenameO[0]) { REDIRECT(fdo, STDOUT_FILENO, filenameO); }
        execvp(program, commands);
        exit(EXIT_SUCCESS);
    } else {
        wait(&status);
    }
}
