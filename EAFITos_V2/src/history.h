#ifndef HISTORY_H
#define HISTORY_H

#include <stddef.h>

void history_init(size_t capacity);
void history_free(void);
void history_add(const char *line);
void history_print(void);

#endif
