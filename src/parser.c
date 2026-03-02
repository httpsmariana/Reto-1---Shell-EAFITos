#define _POSIX_C_SOURCE 200809L
#include "parser.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

static char *dup_range(const char *a, const char *b) {
    size_t n = (size_t)(b - a);
    char *s = (char*)malloc(n + 1);
    if (!s) return NULL;
    memcpy(s, a, n);
    s[n] = '\0';
    return s;
}

int parse_line(const char *line, Args *out) {
    out->argc = 0;
    out->argv = NULL;

    int cap = 8;
    char **argv = (char**)malloc(sizeof(char*) * (size_t)cap);
    if (!argv) return 1;

    const char *p = line;

    while (*p) {
        while (isspace((unsigned char)*p)) p++;
        if (!*p) break;

        char *token = NULL;

        if (*p == '"') {
            p++;
            const char *start = p;
            while (*p && *p != '"') p++;
            token = dup_range(start, p);
            if (*p == '"') p++;
        } else {
            const char *start = p;
            while (*p && !isspace((unsigned char)*p)) p++;
            token = dup_range(start, p);
        }

        if (!token) return 1;

        if (out->argc + 1 >= cap) {
            cap *= 2;
            char **tmp = (char**)realloc(argv, sizeof(char*) * (size_t)cap);
            if (!tmp) return 1;
            argv = tmp;
        }

        argv[out->argc++] = token;
    }

    argv[out->argc] = NULL;
    out->argv = argv;
    return 0;
}

void free_args(Args *a) {
    if (!a || !a->argv) return;
    for (int i = 0; i < a->argc; i++) free(a->argv[i]);
    free(a->argv);
    a->argv = NULL;
    a->argc = 0;
}
