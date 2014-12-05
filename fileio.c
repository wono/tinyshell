#include "fileio.h"

/** writes file to stdout */
void print_file(int file_descriptor) {
    char    buf[DEFAULT_BUFFER_SIZE];
    int     buflen;
    while (0 < (buflen = read(file_descriptor, buf, DEFAULT_BUFFER_SIZE))) {
        write(1, buf, buflen);
    }
}
