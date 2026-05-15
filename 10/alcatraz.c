#include <stdio.h>

/* Szökés Alcatrazból

Az alcatrazi börtön igazgatója a jövő héten ünnepli a 60. születésnapját.
Eme különleges esemény alkalmából úgy döntött, hogy szabadon ereszt néhány elítéltet.
Ehhez a következő játékot találta ki. A börtönben 600 cella van, ezek 1-től 600-ig vannak sorszámozva.
Kezdetben minden cella zárva van. Az őr odamegy az első cellához, s minden egyes zárat kinyit.
Ezután odamegy a 2. cellához, s minden második cella zárján fordít egyet (a nyitottat bezárja,
a zártat kinyitja). Ezután veszi a 3. cellát, s minden harmadik cella zárján fordít egyet.
Ezt megismétli az összes cellával. Akiknek a végén az ajtajuk nyitva marad, azok szabadon távozhatnak.

Kérdés: kik azok a szerencsés fickók, akiket futni enged a börtönigazgató?
(Az eredményt vizsgálva felfedezünk vmilyen mintát?)

Példa 8 ajtóval:

00000000        inicializáció, minden ajtó zárva
11111111        1. lépés, minden záron fordítunk
10101010        2. lépés, minden második záron fordítunk
10001110        3. lépés, minden harmadik záron fordítunk
10011111        4. lépés, minden negyedik záron fordítunk
10010111        5. lépés, minden ötödik záron fordítunk
10010011        6. lépés, minden hatodik záron fordítunk
10010001        7. lépés, minden hetedik záron fordítunk
10010000        8. lépés, minden nyolcadik záron fordítunk

Ellenőrzés

A nyitott ajtók számát írja egymás mellé s küldje be az eredményt.
Ha pl. az 5-ös, 13-as és 67-es cellák maradnak nyitva, akkor a következő számot küldje be: 51367 .

Ez az összevont kiíratás (pl. "51367") csakis az önellenőrzéshez kell!
Ha jó az eredmény, akkor a képernyőre egy normális, olvasható kimenetet írjunk ki (pl. "5, 13, 67"). 
*/
int main(void) 
{
    int cellak[601] = {0};

    for (int i = 1; i <= 600; i++) 
    {
        for (int j = i; j <= 600; j += i) 
        {
            cellak[j] = !cellak[j];
        }
    }

    int elso = 1;
    for (int i = 1; i <= 600; i++) 
    {
        if (cellak[i]) 
        {
            if (!elso) 
            {
                printf(", ");
            }
            printf("%d", i);
            elso = 0;
        }
    }
    printf("\n");

    for (int i = 1; i <= 600; i++) 
    {
        if (cellak[i]) 
        {
            printf("%d", i);
        }
    }
    printf("\n");

    return 0;
}