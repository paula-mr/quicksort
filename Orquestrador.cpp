#include "Orquestrador.h"
#include <iostream>
#include <stdlib.h>

int* gerarVetorCrescente(int tamanho);
int* gerarVetorDecrescente(int tamanho);
int* gerarVetorAleatorio(int tamanho);

int* gerarVetor(int tipo, int tamanho) {
    switch (tipo) {
        case 1:
            return gerarVetorCrescente(tamanho);
        case 2:
            return gerarVetorDecrescente(tamanho);
        default:
            return gerarVetorAleatorio(tamanho);
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
    int* vetor = (int*) malloc(tamanho * sizeof(int));

    for (int i=0; i<tamanho; i++) {
        vetor[i] = rand();
    }

    return vetor;
}
