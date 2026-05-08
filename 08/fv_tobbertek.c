#include <stdio.h>
#include <stdlib.h>

/* függvény adjon vissza több értéket #1
Egy függvény mindig egyetlen értéket ad vissza.
Mutatók segítségével azonban megoldható, hogy egy függvény
(ami inkább eljárás lesz) akár több értéket is "visszaadjon".
Írjunk egy programot, ami random számokkal feltölt egy 10-elemű tömböt.
A random számok a [10, 99] zárt intervallumból kerüljenek ki. Írassuk ki a tömb elemeit egymás mellé.
Írjunk egy "függvényt", aminek átadjuk a tömböt, s a fv. adja vissza
1) a tömb legkisebb elemét,
2) a tömb legnagyobb elemét,
3) a tömb elemeinek az átlagát.
Ezt a három értéket is írassuk ki a képernyőre.

Példa:

A tömb elemei: 13, 57, 23, 71, 11, 68, 88, 59, 10, 32
Legkisebb elem: 10
Legnagyobb elem: 88
Az elemek átlaga: 43.2

Kérdés
Tesztelés során hasznos lehet, ha minden futtatás során ugyanazokat a random számokat kapjuk.
Ezt hogyan tudjuk elérni?
Megjegyzés
Erre majd nézünk egy elegánsabb megoldást is. Egyelőre oldjuk meg ezt a feladatot mutatókkal. 
*/

int randint(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void ertekek_visszaadasa(int n, int tomb[], int *min, int *max, double *avg)
{
    *min = tomb[0];
    *max = tomb[0];
    double osszeg = 0;

    for(int i = 0; i < n; i++)
    {
        if(tomb[i] < *min) *min = tomb[i];
        if(tomb[i] > *max) *max = tomb[i];
        osszeg += tomb[i];
    }
    *avg = osszeg / n;
}

int main()
{
    srand(1);

    int tomb[10];
    int meret = 10;
    int legkisebb;
    int legnagyobb;
    double atlag;

    printf("A tömb elemei: ");
    for(int i = 0; i < meret; i++)
    {
        tomb[i] = randint(10, 99);
        printf("%d ", tomb[i]);
    }
    puts("");

    ertekek_visszaadasa(meret, tomb, &legkisebb, &legnagyobb, &atlag);

    printf("A legkisebb elem: %d\n", legkisebb);
    printf("A legnagyobb elem: %d\n", legnagyobb);
    printf("Az átlag: %.2lf\n", atlag);

    return 0;
}