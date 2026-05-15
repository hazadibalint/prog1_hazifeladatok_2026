#include <stdio.h>
#include <stdlib.h>

/* Dinamikus tömb rendezése (millions.txt)
Rendezzük a millions.txt fájl (link) tartalmát az előadáson vett dinamikus tömb
adatszerkezet használatával.
Bővítse ki az előadáson látott dinamikus tömb implementációját egy void da_clear(DynArray *self);
szignatúrájú eljárással. Az eljárás törölje ki a dinamikus tömbben tárolt összes elemet.
Figyeljen arra is, hogy ne lépjen fel memóriaszivárgás! Ennek ellenőrzésére használja a valgrind eszközt.
Az elemek törlése után a dinamikus tömbbe természetesen ismét lehessen
elemeket beszúrni (ezt is próbálja ki).
*/

typedef struct {
    int *adat;
    int darab;
    int kapacitas;
} DynArray;

DynArray da_create() 
{
    DynArray uj = {malloc(1000000 * sizeof(int)), 0, 1000000};
    return uj;
}

void da_push_back(DynArray *self, int elem) 
{
    if (self->darab >= self->kapacitas) 
    {
        self->kapacitas *= 2;
        self->adat = realloc(self->adat, self->kapacitas * sizeof(int));
    }
    self->adat[self->darab++] = elem;
}

void da_clear(DynArray *self) 
{
    free(self->adat);
    self->adat = malloc(1024 * sizeof(int));
    self->kapacitas = 1024;
    self->darab = 0;
}

int hasonlit(const void *a, const void *b) 
{
    return (*(int*)a - *(int*)b);
}

int main(int argc, char *argv[]) 
{
    if (argc != 2) return 1;
    FILE *fajl = fopen(argv[1], "r");
    if (!fajl) return 1;

    DynArray tomb = da_create();
    int szam;

    while (fscanf(fajl, "%d", &szam) == 1) 
    {
        da_push_back(&tomb, szam);
    }
    fclose(fajl);

    qsort(tomb.adat, tomb.darab, sizeof(int), hasonlit);

    for (int i = 0; i < tomb.darab; i++) 
    {
        printf("%d\n", tomb.adat[i]);
    }

    da_clear(&tomb);
    free(tomb.adat);
    return 0;
}
