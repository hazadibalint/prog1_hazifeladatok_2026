#include <stdio.h>
#include <stdlib.h>

/* Hatoslottó
A Hatoslottó e heti nyerőszámaira a következők teljesültek:

    a 6 szám összege 90
    a 6 szám szorzata 996300 

Érdekességképpen vegyük észre, hogy ha a szorzatban a nullákat nem számítjuk,
akkor csupa 3-mal osztható számjegyet látunk (3, 6, 9).

Mik voltak az e heti nyerőszámok?

Megjegyzés: a Hatoslottó játékban 45 számból 6-ot kell megjelölni.

Fun fact: ez a feladat nem kamu. Tényleg volt egy ilyen lottóhúzás 2016-ban.

Kihívás

A futási időt szorítsuk le 1 mp. alá. Linux alatt a time paranccsal tudjuk mérni egy
program futási idejét. Példa:

$ time sleep 2

real    0m2.001s
user    0m0.000s
sys     0m0.000s

A "real" sort kell nézni, ez lesz a valós futási idő (wall-clock time).
*/

void keres(int index, int start, int aktualis[], int osszeg, long long szorzat) 
{
    if (osszeg > 90 || szorzat > 996300) return;

    if (index == 6) 
    {
        if (osszeg == 90 && szorzat == 996300) 
        {
            printf("A nyerőszámok: %d, %d, %d, %d, %d, %d\n", 
                   aktualis[0], aktualis[1], aktualis[2], aktualis[3], aktualis[4], aktualis[5]);
            exit(0);
        }
        return;
    }

    for (int i = start; i <= 45; i++) 
    {
        aktualis[index] = i;
        keres(index + 1, i + 1, aktualis, osszeg + i, szorzat * i);
    }
}

int main(void) 
{
    int szamok[6];
    keres(0, 1, szamok, 0, 1);
    return 0;
}