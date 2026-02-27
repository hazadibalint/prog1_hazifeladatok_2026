#include <stdio.h>

// Írjon programot, ami bekér egy pozitív egész számot (n), majd 1-től n-ig (zárt intervallum) kiírja az egész számokat úgy,
// hogy a számok között legyen egy nyíl (" → ").
// Vegyük észre, hogy a nyíl előtt és után van egy-egy szóköz, ill. az utolsó elem után nincs semmi (se szóköz, se nyíl).

int main()
{
    int n;
    printf("Adj meg egy pozitív egész számot! ");
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++)
    {
        printf("%d", i);
        if (i < n) {
            printf(" → ");
        }
        
    }
    printf("\n");

    return 0;
}