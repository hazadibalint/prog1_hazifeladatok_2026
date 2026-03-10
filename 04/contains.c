#include <stdio.h>

// egy tömbben szerepel-e egy adott elem?

int contains(int tomb[], int meret, int keresett)
{
    for(int i = 0; i < meret; i++)
    {
        if(tomb[i] == keresett) {
            return 1;
        }
    }

    return 0;
}

int main()
{
    int n;
    int meret = 5;
    int tomb[5] = {1, 2, 3, 4, 5};

    printf("Adj meg egy számot: ");
    scanf("%d", &n);

    printf("Benne van a tömbben a keresett elem? %d\n", contains(tomb, meret, n));

    return 0;
}