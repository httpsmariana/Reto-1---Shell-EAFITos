#define _POSIX_C_SOURCE 200809L
#include "utils.h"
#include <stdio.h>

int cmd_leer(int argc, char **argv) {
    if (argc != 2) {
        printf("Uso: leer <archivo>\n");
        return 1;
    }

    if (safe_print_file(argv[1], 1024 * 1024) != 0) {
        perror("leer");
        return 1;
    }
    printf("\n");
    return 0;
}
