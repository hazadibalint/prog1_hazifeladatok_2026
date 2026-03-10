#include <stdio.h>

// Írjunk függvényt, mely egy adott tömbről eldönti, hogy rendezett-e (*).
// A tömb egész számokat tartalmaz. Az üres tömböt tekintsük rendezettnek.

int rendezett_tomb(int tomb[], int meret)
{
    if(meret <= 1) {
        return 1;
    }
    for(int i = 1; i < meret; i++) {
        if(tomb[i - 1] > tomb[i]) {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int meret = 5;
    int tomb1[5] = {1, 4, 7, 11, 17};
    int tomb2[5] = {6, 4, 66, 12, 1};

    printf("tomb1 rendezett-e? %d\n", rendezett_tomb(tomb1, meret));
    printf("tomb2 rendezett-e? %d\n", rendezett_tomb(tomb2, meret));

    return 0;
}