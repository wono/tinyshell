#include <stdio.h>
#include <unistd.h>

int main() {

    char *args[] = {"echo", "-r", "-t", "-l", NULL};
    execvp("echo", args);
    
    return(0);
}
