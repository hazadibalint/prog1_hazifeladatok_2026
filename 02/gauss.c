#include <stdio.h>

// Írjunk programot, ami kiszámolja az egész számok összegét 1-től 100-ig.

int main()
{
    int a = 0;
    int eredmeny = 0;
    
    for (int i = 0; i-1 < 100; i++)
    {
        eredmeny += i;
    }

    printf("Az eredmény: %d\n", eredmeny);

    return 0;
}