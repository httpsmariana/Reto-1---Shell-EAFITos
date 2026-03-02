#include "history.h"
int cmd_history(int argc, char **argv) {
    (void)argc; (void)argv;
    history_print();
    return 0;
}
