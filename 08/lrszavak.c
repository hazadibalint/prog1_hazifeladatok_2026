#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* legrövidebb szavak
Írj programot, amely a standard kimenetre írja a parancssori argumentumai közül
a legrövidebbeket, soronként egyet-egyet.
A szavakat ugyanabban a sorrendben írassuk ki, ahogyan a parancssori argumentumok között szerepeltek!

Példák:

$ ./a.out
Nem adtál meg egyetlen szót sem!

$ ./a.out alma bab citrom dio eper
bab
dio

Amennyiben a felhasználó nem adott meg egyetlen szót sem, akkor a hibaüzenetet a standard
hibakimentre (stderr) írjuk ki!
Továbbá ilyenkor a program 1-es hibakóddal lépjen ki!

A main() függvény nem módosíthatja a parancssori argumentumok tömbjét! 
*/
int main(int argc, char *argv[])
{
    if(argc < 2) {
        fprintf(stderr, "Nem adtál meg egyetlen szót sem!\n");
        exit(1);
    }

    int legrovidebb = strlen(argv[1]);
    
    for(int i = 2; i < argc; i++)
    {
        int hossz = strlen(argv[i]);
        if(legrovidebb > hossz) {
            legrovidebb = hossz;
        }
    }

    for(int i = 1; i < argc; i++)
    {
        if(strlen(argv[i]) == legrovidebb) {
            printf("%s\n", argv[i]);
        }
    }

    return 0;
}