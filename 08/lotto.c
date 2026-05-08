#include <stdio.h>
#include <stdlib.h>

/* lottó
Írjunk programot, ami egy adott intervallumon generál N db véletlen számot.
A kimenetben ez elemek rendezve jelenjenek meg!
A kimenetben minden elem garantáltan különböző legyen!

Példa:

Hány db random számot kérsz?
5
Alsó határ: 1
Felső határ (zárt intervallum): 90

A generált számok: 7 23 45 65 88
*/

int randint(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

int main()
{
    srand(1);

    int n;
    puts("Hány db random számot kérsz?");
    scanf("%d", &n);
    int also;
    printf("Alsó határ: ");
    scanf("%d", &also);
    int felso;
    printf("Felső határ: ");
    scanf("%d", &felso);

    int tomb[n];

    printf("Rendezetlen számok: ");
    for(int i = 0; i < n; i++)
    {
        tomb[i] = randint(also, felso);
        printf("%d ", tomb[i]);
    }
    puts("");

    // BUBBLE SORT
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(tomb[i] < tomb[j]) {
                int tmp = tomb[i];
                tomb[i] = tomb[j];
                tomb[j] = tmp;
            }
        }
    }

    printf("Rendezett számok: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", tomb[i]);
    }
    puts("");

    return 0;
}

//NEEDS FIX