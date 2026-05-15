#include <stdio.h>
#include <stdlib.h>

int hasonlit(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

void kiir(int n, int tomb[])
{
    for(int i = 0; i < n; i++)
    {
        printf("%d\n", tomb[i]);
    }
}

int main(int argc, char *argv[]) {
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

    int kapacitas = 1000000;
    int *szamok = malloc(kapacitas * sizeof(int));
    if (!szamok)
    {
        printf("Nem sikerült memóriát foglalni!\n");
        fclose(fajl);
        return 1;
    }

    int darab = 0;

    while (fscanf(fajl, "%d", &szamok[darab]) == 1)
    {
        darab++;
        if (darab >= kapacitas)
        {
            kapacitas *= 2;
            int *uj_szamok = realloc(szamok, kapacitas * sizeof(int));
            if (!uj_szamok)
            {
                printf("Elfogyott a memória a bővítés során!\n");
                free(szamok);
                fclose(fajl);
                return 1;
            }
            szamok = uj_szamok;
        }
    }
    fclose(fajl);

    qsort(szamok, darab, sizeof(int), hasonlit);

    kiir(darab, szamok);

    free(szamok);

    return 0;
}