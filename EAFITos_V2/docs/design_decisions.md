# Decisiones de Diseño

## Arquitectura

Se utilizó una arquitectura modular con separación por responsabilidades:

- `repl.c`: Loop principal de la shell
- `parser.c`: Tokenización de la entrada del usuario
- `commands.c`: Tabla de comandos (Command Pattern)
- `history.c`: Manejo del historial
- `cmd_*.c`: Un archivo por comando

Esto permite:
- Fácil extensión de comandos
- Bajo acoplamiento
- Mejor mantenibilidad

---

## Command Pattern

Cada comando se representa con la estructura:

typedef struct {
    const char *name;
    const char *desc;
    const char *usage;
    int (*fn)(int argc, char **argv);
} Command;

Esto permite registrar comandos en una tabla y buscarlos dinámicamente.

---

## Manejo de memoria

- Se libera memoria en `free_args`
- El historial usa un buffer circular con liberación de elementos antiguos
- No se detectaron memory leaks en pruebas manuales repetidas

---

## Manejo de señales

- Ctrl+C (SIGINT): no termina la shell, solo limpia la línea
- Ctrl+Z (SIGTSTP): se ignora la suspensión para mantener el control del REPL

---

## Seguridad

- No se utiliza `system()`
- Lectura de archivos limitada a 1MB
- Validación de argumentos en cada comando