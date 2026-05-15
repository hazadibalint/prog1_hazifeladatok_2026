#include <stdio.h>
#include <ctype.h>

/* strcmp but better
Implementálja az int strcmpi(const char* s1, const char* s2); szignatúrával rendelkező függvényt.
A fv. hasonlóan működjön az strcmp() fv.-hez, de a kis- és nagybetűket NE különböztesse meg.
Vagyis pl. az "ez" és az "EZ" szavakat tekintse egyformának.
*/

int strcmpi(const char* s1, const char* s2) 
{
    while (*s1 && (tolower((unsigned char)*s1) == tolower((unsigned char)*s2))) 
    {
        s1++;
        s2++;
    }
    return tolower((unsigned char)*s1) - tolower((unsigned char)*s2);
}

int main(void) 
{
    printf("%d\n", strcmpi("ez", "EZ"));
    printf("%d\n", strcmpi("Alma", "alMa"));
    printf("%d\n", strcmpi("alma", "banan"));
    return 0;
}