#include <stdio.h>
#include <stdlib.h>

/* Nagyobb, mint 0,5?
Írjon egy programot, ami feldolgozza az in.txt nevű állományt, s kiírja a 0,5-nél nagyobb számokat
egy out.txt nevű fájlba! A program egyszerű log formájában tájékoztassa a felhasználót
arról, hogy mi is történik!

Példa:

$ ./a.out
# in.txt sikeresen megnyitva
# 0,5-nél nagyobb számok szűrése...
# szűrés vége
# out.txt bezárva
# out.txt-be kiírt számok mennyisége: X db

Az X helyére természetesen a megfelelő érték kerüljön. 
*/

#define MAX 1000

int main()
{
    FILE *input = fopen("in.txt", "r");
    puts("# in.txt sikeresen megnyitva");

    FILE *output = fopen("out.txt", "w");
    puts("# 0.5-nél nagyobb számok szűrése...");

    char sor[MAX];
    int db = 0;
    double aktualis_szam;

    while(fgets(sor, MAX, input) != NULL)
    {
        aktualis_szam = atof(sor);

        if(aktualis_szam > 0.5) {
            db++;
        }
    }
    puts("# szűrés vége");

    fclose(input);
    fclose(output);

    puts("# out.txt bezárva");
    printf("# out.txt-be kiírt számok mennyisége: %d db\n", db);

    return 0;
}