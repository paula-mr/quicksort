#include <iostream>
#include <chrono>
#include <string>
#include "Orquestrador.h"
#include "Quicksort.h"

int converterStringParaInt(char *palavra);

int main(int argc, char *argv[]) {
    using namespace std::chrono;

    //declara variaveis
    Quicksort quicksort;
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

    //preenche objeto quicksort
    quicksort.exibirVetores = exibirVetores;
    quicksort.lista = lista;
    quicksort.tamanho = tamanho;
    quicksort.iteracoes = (int **)malloc(sizeof(int*));
    if (exibirVetores) {
        quicksort.iteracoes[0] = (int *)malloc(tamanho * sizeof(int));
        for (int i=0; i < tamanho; i++) {
            quicksort.iteracoes[0][i] = lista[i];
        }
    }

    //calcula tempo demorado para rodar o algoritmo
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    //chama funcao que executa quicksort a partir do parametro passado
    executarQuicksort(&quicksort, variacao);
    high_resolution_clock::time_point t2 = high_resolution_clock::now();

    //obtem a diferenca dos tempos em ms
    duration<double, std::micro> elapsed_time = duration_cast<duration<double>>(t2 - t1);

    //imprime saida padrao
    std::cout << variacao << " " << tipoVetor << " " << tamanho << " "
        << quicksort.numeroComparacoes << " " << quicksort.numeroTrocas << " " << elapsed_time.count() << "\n";

    //imprime iteracoes do vetor
    if (exibirVetores) {
        for (int i = 0; i < quicksort.numeroTrocas; i++) {
            imprimirVetor(quicksort.iteracoes[i], quicksort.tamanho);
        }
    }

    return 0;
}

//funcao que recebe uma sequencia de char e transforma em inteiro
int converterStringParaInt(char *palavra) {
    int soma = 0, i = 0;

    while (palavra[i] != '\0') {
        soma *= 10;
        soma += palavra[i] - '0';
        i++;
    }

    return soma;
}
