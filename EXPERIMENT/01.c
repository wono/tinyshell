#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>

int main() {
    int fd;

    fd = open("data", O_WRONLY | O_CREAT| O_TRUNC, 0666);
    if (fd == -1) {
        perror("open");
        return 1;
    } 
        
    /*
        0 STDIN_FILENO
        1 STDOUT_FILENO
        2 STDERR_FILENO
        3
    */

    if (dup2(fd, STDIN_FILENO) == -1) {
        perror("dup2");
        return 2;
    }

    printf("hello world!\n");
    
    close(fd);
    return 0;
}
