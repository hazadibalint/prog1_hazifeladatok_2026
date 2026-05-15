#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define VERZIO "v1.0.0"

typedef struct {
    const char *azonosito;
    const char *leiras;
    const char *fajlnev;
    const char *tartalom;
} Sablon;

Sablon sablonok[] = {
    {"c",    "C forráskód",      "main.c",    "#include <stdio.h>\n\nint main()\n{\n\tprintf(\"Hello World!\\n\");\n\n\treturn 0;\n}"},
    {"java", "Java forráskód",   "main.java", "public class main\n{\n\tpublic static void main(String[] args)\n\t{\n\t\tSystem.out.println(\"Hello World!\");\n\t}\n}"},
    {"py",   "Python 3 forráskód","main.py",   "print(\"Hello World!\")"},
    {"sh",   "Bash forráskód",   "main.sh",   "#!/bin/bash\necho \"Hello World!\""}
};
const int sablonok_szama = sizeof(sablonok) / sizeof(Sablon);

void sugo_kiirasa()
{
    printf("alap %s\n\nHasználat: alap <sablon_azonosító> [opció]\n\n", VERZIO);
    printf("Elérhető opciók:\n");
    printf("-h, --help      súgó megjelenítése\n");
    printf("-v, --version   verziószám kiírása\n");
    printf("--stdout        nem hoz létre fájlt, csak az eredményt írja ki\n\n");
    printf("Elérhető sablonok:\n\n");
    for (int i = 0; i < sablonok_szama; i++)
    {
        printf("* %-5s - %s [%s]\n", sablonok[i].azonosito, sablonok[i].leiras, sablonok[i].fajlnev);
    }
}

int kod_generalasa(Sablon *sablon, int kepernyore)
{
    if (kepernyore)
    {
        printf("%s", sablon->tartalom);
        return 0;
    }

    FILE *ellenorzes = fopen(sablon->fajlnev, "r");
    if (ellenorzes != NULL)
    {
        fclose(ellenorzes);
        printf("Hiba: az adott '%s' már létezik.\n", sablon->fajlnev);
        exit(1);
    }

    FILE *f = fopen(sablon->fajlnev, "w");
    if (f == NULL)
    {
        printf("Hiba a fájl létrehozásakor!\n");
        exit(1);
    }
    
    fprintf(f, "%s", sablon->tartalom);
    fclose(f);
    printf("# '%s' létrehozva\n", sablon->fajlnev);
    
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        sugo_kiirasa();
        return 0;
    }

    int kepernyore = 0;
    const char *cel_azonosito = NULL;

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
        {
            sugo_kiirasa();
            return 0;
        }
        if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0)
        {
            printf("alap %s\n", VERZIO);
            return 0;
        }
        if (strcmp(argv[i], "--stdout") == 0) kepernyore = 1;
        else if (cel_azonosito == NULL) cel_azonosito = argv[i];
    }

    if (cel_azonosito == NULL) {
        sugo_kiirasa();
        return 0;
    }

    for (int i = 0; i < sablonok_szama; i++)
    {
        if (strcmp(cel_azonosito, sablonok[i].azonosito) == 0)
        {
            return kod_generalasa(&sablonok[i], kepernyore);
        }
    }

    printf("Hiba: ismeretlen argumentum: '%s'\n", cel_azonosito);
    exit(1);
}