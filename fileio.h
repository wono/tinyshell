#ifndef __W_FILE_OPEN_H__
#define __W_FILE_OPEN_H__

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#define DEFAULT_BUFFER_SIZE 1024

/** 
 *  opens file with a coresponding option - read or write 
 *  F -> file descriptor (int)
 *  P -> file path (const *char)
 *  O -> OPEN OPTION (const *char) : O_RDONLY or O_WRONLY
 */
#define FILE_OPEN(F, P, O)\
F = O == O_RDONLY\
    ? open(P, O)\
    : open(P, O | O_CREAT | O_TRUNC, 0666);\
if (!(F)) {\
    perror("file open error");\
    exit(1);\
}

/** 
 *  closes file
 *  F -> file descriptor (int)
 */
#define FILE_CLOSE(F) close(F);

/** writes file to stdout */
void print_file(int file_descriptor);

#endif
