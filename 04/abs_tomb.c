#include <stdio.h>

// Írjon eljárást, ami kap egy egészeket tartalmazó tömböt.
// Az eljárás cserélje ki a tömbben lévő negatív számokat az abszolútértékükre!
// Az eljárás a tömböt helyben módosítja.
// A main() fv.-ben írassa ki a tömböt kétszer (a fenti eljárás meghívása előtt, majd után).

void abs_tomb(int tomb[], int meret)
{
    for (int i = 0; i < meret; i++)
    {
        if(tomb[i] < 0) {
            tomb[i] *= -1;
        }
    }
}

int main()
{
    int meret = 5;
    int tomb[5] = {-4, 3, -64, -16, 21};

    printf("Eredeti tömb: ");
    for(int i = 0; i < meret; i++) {
        printf("%d ", tomb[i]);
    }
    printf("\n");

    abs_tomb(tomb, meret);
    printf("Abszolút tömb: ");
    for(int i = 0; i < meret; i++) {
        printf("%d ", tomb[i]);
    }
    printf("\n");
    
    return 0;
}