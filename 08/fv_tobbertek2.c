#include <stdio.h>
#include <stdlib.h>

/* függvény adjon vissza több értéket #2
Írjunk egy programot, ami random számokkal feltölt egy 10-elemű tömböt.
A random számok a [10, 99] zárt intervallumból kerüljenek ki.
Írassuk ki a tömb elemeit egymás mellé.
Írjunk egy függvényt, aminek átadjuk a tömböt, s a fv. adja vissza
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
A feladatot most NE mutatókkal oldjuk meg.
A függvény most adjon vissza egy struktúrát, amibe becsomagoljuk a visszaadandó elemeket. 
*/

int randint(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

typedef struct {
    int min;
    int max;
    double avg;
} Ertekek;

Ertekek visszaad(int n, int tomb[])
{
    Ertekek erd;
    erd.min = tomb[0];
    erd.max = tomb[0];
    double osszeg = 0;

    for(int i = 0; i < n; i++) {
        if(tomb[i] < erd.min) erd.min = tomb[i];
        if(tomb[i] > erd.max) erd.max = tomb[i];
        osszeg += tomb[i];
    }
    erd.avg = osszeg / n;

    return erd;
}

int main()
{
    srand(1);

    int tomb[10];
    int n = 10;

    printf("A tömb eredményei: ");
    for(int i = 0; i < n; i++) 
    {
        tomb[i] = randint(10, 99);
        printf("%d ", tomb[i]);
    }
    puts("");

    Ertekek eredmeny = visszaad(n, tomb);

    printf("A legkisebb elem: %d\n", eredmeny.min);
    printf("A legnagyobb elem: %d\n", eredmeny.max);
    printf("Az átlag: %.2lf\n", eredmeny.avg);

    return 0;
}