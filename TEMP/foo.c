#include <stdio.h>

int main() {
    int s = 10;
    char foo[s] = { 0 };
    printf("%d\n", sizeof(foo)/sizeof(char));
    return 0;
}
