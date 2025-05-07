#include <stdio.h>

int fatorial(int n) {
    if (n < 0) {
        return -1;
    }

    int i, resultado = 1;
    for (i = 2; i <= n; i++) {
        resultado *= i;
    }

    return resultado;
}

int main() {
    int numero, resultado;

    scanf("%d", &numero);
    resultado = fatorial(numero);

    if (resultado == -1) {
        printf("Erro: não é possível calcular o fatorial de número negativo.\n");
    } else {
        printf("%d\n", resultado);
    }

    return 0;
}
