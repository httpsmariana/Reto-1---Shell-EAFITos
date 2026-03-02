#include <stdio.h>
#include <stdlib.h>

int cmd_copiar(int argc, char **argv) {
    if (argc != 3) {
        printf("Uso: copiar <origen> <destino>\n");
        return 1;
    }

    FILE *origen = fopen(argv[1], "rb");
    if (!origen) {
        perror("Error al abrir archivo origen");
        return 1;
    }

    FILE *destino = fopen(argv[2], "wb");
    if (!destino) {
        perror("Error al crear archivo destino");
        fclose(origen);
        return 1;
    }

    char buffer[1024];
    size_t bytes;

    while ((bytes = fread(buffer, 1, sizeof(buffer), origen)) > 0) {
        fwrite(buffer, 1, bytes, destino);
    }

    fclose(origen);
    fclose(destino);

    printf("Archivo copiado exitosamente.\n");
    return 0;
}
