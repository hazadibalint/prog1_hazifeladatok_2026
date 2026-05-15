#include <stdio.h>

/* Mátrix mellékátló
Hozzon létre a main() fv.-ben egy 6 x 6 méretű mátrixot.
Egy eljárás segítségével írassa ki a mellékátló elemeit.
*/

void mellekatlo_kiir(int matrix[6][6]) 
{
    for (int i = 0; i < 6; i++) 
    {
        printf("%d ", matrix[i][6 - 1 - i]);
    }
    printf("\n");
}

int main(void) 
{
    int matrix[6][6];
    int szamlalo = 1;

    for (int i = 0; i < 6; i++) 
    {
        for (int j = 0; j < 6; j++) 
        {
            matrix[i][j] = szamlalo++;
        }
    }

    mellekatlo_kiir(matrix);

    return 0;
}