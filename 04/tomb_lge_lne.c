#include <stdio.h>

// A: Írjunk fv.-t, ami visszaadja egy egészeket tartalmazó tömb legkisebb elemét.
// B: Írjunk fv.-t, ami visszaadja egy egészeket tartalmazó tömb legnagyobb elemét.
// Feltételezhetjük, hogy a tömb legalább 1 db elemet tartalmaz.

int legkisebb_elem(int tomb[],int meret)
{
    int elem = tomb[0];

    for(int i = 1; i < meret; i++)
    {
        if(elem > tomb[i]) {
            elem = tomb[i];
        }
    }

    return elem;
}

int legnagyobb_elem(int tomb[],int meret)
{
    int elem = tomb[0];

    for(int i = 1; i < meret; i++)
    {
        if(elem < tomb[i]) {
            elem = tomb[i];
        }
    }

    return elem;
}

int main()
{
    int meret = 5;
    int tomb[5] = {7, 22, 3, 44, 5};

    printf("legkisebb elem: %d\n", legkisebb_elem(tomb, meret));
    printf("legnagyobb elem: %d\n", legnagyobb_elem(tomb, meret));

    return 0;
}