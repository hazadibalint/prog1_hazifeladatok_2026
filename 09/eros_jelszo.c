#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* kellene egy erős jelszó
Egy jelszót tekintsünk erősnek, ha teljesülnek rá a következő feltételek:

    legalább 8 karakter hosszú
    tartalmaz kisbetűt
    tartalmaz nagybetűt
    tartalmaz számjegyet
    tartalmaz speciális karaktert (ezek, idézőjelek között felsorolva: ".,;'" [4 db]) 

Írjunk programot, ami generál egy erős jelszót.

Példa:

$ ./passwd
df6,G43FDS

Az egyszerűség kedvéért a jelszó max. 12 karakter hosszú legyen. 
*/

void shuffle(int n, char tomb[])
{
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        char temp = tomb[i];
        tomb[i] = tomb[j];
        tomb[j] = temp;
    }
}

char veletlen_karakter(char tipus)
{
    if (tipus == 'k') return 'a' + (rand() % 26);
    if (tipus == 'n') return 'A' + (rand() % 26);
    if (tipus == 's') return '0' + (rand() % 10);
    
    char spec[] = ".,;'";
    return spec[rand() % 4];
}

int main(void)
{
    srand(time(NULL));

    char jelszo[13];
    char tipusok[] = {'k', 'n', 's', 'x'};

    jelszo[0] = veletlen_karakter('k');
    jelszo[1] = veletlen_karakter('n');
    jelszo[2] = veletlen_karakter('s');
    jelszo[3] = veletlen_karakter('x');

    for (int i = 4; i < 12; i++)
    {
        char valasztott_tipus = tipusok[rand() % 4];
        jelszo[i] = veletlen_karakter(valasztott_tipus);
    }
    jelszo[12] = '\0';

    shuffle(12, jelszo);

    printf("%s\n", jelszo);

    return 0;
}