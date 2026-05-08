#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

/* valós számok összege
Írjon egy programot, ami feldolgozza a valos_szamok.txt nevű állományt,
s kiírja a képernyőre 20 tizedesjegy pontossággal a fájlban található számok összegét!

Figyelem!
Csak olyan dolgokat lehet használni, amit már tanultunk! Ellenkező esetben 0 pont jár a feladatra. 
*/

int main()
{
    FILE *fp = fopen("valos_szamok.txt", "r");

    char sor[MAX];
    double osszeg = 0;
    double aktualis_szam;

    while(fgets(sor, MAX, fp) != NULL) {
        for(int i = 0; sor[i] != '\0'; i++) {
            if(sor[i] == ',') {
                sor[i] = '.';
            }
        }
        aktualis_szam = atof(sor);
        osszeg += aktualis_szam;
    }

    printf("%.20lf\n", osszeg);

    return 0;
}