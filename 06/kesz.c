#include <stdio.h>

/* Kérjünk be egész számokat 0 végjelig az [1, 99] zárt intervallumból.
A bevitel után írassuk ki, hogy hány különböző számot adtunk meg. 
Az [1, 99] intervallumon kívülről ne fogadjunk el inputot.
A végén még tüntessük fel a megadott különböző számokat is növekvő sorrendben. */

int main()
{
    int min = 1;
    int max = 99;
    int szam;
    int szam_lista[100] = {0};

    puts("Adj meg 0 végjelig egész számokat az [1, 99] intervallumból!");

    do {
        printf("Szám: ");
        scanf("%d", &szam);

        if(szam >= 1 && szam <= 99) {
            szam_lista[szam] = 1;
        }
        else if(szam != 0) {
            puts("Ez a szám kívül esik az elfogadható intervallumon!");
        }
    } while(szam != 0);
    
    int darab = 0;
    for(int i = min; i <= max; i++) {
        if(szam_lista[i] == 1) {
            darab++;
        }
    }

    printf("%d db különböző szám lett megadva.\n", darab);

    if(darab > 0) {
        printf("Ezek (növekvő sorrendben): ");
        int elso = 1;
        for(int i = min; i <= max; i++) {
            if(szam_lista[i] == 1) {
                if(!elso) {
                    printf(", ");
                }
                printf("%d", i);
                elso = 0;
            }
        }
        puts("");
    }

    return 0;
}