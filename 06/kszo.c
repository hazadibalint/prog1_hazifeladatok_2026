#include <stdio.h>
#include <stdlib.h>
#include "prog1.h"

/*
Írjunk programot, ami parancssori argumentumként vár két egész számot.
A program írja ki a két szám összegét.
Ha a felhasználó nem pontosan két argumentumot adott meg, akkor írjon ki egy hibaüzenetet!
Példa:
$ ./a.out
Hiba! Két paramétert (számot) kell megadni.
$ ./a.out 20
Hiba! Két paramétert (számot) kell megadni.
$ ./a.out 20 5int
25
$ ./a.out 20 5 67
Hiba! Két paramétert (számot) kell megadni.
*/

int main(int argc, string argv[])
{
    if(argc == 3) {
        printf("%d\n",(atoi(argv[1]) + atoi(argv[2])));
        return 0;
    }
    else {
        printf("HIba! Két paramétert (számot) kell megadni.\n");
        return 1;
    }
}