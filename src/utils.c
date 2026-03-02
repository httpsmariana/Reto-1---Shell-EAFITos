#define _POSIX_C_SOURCE 200809L
#include "utils.h"
#include <stdio.h>

int safe_print_file(const char *path, size_t max_bytes) {
    FILE *f = fopen(path, "rb");
    if (!f) return -1;

    size_t total = 0;
    unsigned char buf[4096];

    while (!feof(f)) {
        size_t n = fread(buf, 1, sizeof(buf), f);
        if (n == 0) break;

        if (total + n > max_bytes) {
            n = (max_bytes > total) ? (max_bytes - total) : 0;
        }

        if (n > 0) fwrite(buf, 1, n, stdout);
        total += n;

        if (total >= max_bytes) {
            printf("\n[Salida truncada]\n");
            break;
        }
    }

    fclose(f);
    return 0;
}
