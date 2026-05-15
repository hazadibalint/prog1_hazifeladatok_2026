#include <stdio.h>

/* ELEMZŐ (B PROGRAM)
A "B" program vegye inputként az előzőleg előállított állományt, s írja ki,
hogy melyik a leghosszabb sor, s annak mennyi a hossza.

Példa:

$ ./a.out teszt.txt
2 14

Ha a fenti példára futtatjuk, akkor a 2. sorban található a leghosszabb sor,
melynek a hossza 14 karakter. */

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Használat: %s <fájlnév>\n", argv[0]);
        return 1;
    }

    FILE *fajl = fopen(argv[1], "r");
    if (!fajl)
    {
        printf("Hiba a fájl megnyitásakor!\n");
        return 1;
    }

    int leghosszabb_sor_index = 0;
    int leghosszabb_hossz = -1;

    int aktualis_sor_index = 1;
    int aktualis_hossz = 0;
    int c;

    while ((c = fgetc(fajl)) != EOF)
    {
        if (c == '\n')
        {
            if (aktualis_hossz > leghosszabb_hossz)
            {
                leghosszabb_hossz = aktualis_hossz;
                leghosszabb_sor_index = aktualis_sor_index;
            }
            aktualis_sor_index++;
            aktualis_hossz = 0;
        }
        else
        {
            aktualis_hossz++;
        }
    }

    if (aktualis_hossz > 0)
    {
        if (aktualis_hossz > leghosszabb_hossz)
        {
            leghosszabb_hossz = aktualis_hossz;
            leghosszabb_sor_index = aktualis_sor_index;
        }
    }

    fclose(fajl);

    if (leghosszabb_hossz != -1)
    {
        printf("%d %d\n", leghosszabb_sor_index, leghosszabb_hossz);
    }

    return 0;
}