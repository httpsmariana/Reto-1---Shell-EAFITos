#define _POSIX_C_SOURCE 200809L
#include "history.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

static char **g_items = NULL;
static size_t g_cap = 0;
static size_t g_len = 0;
static size_t g_start = 0;

void history_init(size_t capacity) {
    g_items = (char**)calloc(capacity, sizeof(char*));
    g_cap = capacity;
}

void history_free(void) {
    if (!g_items) return;
    for (size_t i = 0; i < g_cap; i++) free(g_items[i]);
    free(g_items);
}

void history_add(const char *line) {
    if (!g_items || g_cap == 0) return;

    size_t idx;
    if (g_len < g_cap) {
        idx = (g_start + g_len) % g_cap;
        g_len++;
    } else {
        idx = g_start;
        g_start = (g_start + 1) % g_cap;
        free(g_items[idx]);
    }

    g_items[idx] = strdup(line);
}

void history_print(void) {
    for (size_t i = 0; i < g_len; i++) {
        size_t idx = (g_start + i) % g_cap;
        printf("%zu: %s\n", i + 1, g_items[idx]);
    }
}
