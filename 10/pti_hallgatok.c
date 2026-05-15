#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* PTI-s hallgatók
Adott az alábbi nevek.csv szöveges állomány (ebben a mezők egymástól vesszővel vannak elválasztva):

aladar,25,MI
bela,23,pti
denes,22,GI
cecil,21,mi
jozsef,22,PTI
geza,26,PTi

A sorok felépítése: keresztnév, életkor, szak. Vegyük észre, hogy a szak megjelölésében keverednek
a kis- és nagybetűk.

Írjunk programot, ami beolvassa ezt a fájlt, majd kiírja az stdout-ra a PTI-s hallgatók
nevét ábécésorrendben, nagy kezdőbetűkkel ellátva. Példa:

bash$ ./pti.py
Bela, Geza, Jozsef

A kimenetben a nevek vesszővel vannak elválasztva. A vessző után szóköz is szerepel.

Megjegyzés

Ha C-ben akarjuk leprogramozni a feladatot, akkor legyen egy kis kiegészítés:
feltételezhetjük, hogy az input file maximum 100 sort tartalmaz. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char nev[50];
} Hallgato;

int hasonlit(const void *a, const void *b) 
{
    return strcmp(((Hallgato*)a)->nev, ((Hallgato*)b)->nev);
}

int main(void) 
{
    FILE *fajl = fopen("nevek.csv", "r");
    if (!fajl) return 1;

    Hallgato pti_sek[100];
    int darab = 0;

    char nev[50];
    int kor;
    char szak[10];

    while (fscanf(fajl, "%49[^,],%d,%9s\n", nev, &kor, szak) == 3) 
    {
        for (int i = 0; szak[i]; i++) 
        {
            szak[i] = tolower(szak[i]);
        }

        if (strcmp(szak, "pti") == 0) 
        {
            nev[0] = toupper(nev[0]);
            strcpy(pti_sek[darab].nev, nev);
            darab++;
        }
    }
    fclose(fajl);

    qsort(pti_sek, darab, sizeof(Hallgato), hasonlit);

    for (int i = 0; i < darab; i++) 
    {
        printf("%s", pti_sek[i].nev);
        if (i < darab - 1) 
        {
            printf(", ");
        }
    }
    printf("\n");

    return 0;
}