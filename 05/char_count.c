#include <stdio.h>
#include <string.h>
#include "prog1.h"

// / Az s sztringben a c karakter hányszor fordul elő?
// int char_count(string s, char c);

// Példák:

// char_count("Abba", 'b') -> 2
// char_count("Abba", 'a') -> 1
// char_count("Abba", 'x') -> 0

int char_count(string s, char c)
{
    int hossz = strlen(s);
    int count = 0;

    for(int i = 0; i < hossz; i++) {
        if(s[i] == c)
        count++;
    }

    return count;
}

int main()
{
    string szo = get_string("Adj meg egy szót! ");
    char betu;
    printf("Add meg a keresett betűt! ");
    scanf("%c", &betu);

    printf("A keresett betű a(z) %c, a %s-ban %dx fordul elő.\n", betu, szo, char_count(szo, betu));

    return 0;
}
