#include <stdio.h>

// Írjunk egy programot, amely beolvas egy pozitív egész számot (n),
// majd kiírja 1-től n-ig (zárt intervallum) az összes néggyel osztható számot!

int main()
{
    int n;

    printf("Adj meg egy pozitív egész számot! ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        if (i % 4 == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}