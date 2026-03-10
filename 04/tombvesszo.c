#include <stdio.h>

// Írjon eljárást, ami kap egy tömböt, s kiírja a tömb elemeit egymás mellé. Az elemek között legyen vessző és szóköz.
// Az utolsó elem után csak sortörés szerepeljen!

void tomb_kiir(int tomb[], int meret)
{
    for(int i = 0; i < meret; i++) {
        printf("%d", tomb[i]);
        if(i < meret- 1) {
            printf(", ");
        }
    }
    printf("\n");
}

int main()
{
    int meret = 5;
    int tomb[5] = {1,4,13,6,7};

    tomb_kiir(tomb,meret);

    return 0;
}