#include <stdio.h>
#include <unistd.h>
#include <pwd.h>

int cmd_usuario(int argc, char **argv) {
    (void)argc;
    (void)argv;
    struct passwd *pw = getpwuid(getuid());
    if (pw)
        printf("Usuario: %s\n", pw->pw_name);
    return 0;
}
