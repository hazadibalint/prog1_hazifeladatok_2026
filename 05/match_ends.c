#include "prog1.h"
#include <stdio.h>
#include <string.h>

/*
Bemenet: sztringeket tartalmazó tömb. Számoljuk meg, hogy a bemenetben
hány olyan sztring van, melynek a hossza legalább 2 és az
első karaktere egyezik az utolsó karakterével. A visszatérési
érték ezen feltételeket kielégítő sztringek száma legyen.

Példák (Python kóddal, majd át kell írni C-be):

match_ends(["aba", "xyz", "aa", "x", "bbb"])    ->  3
match_ends(["", "x", "xy", "xyx", "xx"])        ->  2
match_ends(["aaa", "be", "abc", "hello"])       ->  1
*/

int match_ends(int n, string words[])
{
    int count = 0;

    for(int i = 0; i < n; i++) {
        string word = words[i];
        int szo_hossz = strlen(word);

        if(szo_hossz >= 2) {
            if(word[0] == word[szo_hossz - 1 ]) {
                count++;
            }
        }
    }

    return count;
}

int main()
{
    string szavak1[] = { "aba", "xyz", "aa", "x", "bbb" };
    string szavak2[] = { "", "x", "xy", "xyx", "xx" };
    string szavak3[] = { "aaa", "be", "abc", "hello" };
    int szavak1_2_meret = 5;
    int szavak3_meret = 4;

    printf("szavak1: %d\n", match_ends(szavak1_2_meret, szavak1));
    printf("szavak2: %d\n", match_ends(szavak1_2_meret, szavak2));
    printf("szavak3: %d\n", match_ends(szavak3_meret, szavak3));  

    for (int i = 0; i < szavak1_2_meret; ++i)
    {
        puts(szavak1[i]);
    }

    return 0;
}