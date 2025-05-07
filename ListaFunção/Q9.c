#include <stdio.h>
#include <string.h>
#include <ctype.h>

int validarNome(char nome[]) {
    if (strlen(nome) > 20) {
        printf("Erro: O nome deve ter no máximo 20 caracteres.\n");
        return 0;  
    }
    return 1;  
}

int validarSexo(char sexo) {
    if (sexo == 'm' || sexo == 'M') {
        return 1;  
    }
    if (sexo == 'f' || sexo == 'F') {
        return 1;  
    }
    printf("Erro: Sexo inválido. Digite 'm' para masculino ou 'f' para feminino\n");
    return 0; 
}

int validarCPF(char cpf[]) {
    if (strlen(cpf) != 11) {
        printf("Erro: O CPF deve ter 11 caracteres.\n");
        return 0;  
    }
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            printf("Erro: O CPF deve conter apenas números.\n");
            return 0;  
        }
    }
    return 1; 
}

int validarNascimento(char dataNascimento[]) {
    if (strlen(dataNascimento) != 10) {
        printf("Erro: A data deve ter o formato dd/mm/aaaa.\n");
        return 0;  
    }

    if (dataNascimento[2] != '/' || dataNascimento[5] != '/') {
        printf("Erro: A data deve ter o formato dd/mm/aaaa.\n");
        return 0;  
    }

    for (int i = 0; i < 10; i++) {
        if (i != 2 && i != 5 && !isdigit(dataNascimento[i])) {
            printf("Erro: A data deve conter apenas números e '/' como separadores.\n");
            return 0;
        }
    }

    int dia, mes, ano;
    sscanf(dataNascimento, "%d/%d/%d", &dia, &mes, &ano);

    if (mes < 1 || mes > 12) {
        printf("Erro: Mês inválido. Deve ser entre 01 e 12.\n");
        return 0; 
    }

    if (dia < 1 || dia > 31) {
        printf("Erro: Dia inválido. Deve ser entre 01 e 31.\n");
        return 0; 
    }

    if (mes == 2 && dia > 29) {
        printf("Erro: Fevereiro não pode ter mais que 29 dias.\n");
        return 0;
    }

    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
        printf("Erro: Esse mês tem no máximo 30 dias.\n");
        return 0; 
    }

    return 1; 
}

int cadastrarCliente() {
    char nome[100], sexo, cpf[15], dataNascimento[11];
    
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]s", nome); 
    if (!validarNome(nome)) return 0;
    
    printf("Digite o sexo (m para masculino ou f para feminino): ");
    scanf(" %c", &sexo); 
    if (!validarSexo(sexo)) return 0; 
    
    printf("Digite o CPF (apenas números): ");
    scanf("%s", cpf);
    if (!validarCPF(cpf)) return 0;
    
    printf("Digite a data de nascimento (dd/mm/aaaa): ");
    scanf("%s", dataNascimento);
    if (!validarNascimento(dataNascimento)) return 0;
    
    printf("\nCadastro realizado com sucesso!\n");
    printf("Nome: %s\n", nome);
    printf("Sexo: %c\n", sexo);
    printf("CPF: %s\n", cpf);
    printf("Data de Nascimento: %s\n", dataNascimento);
    
    return 1;
}

int main() {
    int sucesso = cadastrarCliente();
    if (!sucesso) {
        printf("Cadastro falhou devido a um erro nas informações fornecidas.\n");
    }
    return 0;
}
