#define _POSIX_C_SOURCE 200809L
#include "repl.h"
#include "parser.h"
#include "commands.h"
#include "history.h"

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static volatile sig_atomic_t g_sigint = 0;

static void on_sigint(int sig) {
    (void)sig;
    g_sigint = 1;
    ssize_t _ = write(STDOUT_FILENO, "\n", 1);
(void)_;
}

static void on_sigtstp(int sig) {
    (void)sig;
    ssize_t _ = write(STDOUT_FILENO, "\n", 1);
(void)_;
}

void repl_run(void) {
    signal(SIGINT, on_sigint);
    signal(SIGTSTP, on_sigtstp);

    history_init(100);

    char *line = NULL;
    size_t cap = 0;

    while (1) {
        printf("EAFITos> ");
        fflush(stdout);

        ssize_t n = getline(&line, &cap, stdin);
        if (n < 0) {
            printf("\n");
            break;
        }

        if (n > 0 && line[n - 1] == '\n') line[n - 1] = '\0';
        if (line[0] == '\0') continue;

        history_add(line);

        Args a = {0};
        if (parse_line(line, &a) != 0 || a.argc == 0) {
            free_args(&a);
            continue;
        }

        const Command *cmd = commands_find(a.argv[0]);
        if (!cmd) {
            printf("Comando no reconocido: %s (usa: help)\n", a.argv[0]);
            free_args(&a);
            continue;
        }

        int rc = cmd->fn(a.argc, a.argv);
        free_args(&a);

        if (rc == 999) break;
    }

    free(line);
    history_free();
}
