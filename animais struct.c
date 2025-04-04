#include <stdio.h>

#define NUM_ANIMAIS 3

struct Animal {
    char nome[50];
    int idade;
    char sexo;
};

int main() {
    struct Animal animais[NUM_ANIMAIS];
    int somaIdades = 0;
    float mediaIdade;
    
    for (int i = 0; i < NUM_ANIMAIS; i++) {
        printf("Digite o nome do animal %d: ", i + 1);
        scanf(" %[^\n]%*c", animais[i].nome); 
        printf("Digite a idade do animal %d: ", i + 1);
        scanf("%d", &animais[i].idade);
        printf("Digite o sexo do animal %d (M/F): ", i + 1);
        scanf(" %c", &animais[i].sexo);
        
        somaIdades += animais[i].idade;
    }

    mediaIdade = somaIdades / (float)NUM_ANIMAIS;
    
    printf("\nLista de todos os animais cadastrados:\n");
    for (int i = 0; i < NUM_ANIMAIS; i++) {
        printf("Nome: %s, Idade: %d, Sexo: %c\n", animais[i].nome, animais[i].idade, animais[i].sexo);
    }

    printf("\nAnimais com idade igual ou superior à média (%.2f):\n", mediaIdade);
    for (int i = 0; i < NUM_ANIMAIS; i++) {
        if (animais[i].idade >= mediaIdade) {
            printf("Nome: %s, Idade: %d, Sexo: %c\n", animais[i].nome, animais[i].idade, animais[i].sexo);
        }
    }

    return 0;
}
