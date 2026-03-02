#include <stdio.h>

// Írjunk egy programot, ami bekér egy magasságot, majd kirajzol két derékszögű háromszöget egymás mellé
// az alább látható módon. (A két háromszög között 2 db szóköz legyen).

// magassag: 3

//   #  #
//  ##  ##
// ###  ###

int main()
{
    int m;
    printf("Add meg a magasságot! ");
    scanf("%d", &m);

    printf("\n");

    for(int i = 0; i < m; i++)
    {
        for(int k = 0; k <= m - i; k++)
        {
            printf(" ");
        }
        for(int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");
        for(int l = 0; l <= i; l++)
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
