#include <stdio.h>

// Írassuk ki az ASCII táblázatot!
// Elegendő csupán a 32-126 (zárt) intervallumot figyelembe venni. 0-tól 31-ig a nem nyomtatható karakterek szerepelnek.
// A 127-es karakter (DEL) sem nyomtatható. 127 felett pedig lehetnek eltérések az egyes kódtáblák között.
// A [32, …, 126] intervallumban viszont mindig ugyanazok a nyomtatható karakterek szerepelnek.

int main()
{
    for (int i = 32; i <= 126; i++)
    {
        printf("%c: %d ", i, i);
        printf("\n");
    }

    return 0;
}