#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define BUF_SIZE 16
int main(int argc, char *argv[])
{
    //int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC);
    size_t RETURN_SIZE;
    
    while( 1 ) {
        RETURN_SIZE = write(0, "FOOOOOO\n", BUF_SIZE);
        printf("%lu\n", RETURN_SIZE);
    }
    
    return( 0 );
}
