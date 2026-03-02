#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <dirent.h>

int cmd_listar(int argc, char **argv) {
    (void)argc; (void)argv;

    DIR *d = opendir(".");
    if (!d) {
        perror("listar");
        return 1;
    }

    struct dirent *ent;
    while ((ent = readdir(d)) != NULL) {
        printf("%s\n", ent->d_name);
    }

    closedir(d);
    return 0;
}
