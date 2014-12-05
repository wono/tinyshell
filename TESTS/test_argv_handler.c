#include <stdio.h>
#include <string.h>

#include "argv_handler.h"

void copy_argv(int argc, char *argv[], char *dest[]) {
    int i;
    for (i = 0; i < argc; i++) {
        strcpy(argv[i], dest[i]);
        printf("%s\n", dest[i]);
    }
}

int main(int argc, char *argv[]) {
        
    COPY_ARGV(argc, argv, dest);

    int i;
    for (i = 0; i < argc; i++ ) {
        printf("%s\n", dest[i]);
    }

    return(0);
}
