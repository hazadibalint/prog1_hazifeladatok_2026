#include <stdio.h>

int main()
{
    double a;
    double b;

    printf("Add meg a(z) a oldal hosszát: ");
    scanf("%lf", &a);
    printf("Add meg a(z) b oldal hosszát: ");
    scanf("%lf", &b);

    double kerulet = 2 * (a + b);
    double terulet = a * b;

    printf("A téglalap kerülete: %lf\n", kerulet);
    printf("A téglalap területe: %lf\n", terulet);

    return 0;
}
