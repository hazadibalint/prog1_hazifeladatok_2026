#include <stdio.h>

// Implementáljuk az alábbi eljárást:
// void line(char c, int length);

// Példa:

// printf("hello\n");
// line('-', 40);
// printf("world\n");

// Kimenet:

// hello
// ----------------------------------------
// world

void line(char c, int length)
{
    for(int i = 0; i < length; i++) {
        printf("%c",c);
    }
    printf("\n");
}

int main()
{
    printf("Hello\n");
    line('-', 40);
    printf("World!\n");

    return 0;
}