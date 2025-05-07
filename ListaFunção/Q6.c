#include <stdio.h>

void ler3Letras(char letras[3]) {
    for (int i = 0; i < 3; i++) {
        printf("Digite a %dª letra: ", i + 1);
        scanf(" %c", &letras[i]);
    }
}

int main() {
    char letras[3];
    ler3Letras(letras);
    
    printf("As três letras são: ");
    for (int i = 0; i < 3; i++) {
        printf("%c ", letras[i]);
    }
    printf("\n");
    
    return 0;
}
