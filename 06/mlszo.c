#include <stdio.h>
#include <string.h>

// Kérjünk be szavakat a felh.-tól '*' végjelig. A végén írassuk ki a leghosszabb szó hosszát!
// fgets

int main()
{
    char szo[100];
    int max = 0;
    int darab = 0;

    puts("Adj meg szavakat '*' végjelig!");

    while(1)
    {
        printf("Szó: ");
        fgets(szo, 100, stdin);

        szo[strcspn(szo, "\n")] = '\0';

        int hossz = strlen(szo);
        if(hossz > max) {
            max = hossz;
        }

        if(strcmp(szo, "*") == 0) break;
        darab++;
    } 

    printf("%d db szót adtál meg. A lehosszabb szó %d karakterből áll.\n", darab, max);


    return 0;
}