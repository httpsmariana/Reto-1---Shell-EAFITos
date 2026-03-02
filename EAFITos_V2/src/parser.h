#ifndef PARSER_H
#define PARSER_H

typedef struct {
    int argc;
    char **argv;
} Args;

int parse_line(const char *line, Args *out);
void free_args(Args *a);

#endif
