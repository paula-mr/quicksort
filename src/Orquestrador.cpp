#include "Orquestrador.h"
#include "quicksort.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

int* gerarVetorCrescente(int tamanho);
int* gerarVetorDecrescente(int tamanho);
int* gerarVetorAleatorio(int tamanho);

/*
    TIPO PIVO
    1 - ELEMENTO CENTRAL
    2 - MEDIANA
    3 - PRIMEIRO ELEMENTO
*/
void executarQuicksort(Quicksort *quicksort, char* tipo) {
    //varia entre os tipos a partir do segundo caracter
    switch (tipo[1]) {
        case 'C':
            quicksort->tipoPivo = 1;
            quicksort->quicksort();
            break;

        case 'M':
            quicksort->tipoPivo = 2;
            quicksort->quicksort();
            break;

        case 'P':
            quicksort->tipoPivo = 3;
            quicksort->quicksort();
            break;

        case 'N':
            quicksort->tipoPivo = 1;
            quicksort->quicksortNaoRecursivo();
            break;

        /*caso o caracter seja I, eh preciso ainda decidir
          qual tipo de insercao sera utilizada*/
        case 'I':
            quicksort->tipoPivo = 2;
            switch(tipo[2]) {
                case '1':
                    if (tipo[3] == '\0') {
                        quicksort->porcentagemInsercao = 1;
                        quicksort->quicksortInsercao();
                    } else {
                        quicksort->porcentagemInsercao = 10;
                        quicksort->quicksortInsercao();
                    }
                    break;

                case '5':
                    quicksort->porcentagemInsercao = 5;
                    quicksort->quicksortInsercao();
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
    return 0;
}

void imprimirVetor(int* lista, int tamanho) {
    for (int i=0; i<tamanho; i++) {
        std::cout << lista[i] << " ";
    }

    std::cout << "\n";
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
