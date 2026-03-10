#include <stdio.h>

int is_even(int n)
{
    if(n % 2 == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int is_odd(int n)
{
    if(n % 2 == 1) {
        return 1;
    }
    else {
        return 0;
    }
}

int is_odd2(int n)
{
    if(is_even(n) == 0) {
        return 1;
    }
    else {
        return 0;
    }
}

int main()
{
    int n;
    printf("Adj meg egy számot! ");
    scanf("%d", &n);

    printf("Páros: %d\n", is_even(n));
    printf("Páratlan: %d\n", is_odd(n));
    printf("Páratlan2: %d\n", is_odd2(n));

    return 0;
}