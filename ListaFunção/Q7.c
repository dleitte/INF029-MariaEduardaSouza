#include <stdio.h>

void ler3Palavras(char palavras[3][50]) {
    for (int i = 0; i < 3; i++) {
        printf("Digite a %dª palavra: ", i + 1);
        scanf("%s", palavras[i]);
    }
}

int main() {
    char palavras[3][50];
    ler3Palavras(palavras);
    
    printf("As três palavras são: ");
    for (int i = 0; i < 3; i++) {
        printf("%s ", palavras[i]);
    }
    printf("\n");
    
    return 0;
}
