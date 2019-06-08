#include <iostream>
#include "Orquestrador.h"

int converterStringParaInt(char *palavra);

int main(int argc, char *argv[]) {
    long unsigned int numeroComparacoes, numeroTrocas;
    int *lista, tamanho;
    char *variacao, *tipoVetor;
    bool exibirVetores;

    //recupera parametros
    variacao = argv[1];
    tipoVetor = argv[2];
    tamanho = converterStringParaInt(argv[3]);
    //exibir vetores caso o número de parâmetros seja igual a 5
    exibirVetores = (argc == 5);

    //chama funcao que gera vetor a partir do parametro passado
    lista = gerarVetor(tipoVetor, tamanho);
    //chama funcao que executa quicksort a partir do parametro passado
    executarQuicksort(variacao, lista, tamanho, &numeroComparacoes, &numeroTrocas);

    return 0;
}

//funcao que recebe uma sequencia de char e transforma em inteiro
int converterStringParaInt(char *palavra) {
    int soma = 0, i = 0;

    while (palavra[i] != '\0') {
        soma += palavra[i] - '0';
        i++;
    }

    return soma;
}
