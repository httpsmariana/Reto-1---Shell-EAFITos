#ifndef COMMANDS_H
#define COMMANDS_H

typedef struct {
    const char *name;
    const char *desc;
    const char *usage;
    int (*fn)(int argc, char **argv);
} Command;

const Command* commands_get_all(int *count);
const Command* commands_find(const char *name);

/* comandos */
int cmd_listar(int argc, char **argv);
int cmd_leer(int argc, char **argv);
int cmd_tiempo(int argc, char **argv);
int cmd_crear(int argc, char **argv);
int cmd_help(int argc, char **argv);
int cmd_history(int argc, char **argv);
int cmd_exit(int argc, char **argv);
int cmd_calc(int argc, char **argv);
int cmd_limpiar(int argc, char **argv);
int cmd_usuario(int argc, char **argv);
int cmd_directorio(int argc, char **argv);
int cmd_copiar(int argc, char **argv);
int cmd_estadisticas(int argc, char **argv);

#endif
