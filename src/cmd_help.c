#include "commands.h"
#include <stdio.h>

int cmd_help(int argc, char **argv) {
    int n = 0;
    const Command *all = commands_get_all(&n);

    if (argc == 1) {
        printf("Comandos disponibles:\n");
        for (int i = 0; i < n; i++) {
            printf("  %-10s - %s\n", all[i].name, all[i].desc);
        }
        return 0;
    }

    const Command *c = commands_find(argv[1]);
    if (!c) {
        printf("help: comando no encontrado\n");
        return 1;
    }

    printf("%s - %s\nUso: %s\n", c->name, c->desc, c->usage);
    return 0;
}
