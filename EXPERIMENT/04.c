#include <unistd.h>
#include <fcntl.h>

int main()
{
    int fd = open("foo1.txt", O_WRONLY | O_CREAT | O_TRUNC);
    
    if (fd < 0) {
        write(1, "WROOOOOOOOOOOOONG", 16);
        return -1;
    }
    
    write(fd, "FOOOOOOOOOOOOOO\n", 16);
    
    return( 0 );
}
