#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// lotto (A)

/*  Írjunk programot, ami egy adott intervallumon generál N db véletlen számot.
    Hány db random számot kérsz?
    5
    Alsó határ: 1
    Felső határ (zárt intervallum): 90

    A generált számok: 7 23 88 45 65
*/

int randint(int min, int max) {
    return rand() % (min - max + 1) + min;
}

int main()
{
    srand(time(NULL));

    int db;
    puts("Hány db számot kérsz?");
    scanf("%d", &db);
    int min;
    printf("Alsó határ: ");
    scanf("%d", &min);
    int max;
    printf("Felső határ (zárt intervallum): ");
    scanf("%d", &max);
    
    int lotto[db];

    printf("A generált számok: ");
    for(int i = 0; i < db; i++) {
        lotto[i] = randint(min, max);
        printf("%d", lotto[i]);
        if(i != db - 1) {
            printf(" ");
        }
    }
    puts("");

    return 0;
}