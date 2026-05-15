#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* GENERÁLÓ (A PROGRAM)
Legyen egy "A" program, ami előállít egy szöveges állományt.
Ebben a sorok legyenek eltérő hosszúságúak, s a sorok nyomtatható karakterekből álljanak.
Figyeljen arra, hogy egyetlen sor végén se legyen whitespace karakter!

Ha a programot többször futtatjuk, akkor mindig más és más tartalmú szöveges állományt hozzon létre.
A kimenetet akár a standard outputra is lehet küldeni, s ekkor a kimenetet át lehet irányítani
egy tetszőleges állományba.
Parancssori argumentumként három értéket kelljen megadni: a sorok számát,
ill. a sorok minimális ésmaximális hosszát.

Példa:

$ ./a.out 3 5 20
abcdef
aa 8734 643545
j34z53874

Azaz: 3 sort generáltunk, melyek hossza az [5, 20] zárt intervallumba esik.
Itt a leghosszabb sor (a középső sor) 14 karakterből áll. 
*/

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        fprintf(stderr, "Használat: %s <sorok_száma> <min_hossz> <max_hossz>\n", argv[0]);
        return 1;
    }

    int sorok_szama = atoi(argv[1]);
    int min_hossz = atoi(argv[2]);
    int max_hossz = atoi(argv[3]);

    srand(time(NULL));

    for (int i = 0; i < sorok_szama; i++)
    {
        int aktualis_hossz = min_hossz + (rand() % (max_hossz - min_hossz + 1));
        for (int j = 0; j < aktualis_hossz; j++)
        {
            char c = 33 + (rand() % (126 - 33 + 1));
            putchar(c);
        }
        putchar('\n');
    }

    return 0;
}