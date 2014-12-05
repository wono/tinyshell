#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

int main(int argc, char *argv[]) {
    int count = 0;
    
    printf("\n");
    while(environ[count] != NULL) {
        printf("[%s] :: ", environ[count]);
        count++;
    }
    
    char *val = getenv("USER");
    printf("\n\nCurrent: %s\n", val);
    
    return 0;
}
