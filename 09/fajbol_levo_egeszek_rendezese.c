#include <stdio.h>

/* fájlban lévő egészek rendezése
Írjon programot, ami parancssori argumentumként megkapja egy szöveges állomány nevét.
A fájl soronként egy egész számot tartalmaz.
A program olvassa be a számokat, rendezze őket, majd rendezett formában írja ki a számokat a képernyőre.
*/

void gyorsrendezes(int szamok[], int also, int felso)
{
    if (also < felso)
    {
        int pivot = szamok[felso];
        int i = also - 1;
        int temp;

        for (int j = also; j < felso; j++)
        {
            if (szamok[j] <= pivot)
            {
                i++;
                temp = szamok[i];
                szamok[i] = szamok[j];
                szamok[j] = temp;
            }
        }
        
        temp = szamok[i + 1];
        szamok[i + 1] = szamok[felso];
        szamok[felso] = temp;

        int pi = i + 1;

        gyorsrendezes(szamok, also, pi - 1);
        gyorsrendezes(szamok, pi + 1, felso);
    }
}

void kiir(int n, int tomb[])
{
    for(int i = 0; i < n; i++)
    {
        printf("%d\n", tomb[i]);
    }
}

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

    int szamok[1000];
    int darab = 0;

    while (darab < 1000 && fscanf(fajl, "%d", &szamok[darab]) == 1)
    {
        darab++;
    }
    fclose(fajl);

    gyorsrendezes(szamok, 0, darab - 1);

    kiir(darab, szamok);

    return 0;
}
