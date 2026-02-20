#include <stdio.h>
#include <math.h>

int main()
{
    double r;
    printf("Add meg a sugarát a körnek: ");
    scanf("%lf", &r);

    double kerulet = M_PI * 2 * r;
    double terulet = r * r * M_PI;

    printf("A kör kerülete: %lf\n", kerulet);
    printf("A kör területe: %lf\n", terulet);

    return 0;
}