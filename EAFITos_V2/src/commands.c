#include <string.h>
#include "commands.h"

static const Command g_cmds[] = {
    {"listar", "Lista el contenido del directorio actual", "listar", cmd_listar},
    {"leer", "Lee y muestra un archivo", "leer <archivo>", cmd_leer},
    {"tiempo", "Muestra fecha y hora actual", "tiempo", cmd_tiempo},
    {"crear", "Crea un archivo vacío", "crear <archivo>", cmd_crear},
    {"help", "Muestra ayuda de comandos", "help [comando]", cmd_help},
    {"history", "Muestra el historial", "history", cmd_history},
    {"exit", "Sale de la shell", "exit", cmd_exit},
    {"calc", "Calculadora básica", "calc <num1> <op> <num2>", cmd_calc},
    {"limpiar", "Limpia la pantalla", "limpiar", cmd_limpiar},
    {"usuario", "Usuario actual", "usuario", cmd_usuario},
    {"directorio", "Directorio actual", "directorio", cmd_directorio},
    {"copiar", "Copia un archivo", "copiar <origen> <destino>", cmd_copiar},
    {"estadisticas", "Estadísticas de archivo", "estadisticas <archivo>", cmd_estadisticas},
};

const Command* commands_get_all(int *count) {
    *count = sizeof(g_cmds) / sizeof(g_cmds[0]);
    return g_cmds;
}

const Command* commands_find(const char *name) {
    for (unsigned i = 0; i < sizeof(g_cmds)/sizeof(g_cmds[0]); i++) {
        if (strcmp(g_cmds[i].name, name) == 0)
            return &g_cmds[i];
    }
    return NULL;
}
