#include "Insercao.h"
#include <iostream>

void insercao(Quicksort *quicksort, int inicio, int fim) {
    int i = inicio, j;

    for (; i <= fim; i++) {
        int aux = quicksort->lista[i];
        j = i-1;

        quicksort->numeroComparacoes = quicksort->numeroComparacoes+1;
        while ((j >= inicio) && (aux < quicksort->lista[j])) {
            quicksort->lista[j+1] = quicksort->lista[j];
            quicksort->numeroTrocas = quicksort->numeroTrocas+1;
            quicksort->guardarIteracoes();
            j--;
        }

        quicksort->lista[j+1] = aux;
        quicksort->numeroTrocas = quicksort->numeroTrocas+1;

        quicksort->guardarIteracoes();
    }
}
