#include <stdio.h>

struct Cliente {
    char nome[100];
    char dataNascimento[11];
    char cpf[15];
    char sexo;
};

struct Cliente cadastrarCliente() {
    struct Cliente cliente;
    
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]s", cliente.nome);
    printf("Digite a data de nascimento (dd/mm/aaaa): ");
    scanf("%s", cliente.dataNascimento);
    printf("Digite o CPF (XXX.XXX.XXX-XX): ");
    scanf("%s", cliente.cpf);
    printf("Digite o sexo (M/F): ");
    scanf(" %c", &cliente.sexo);
    
    return cliente;
}

int main() {
    struct Cliente cliente = cadastrarCliente();
    
    printf("\nDados do cliente:\n");
    printf("Nome: %s\n", cliente.nome);
    printf("Data de Nascimento: %s\n", cliente.dataNascimento);
    printf("CPF: %s\n", cliente.cpf);
    printf("Sexo: %c\n", cliente.sexo);
    
    return 0;
}
