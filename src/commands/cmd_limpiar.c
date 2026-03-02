#include <stdio.h>

int cmd_limpiar(int argc, char **argv) {
    (void)argc;
    (void)argv;
    printf("\033[H\033[J");
    return 0;
}
