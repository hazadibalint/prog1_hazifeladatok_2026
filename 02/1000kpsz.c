#include <stdio.h>

// Ha felsoroljuk a 10-nél kisebb pozitív egész számokat, melyek 3-nak vagy 5-nek a többszörösei,
// akkor a köv. számokat kapjuk: 3, 5, 6 és 9. Ezek összege 23.
// Állapítsuk meg azon 1000-nél kisebb számok összegét, melyek 3-nak vagy 5-nek a többszörösei.

int main()
{
    int sum = 0;

    for (int i = 1; i < 1000; i++)
    {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }

    printf("Eredmény: %d\n", sum);

    return 0;
}