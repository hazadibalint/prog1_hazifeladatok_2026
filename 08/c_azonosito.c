#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define BUFSIZE 255

/* C azonosítók
A C nyelvben egy azonosítóra a következők teljesülnek:
-csak alfanumerikus karakterek (a-z, A-Z, 0-9) szerepelnek benne, ill. az aláhúzás jel ('_')
-betűvel (a-z, A-Z) vagy aláhúzás jellel ('_') kezdődik [azaz nem szerepelhet számjegy az elején]
-legalább egy karakter hosszú 
Írjunk egy programot, ami '*' végjelig sztringeket olvas, s minden sztringről eldönti, hogy azonosító-e vagy sem.
Az azonosító tesztelését egy függvénnyel végezzük el! A függvény deklarációja így nézzen ki:
int is_valid_c_identifier(const char* input);
A kimenetben a YES egy igaz értéket, a NO egy hamis értéket jelöl
(aszerint, hogy a sztring szabályos C azonosító-e vagy sem).

Példa:

Adj meg sztringeket '*' végjelig!

Input: i
YES

Input: long_and_mnemonic_identifier
YES

Input:
NO

Input: it_contains_1number
YES

Input: it_contains_CapitalLetters
YES

Input: dot.is_not_accepted
NO

Input: 1variable
NO

Input: thisiscorrectalthoughthewordsarenotseparated
YES

Input: _
YES

Input: _foo
YES

Input: foo_
YES

Input: _foo_
YES

Input: foo_bar
YES

Input: foo__bar
YES

Input: a1234
YES

Input: a1234_2414
YES

Input: a1234_2_414
YES

Input: a1234__2414
YES

Input: *
*/

int is_valid_c_identifier(const char* input)
{
    int hossz = strlen(input);

    if(hossz < 1) return 0;

    if(!isalpha(input[0]) && input[0] != '_') return 0;

    for(int i = 0; i < hossz; i++) {
        if(!isalnum(input[i]) && input[i] != '_') return 0;
    }

    return 1;
}

int main()
{
    char text[BUFSIZE];
    puts("Adj meg sztringeket '*' végjelig!");
    puts("");
    
    while (1)
    {
        printf("Input: ");
        fgets(text, BUFSIZE, stdin);
        text[strlen(text) - 1] = '\0';

        if(strcmp(text, "*") == 0) break;

        if(is_valid_c_identifier(text)) {
            puts("YES");
        }
        else {
            puts("NO");
        }
        puts("");
    }

    return 0;
}
