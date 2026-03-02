#include <stdio.h>

// Írjunk egy programot, ami interaktív módon bekéri egy gyémánt magasságát (egész szám).
// Először ellenőrizzük le, hogy helyes-e a bemenet. Csak pozitív páratlan számot fogadjunk el,
// ellenkező esetben írjunk ki egy hibaüzenetet és a program álljon le.
// Helyes bemenet (pozitív páratlan szám) esetén rajzoljuk ki a gyémántot a következőképpen:

// Magasság: 7

//    *
//   ***
//  *****
// *******
//  *****
//   ***
//    *

int main()
{
    int m;
    printf("Magasság: ");
    scanf("%d", &m);
    
    printf("\n");

    if(m % 2 == 0 || m <= 0)
    {
        printf("Hiba: pozitív páratlan számot adj meg!\n");
        return 1;
    }

    int kozep = m / 2;

    // felső rész
    for(int i = 0; i <= kozep; i++)
    {
        for(int j = 0; j < kozep - i; j++) {
            printf(" ");
        }
        for(int k = 0; k < (2 * i + 1); k++) {
            printf("*");
        }
        printf("\n");
    }
    // alsó rész
    for(int i = kozep - 1; i >= 0; i--)
    {
        for(int j = 0; j < kozep - i; j++) {
            printf(" ");          
        }
        for(int k = 0; k < (2 * i + 1); k++) {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}