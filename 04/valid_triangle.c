#include <stdio.h>

// Írjunk egy függvényt, ami egy háromszögről eldönti, hogy megszerkeszthető-e vagy sem.
// Deklaráljuk a függvényt. (main függvény elé tenni?)
// Majd definiáljuk a függvényt.
// Végül hívjuk meg a függvényt, próbáljuk ki, teszteljük.

int valid_triangle(int a, int b, int c);

int main()
{
    int a, b, c;
    printf("Adj meg 3 pozitív oldal hosszt (ilyen alakban: a b c): ");
    scanf("%d %d %d", &a, &b, &c);
    while(1) {
        if(a > 0  && b > 0 && c > 0) {
            break;
        }
        printf("Hiba: negatív számot adtál meg!\n");
        printf("Adj meg 3 pozitív oldal hosszt (ilyen alakban: a b c): ");
        scanf("%d %d %d", &a, &b, &c);
    }

    valid_triangle(a,b,c);

    return 0;
}

int valid_triangle(int a, int b, int c)
{
    if ((a + b < c) || (b + c < a) || (a + c < b)) {
        printf("Nem megszerkeszthető.\n");
        return 1;
    }

    printf("Megszerkeszthető.\n");
    return 0;
}