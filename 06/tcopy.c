#include <stdio.h>
#include <stdlib.h>

/* A felh.-tól kérdezzük meg, hogy hány db számot szeretne megadni, majd kérjünk be
tőle pontosan ennyi egész értéket. Ezeket tároljuk el egy tömbben. A tömbről készítsünk
egy másolatot, s ebben a másolatban a bevitt számok abszolútértékét tároljuk le.
A program végén írassuk ki a másolat tömb tartalmát (ami az abszolútértékeket tartalmazza),
majd az eredeti tömb tartalmát. A kiíratás a fenti módon történjen! Minden elem közé vessző
és szóköz, az utolsó elem után csak sortörés. */

int main()
{
    int darab;
    puts("Hány darab számot szeretnél bevinni?");
    scanf("%d", &darab);

    int szamok[darab];
    int szamok_masolat[darab];

    for(int i = 0; i < darab; i++) {
        printf("%d. szám: ", i + 1);
        scanf("%d", &szamok[i]);
        szamok_masolat[i] = abs(szamok[i]);
    }

    printf("A bevitt számok abszolút értéke: ");
    for(int j = 0; j < darab; j++) {
        printf("%d", szamok_masolat[j]);
        if(j < darab - 1) {
            printf(", ");
        }
    }
    puts("");

    printf("A megadott számok: ");
    for(int j = 0; j < darab; j++) {
        printf("%d", szamok[j]);
        if(j < darab - 1) {
            printf(", ");
        }
    }
    puts("");

    return 0;
}
