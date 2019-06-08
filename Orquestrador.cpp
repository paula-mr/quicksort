#include "Orquestrador.h"
#include "Quicksort.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

int* gerarVetorCrescente(int tamanho);
int* gerarVetorDecrescente(int tamanho);
int* gerarVetorAleatorio(int tamanho);

void executarQuicksort(char* tipo, int* lista, int tamanho, long unsigned int *numeroComparacoes, long unsigned int *numeroTrocas) {
    switch (tipo[1]) {
        case 'C':
            quicksort(lista, tamanho, 1, numeroComparacoes, numeroTrocas);
            break;

        case 'M':
            quicksort(lista, tamanho, 2, numeroComparacoes, numeroTrocas);
            break;

        case 'P':
            quicksort(lista, tamanho, 3, numeroComparacoes, numeroTrocas);
            break;

        case 'N':
            quicksortNaoRecursivo(lista, tamanho, numeroComparacoes, numeroTrocas);
            break;

        case 'I':
            switch(tipo[2]) {
                case '1':
                    if (tipo[3] == '\0')
                        quicksortInsercao(lista, tamanho, 1, numeroComparacoes, numeroTrocas);
                    else
                        quicksortInsercao(lista, tamanho, 10, numeroComparacoes, numeroTrocas);
                    break;

                case '5':
                    quicksortInsercao(lista, tamanho, 5, numeroComparacoes, numeroTrocas);
                    break;
            }
            break;
    }
}

int* gerarVetor(char* tipo, int tamanho) {
    switch (tipo[0]) {
        case 'A':
            return gerarVetorAleatorio(tamanho);
        case 'O':
            switch (tipo[3]) {
                case 'C':
                    return gerarVetorCrescente(tamanho);
                case 'D':
                    return gerarVetorDecrescente(tamanho);
            }
    }
}

void imprimirVetor(int* lista, int tamanho) {
    for (int i=0; i<tamanho; i++) {
        std::cout << lista[i] << " ";
    }
}


int* gerarVetorCrescente(int tamanho) {
    int* vetor = (int*) malloc(tamanho * sizeof(int));

    for (int i=0; i<tamanho; i++) {
        vetor[i] = i;
    }

    return vetor;
}

int* gerarVetorDecrescente(int tamanho) {
    int* vetor = (int*) malloc(tamanho * sizeof(int));

    for (int i=tamanho, j=0; i>0; i--, j++) {
        vetor[j] = i;
    }

    return vetor;
}

int* gerarVetorAleatorio(int tamanho) {
    srand(time(0));
    int* vetor = (int*) malloc(tamanho * sizeof(int));

    for (int i=0; i<tamanho; i++) {
        vetor[i] = rand();
    }

    return vetor;
}
