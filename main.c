#include <stdio.h>
#include <unistd.h>

#include "execute_by_child.h"
#include "fileio.h"
#include "redirect.h"
#include "str_handler.h"
#include "tokenize.h"
#include "util.h"

#define LINE_SIZE           128
#define MAX_ARGC            12
#define SHELL_TITLE         "C/S Lab 6> "
#define SHELL_TITLE_LENGTH  11

int main()
{
    char line[LINE_SIZE], temp[LINE_SIZE];
    char *buffer[MAX_ARGC];
    
    while (1) {
        memset(&line[0], 0, sizeof(line));
        memset(&temp[0], 0, sizeof(temp));
        
        write(STDOUT_FILENO, SHELL_TITLE, SHELL_TITLE_LENGTH);
        
        read(STDIN_FILENO, line, LINE_SIZE);

        if ('\n' == line[0]) break;

        // removes newline character
        replace_char_last(line, strlen(line)-1, '\n', 0); 

        // removes space if it follows redirect symbol
        wstring_copy_except(
            line, temp, REDIRECT_SYMBOL_I, REDIRECT_SYMBOL_O, ' ');

        size_t c = tokenize(temp, buffer, " ");
        
        char *commands[c];

        size_t i;
        for (i = 0; i < c; i++) {
            commands[i] = buffer[i];
        }
        commands[i] = NULL;

        // REDIRECTION CHECK
        int rdi = searchIndex(c-1, commands, REDIRECT_SYMBOL_I);        
        int rdo = searchIndex(c-1, commands, REDIRECT_SYMBOL_O);
        
        // get redirection files
        SET_REDIRECT_FILENAME(commands, rdi, i, fi, szi);
        SET_REDIRECT_FILENAME(commands, rdo, i, fo, szo);
        
#       ifdef DEBUG
        printf("RDI: %d\tRDO: %d\n", rdi, rdo);
#       endif

        // get command only - no redirection signatures
        if (0 <= rdi + rdo) {
            rdi = rdi < 0 ? rdo : rdi;
            rdo = rdo < 0 ? rdi : rdo;
            
            int min = rdi < rdo ? rdi : rdo;
            
            size_t x = i;
            for (i = min; i < x; i++) {
                commands[i] = NULL;
            }
        }
        
        execute_by_child(commands[0], commands, fi, fo);
        
    }
    
    return(0);
}
