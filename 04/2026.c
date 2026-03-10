#include <stdio.h>

// Írjon egy C programot, ami kiírja a ketezerhuszonhat-ot úgy, hogy a forráskódban egyetlen számjegyet sem használ.
// https://jabbalaci.github.io/teaching-assets/hun/python/ascii/asciichart.png
// ASCII

int main()
{
    int ev = ',' * ',' + 'Z';

    printf("%d\n", ev);
    
    return ev - ev;
}

// ZÉRÓ SZÁM
