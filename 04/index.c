#include <stdio.h>

// egy tömbben hol (melyik indexpozíción) szerepel egy adott elem?
// Ha a tömbben nincs benne az adott elem, akkor a fv.-nek milyen értéket kellene visszaadni?

int my_index(int tomb[], int meret, int keresett)
{
    for(int i = 0; i < meret; i++)
    {
        if(tomb[i] == keresett) {
            return i;
        }
    }

    return -1;
}

int main()
{
    int meret = 5;
    int tomb[5] = {1, 2, 3, 4, 5};

    int n;
    printf("Adj meg egy számot! ");
    scanf("%d", &n);

    printf("Melyik index-en található meg a(z) %d szám? %d\n", n, my_index(tomb, meret, n));

    return 0;
}