#include <stdio.h>
#include <unistd.h>

int cmd_directorio(int argc, char **argv) {
    (void)argc;
    (void)argv;
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL)
        printf("Directorio actual: %s\n", cwd);
    return 0;
}
