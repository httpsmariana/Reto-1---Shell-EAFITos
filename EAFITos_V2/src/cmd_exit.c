#include <stdio.h>
int cmd_exit(int argc, char **argv) {
    (void)argc; (void)argv;
    printf("Saliendo...\n");
    return 999;
}
