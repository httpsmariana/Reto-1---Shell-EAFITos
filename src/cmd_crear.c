#define _POSIX_C_SOURCE 200809L
#include <stdio.h>

int cmd_crear(int argc, char **argv) {
    if (argc != 2) {
        printf("Uso: crear <archivo>\n");
        return 1;
    }

    FILE *f = fopen(argv[1], "wb");
    if (!f) {
        perror("crear");
        return 1;
    }

    fclose(f);
    printf("Archivo creado: %s\n", argv[1]);
    return 0;
}
