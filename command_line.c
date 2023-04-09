#include <stdio.h>
int main(int argc, char *argv[])
{
    printf("This program has %d arguments:", argc-1);
    for (int i = 0; i < argc; ++i)
    {
        printf("%s\n", argv[i]);
    }
    return 0;
}

// to run:
// gcc command_line.c -o main
// ./main Nocturnal Coder