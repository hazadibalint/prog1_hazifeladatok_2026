#include <stdio.h>

// Írjon függvényt, ami vissza adja a legnagyobb osztóját a megadott számnak ( önmagát kivéve ),
// majd írjon a main függvényben egy ciklust, kiírja az első 50 szám legnagyobb osztóját a függvény felhasználásával.

int legnagyobboszto(int szam)
{
    for(int i = szam / 2; i >= 1; i--) {
        if(szam % i == 0) {
            return i;
        }
    }

    return 0;
}

int main()
{
    int meret = 50;

    for(int i = 1; i <= 50; i++)
    {
        printf("%d. osztója, önmagán kívül: %d\n", i, legnagyobboszto(i));
    }

    return 0;
}