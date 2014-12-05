#include <string.h>
#include <stdio.h>

int main()
{
    char buff[16] = "Hello World";
    char *token;

    token = strtok(buff, " ");

    while( NULL != token ) {
        printf("%s\n", token);
        token = strtok(NULL, " ");
    }
    
    return 0;
}
