#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Írjon egy függvényt, ami kap egy egészeket tartalmazó tömböt.
A fv. adja vissza a tömb egy véletlenszerűen kiválasztott elemét.
A függvény szignatúrája:

int choice(const int n, const int tomb[])

Ahol n a tömb elemeinek a számát jelenti. Feltételezhetjük, hogy a tömb legalább egy elemet tartalmaz. 
*/

int choice(const int n, const int tomb[])
{
    int veletlen_index = rand() % n;
    return tomb[veletlen_index];
}

int main(void)
{
    srand(time(NULL));

    int szamok[] = {10, 23, 47, 65, 89, 12, 5};
    int meret = sizeof(szamok) / sizeof(szamok[0]);

    int kivalasztott = choice(meret, szamok);

    printf("A tömb egy véletlen eleme: %d\n", kivalasztott);

    return 0;
}