#include <stdio.h>

// Írjunk egy programot, amely beolvas egy pozitív egész számot (n),
// majd kiírja n-től 1-ig (zárt intervallum) visszafelé az összes páratlan számot!

int main()
{   
    int n; 
    printf("Adj meg egy pozitív egész számot! ");
    scanf("%d", &n);

    for (n; n >= 1; n--)
    {
        if(n % 2 == 1) {
            printf("%d ", n);
        }
    }
    printf("\n");

    return 0;
}