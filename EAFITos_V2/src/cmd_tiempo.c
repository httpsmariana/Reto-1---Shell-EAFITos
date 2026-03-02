#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <time.h>

int cmd_tiempo(int argc, char **argv) {
    (void)argc; (void)argv;

    time_t t = time(NULL);
    if (t == (time_t)-1) {
        perror("tiempo");
        return 1;
    }

    struct tm tmv;
    if (!localtime_r(&t, &tmv)) {
        perror("tiempo");
        return 1;
    }

    char buf[64];
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &tmv);
    printf("%s\n", buf);
    return 0;
}
