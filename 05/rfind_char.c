#include <stdio.h>
#include <string.h>
#include "prog1.h"

// Az s alapsztringben keressük a c karakter utolsó előfordulásának a helyét.
// Visszatérési érték: a c utolsó előfordulásának az indexe az s-ben.
// Ha nincs benne: -1 a visszatérési érték.

int rfind_char(string s, char c)
{
    int hossz = strlen(s);
    int utolso_index = 0;

    for(int i = 0; i < hossz; i++) {
        if(s[i] == c) {
            utolso_index = i;
        }
    }
    if(utolso_index == 0) {
        return -1;
    }

    return utolso_index;
}

int main()
{
    string s = get_string("Adj meg egy szót ");
    puts("");

    char c;
    printf("Adj meg a keresett betűt! ");
    scanf("%c", &c);
    puts("");

    printf("Utolsó előfordulása a(z) %c betűnek a(z) %s szóban: %d index\n",c, s, rfind_char(s, c));

    return 0;
}