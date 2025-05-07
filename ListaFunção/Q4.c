#include <stdio.h>

void ler3Numeros(int numeros[3]) {
    for (int i = 0; i < 3; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &numeros[i]);
    }
}

int main() {
    int numeros[3];
    ler3Numeros(numeros);
    
    printf("Os três números são: ");
    for (int i = 0; i < 3; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
    
    return 0;
}
