#include <stdio.h>
#include "prog1.h"

// Írjunk egy programot, ami egy karaktertömböt feltölt az angol ábécé
// kisbetűivel. A feltöltést egy eljárással oldjuk meg. 
// Módosítsuk úgy az előző programot, hogy ne csak egy szimpla karaktertömböt
// adjunk vissza, hanem egy sztringet. Ez a visszaadott sztring tartalmazza
// az angol ábécé kisbetűit.
// Segítség
// Mi a különbség egy sima karaktertömb és egy sztring között?
// A sztring végén van NUL karakter ('\0'). 

void angolabc_a(char c[], int meret) {
    int j = 0;
    for(int i = 'a'; i <= 'z'; i++) {
        c[j] = (char)i;
        j++;
    }
}

void angolabc_b(char c[]) {
    int j = 0;
    for(int i = 'a'; i <= 'z'; i++) {
        c[j] = (char)i;
        j++;
    }
    c[j] = '\0';
}

int main()
{
    char karakterek_a[26];
    char karakterek_b[27];
    string s_b = karakterek_b;
    int meret = 26;

    angolabc_a(karakterek_a, meret);

    printf("karakterek_a: ");
    for(int i = 0; i < meret; i++) {
        printf("%c ", karakterek_a[i]);
    }
    printf("\n");

    angolabc_b(karakterek_b);

    printf("karakterek_b: %s\n", s_b);
    return 0;
}
