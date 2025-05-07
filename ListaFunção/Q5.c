#include <stdio.h>

struct Numeros {
    int n1, n2, n3, n4;
};

struct Numeros ler4Numeros() {
    struct Numeros numeros;
    printf("Digite o 1º número: ");
    scanf("%d", &numeros.n1);
    printf("Digite o 2º número: ");
    scanf("%d", &numeros.n2);
    printf("Digite o 3º número: ");
    scanf("%d", &numeros.n3);
    printf("Digite o 4º número: ");
    scanf("%d", &numeros.n4);
    
    return numeros;
}

int main() {
    struct Numeros numeros = ler4Numeros();
    
    printf("Os quatro números são: %d %d %d %d\n", numeros.n1, numeros.n2, numeros.n3, numeros.n4);
    
    return 0;
}
