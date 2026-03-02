#include <stdio.h>
#include <ctype.h>

int cmd_estadisticas(int argc, char **argv) {
    if (argc != 2) {
        printf("Uso: estadisticas <archivo>\n");
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error al abrir archivo");
        return 1;
    }

    int lineas = 0, palabras = 0, caracteres = 0;
    int c, en_palabra = 0;

    while ((c = fgetc(file)) != EOF) {
        caracteres++;
        if (c == '\n') lineas++;
        if (isspace(c)) {
            en_palabra = 0;
        } else if (!en_palabra) {
            palabras++;
            en_palabra = 1;
        }
    }

    fclose(file);

    printf("Estadísticas del archivo:\n");
    printf("Líneas: %d\n", lineas);
    printf("Palabras: %d\n", palabras);
    printf("Caracteres: %d\n", caracteres);
    return 0;
}
