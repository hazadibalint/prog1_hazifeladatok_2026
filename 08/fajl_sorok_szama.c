#include <stdio.h>
#include <stdlib.h>

/* fájlban lévő sorok száma
Írjon programot, ami parancssori argumentumként megkapja egy szöveges fájl nevét.
A program írja ki a képernyőre a fájl sorainak a számát.
Hiba esetén a hibaüzenet a standard hibakimeneten jelenjen meg,
s a program egy hibakóddal lépjen ki!

Példa:

$ ./a.out
Hiba! Adja meg egy szöveges állomány nevét!

$ ./a.out nesze.txt
Hiba! A nesze.txt nevű file-t nem sikerült megnyitni!

$ ./a.out input.txt
3

$ cat input.txt
elso sor
masodik sor
harmadik sor (utolso sor)

A fenti példában a nesze.txt egy nem létező fájl neve.

Szorgalmi
A fájl sorainak a számát egy függvénnyel állapítsuk meg:
int get_number_of_lines(...);
A formális paraméterlistát nem adtam meg.
Találjuk ki, hogy ennek a függvénynek vajon mit s hogyan kellene átadni! 
*/

#define MAX 1000

int get_number_of_lines(const char* fajlnev)
{
    FILE *fp = fopen(fajlnev, "r");

    if(fp == NULL) {
    return -1;
    }

    int sorok = 0;
    char karakter[MAX];

    while(fgets(karakter, MAX, fp) != NULL) {
        sorok++;
    }

    fclose(fp);
    return sorok;
}

int main(int argc, char* argv[])
{
    if(argc != 2) {
        fprintf(stderr, "Hiba! Adja meg egy szöveges állomány nevét!\n");
        exit(1);
    }

    char* bemeneti_fajl = argv[1];

    int eredmeny = get_number_of_lines(bemeneti_fajl);

    if(eredmeny == -1) {
        fprintf(stderr, "Hiba! A %s nevű file-t nem sikerült megnyitni!\n", bemeneti_fajl);
        exit(1);
    }

    printf("%d\n", eredmeny);

    return 0;
}