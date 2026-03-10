#include <stdio.h>

// Írjon függvényt, ami vissza adja a fibonacci N.-k elemét, majd készítsen a main függvényben egy ciklust,
// ami kiírja az első 100 fibonacci számot a függvény segítségével.

//fix: túlcsordul

int fibonacci(int hossz)
{
    int a = 0;
    int b = 1;
    int tmp;

    for(int i = 2; i <= hossz; i++)
    {   
        tmp = a + b;
        a = b;
        b = tmp;
    }

    return b;
}

int main()
{
    int hossz = 100;

    for(int i = 0; i < hossz; i++) {
        if(fibonacci(i) < 0) {
            printf("%d: túlcsordult\n", i);
            return 0;
        }
        printf("%d: %d\n",i, fibonacci(i));
    }
}