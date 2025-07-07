#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#define TAM 10

enum { TODAS_ESTRUTURAS_AUXILIARES_VAZIAS = -11, NOVO_TAMANHO_INVALIDO, NUMERO_INEXISTENTE,
       ESTRUTURA_AUXILIAR_VAZIA, TAMANHO_INVALIDO, SEM_ESPACO_DE_MEMORIA, POSICAO_INVALIDA,
       JA_TEM_ESTRUTURA_AUXILIAR, SEM_ESTRUTURA_AUXILIAR, SEM_ESPACO, SUCESSO };

typedef struct {
    int *elementos;
    int quantidade_ocupada;
    int tamanho_alocado;
} EstruturaAuxiliar;

EstruturaAuxiliar *vetorPrincipal[TAM]; 

int criarEstruturaAuxiliar(int posicao, int tamanho) {
    if (posicao < 1 || posicao > TAM) {
        return POSICAO_INVALIDA;
    }

    int indice = posicao - 1;

    if (vetorPrincipal[indice] != NULL) {
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }

    if (tamanho < 1) {
        return TAMANHO_INVALIDO;
    }

    EstruturaAuxiliar *novaEstrutura = (EstruturaAuxiliar *) malloc(sizeof(EstruturaAuxiliar));
    if (novaEstrutura == NULL) {
        return SEM_ESPACO_DE_MEMORIA; 
    }
    
    novaEstrutura->elementos = (int *) malloc(tamanho * sizeof(int));
    if (novaEstrutura->elementos == NULL) {
        free(novaEstrutura);
        return SEM_ESPACO_DE_MEMORIA;
    }
    
    novaEstrutura->quantidade_ocupada = 0;
    novaEstrutura->tamanho_alocado = tamanho; 

    vetorPrincipal[indice] = novaEstrutura;

    return SUCESSO; 
}

int inserirNumeroEmEstrutura(int posicao, int valor) {
    if (posicao < 1 || posicao > TAM) {
        return POSICAO_INVALIDA;
    }
    
    int indice = posicao - 1;

    if (vetorPrincipal[indice] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }
    
    EstruturaAuxiliar *aux = vetorPrincipal[indice];

    if (aux->quantidade_ocupada < aux->tamanho_alocado) {
        aux->elementos[aux->quantidade_ocupada] = valor;
        aux->quantidade_ocupada++;
        return SUCESSO;
    } else {
        return SEM_ESPACO;
    }
}

int excluirNumeroDoFinaldaEstrutura(int posicao) {
    if (posicao < 1 || posicao > TAM) {
        return POSICAO_INVALIDA;
    }

    int indice = posicao - 1; 

    if (vetorPrincipal[indice] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    EstruturaAuxiliar *aux = vetorPrincipal[indice];

    if (aux->quantidade_ocupada == 0) {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    aux->quantidade_ocupada--,
        
    return SUCESSO;
}

int excluirNumeroEspecificoDeEstrutura(int posicao, int valor) {
    if (posicao < 1 || posicao > TAM) {
        return POSICAO_INVALIDA;
    }

    int indice = posicao - 1; 

    if (vetorPrincipal[indice] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    EstruturaAuxiliar *aux = vetorPrincipal[indice];

    if (aux->quantidade_ocupada == 0) {
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    int i;
    int encontrado = 0;
    for (i = 0; i < aux->quantidade_ocupada; i++) {
        if (aux->elementos[i] == valor) {
            encontrado = 1;
            break; 
        }
    }

    if (!encontrado) {
        return NUMERO_INEXISTENTE; 
    }

    for (int j = i; j < aux->quantidade_ocupada - 1; j++) {
        aux->elementos[j] = aux->elementos[j+1];
    }

    aux->quantidade_ocupada--;

    return SUCESSO;
}

int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}

int getDadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA) {
        return POSICAO_INVALIDA;
    }

    int indice = posicao - 1; 

    if (vetorPrincipal[indice] == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    EstruturaAuxiliar *aux = vetorPrincipal[indice];
    for (int i = 0; i < aux->quantidade_ocupada; i++) {
        vetorAux[i] = aux->elementos[i];
    }

    return SUCESSO;
}

int comparar(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[]) {
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA)
        return POSICAO_INVALIDA;

    int indice = posicao - 1;
    if (vetorPrincipal[indice] == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    EstruturaAuxiliar *aux = vetorPrincipal[indice];
    if (aux->quantidade_ocupada == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    memcpy(vetorAux, aux->elementos, aux->quantidade_ocupada * sizeof(int));
    qsort(vetorAux, aux->quantidade_ocupada, sizeof(int), comparar);

    return SUCESSO;
}

int getDadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
    int k = 0;
    int algumaNaoVazia = 0;

    for (int i = 0; i < TAM; i++) {
        EstruturaAuxiliar *aux = vetorPrincipal[i];
        if (aux != NULL && aux->quantidade_ocupada > 0) {
            algumaNaoVazia = 1;
            for (int j = 0; j < aux->quantidade_ocupada; j++) {
                vetorAux[k++] = aux->elementos[j];
            }
        }
    }

    return algumaNaoVazia ? SUCESSO : TODAS_ESTRUTURAS_AUXILIARES_VAZIAS;
}

int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[]) {
    int resultado = getDadosDeTodasEstruturasAuxiliares(vetorAux);

    if (resultado == SUCESSO) {
        int total = 0;
        for (int i = 0; i < TAM; i++) {
            if (vetorPrincipal[i] != NULL) {
                total += vetorPrincipal[i]->quantidade_ocupada;
            }
        }
        qsort(vetorAux, total, sizeof(int), comparar);
    }

    return resultado;
}

int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho) {
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA)
        return POSICAO_INVALIDA;

    int indice = posicao - 1;
    EstruturaAuxiliar *aux = vetorPrincipal[indice];

    if (aux == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    int novoTam = aux->tamanho_alocado + novoTamanho;

    if (novoTam < 1)
        return NOVO_TAMANHO_INVALIDO;

    int *novoArray = realloc(aux->elementos, novoTam * sizeof(int));
    if (novoArray == NULL)
        return SEM_ESPACO_DE_MEMORIA;

    aux->elementos = novoArray;
    aux->tamanho_alocado = novoTam;

    if (aux->quantidade_ocupada > novoTam)
        aux->quantidade_ocupada = novoTam;

    return SUCESSO;
}


int getQuantidadeElementosEstruturaAuxiliar(int posicao) {
    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA)
        return POSICAO_INVALIDA;

    int indice = posicao - 1;
    EstruturaAuxiliar *aux = vetorPrincipal[indice];

    if (aux == NULL)
        return SEM_ESTRUTURA_AUXILIAR;

    if (aux->quantidade_ocupada == 0)
        return ESTRUTURA_AUXILIAR_VAZIA;

    return aux->quantidade_ocupada;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
}
