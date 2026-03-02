#include <stdio.h>
#include <stdlib.h>

int cmd_calc(int argc, char **argv) {
    if (argc != 4) {
        printf("Uso: calc <num1> <operador> <num2>\n");
        return 1;
    }

    double num1 = atof(argv[1]);
    double num2 = atof(argv[3]);
    char op = argv[2][0];

    switch(op) {
        case '+': printf("Resultado: %.2f\n", num1 + num2); break;
        case '-': printf("Resultado: %.2f\n", num1 - num2); break;
        case '*': printf("Resultado: %.2f\n", num1 * num2); break;
        case '/':
            if (num2 == 0)
                printf("Error: División por cero\n");
            else
                printf("Resultado: %.2f\n", num1 / num2);
            break;
        default:
            printf("Operador no válido\n");
            return 1;
    }

    return 0;
}
