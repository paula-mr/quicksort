#include "Insercao.h"

void insercao(Quicksort *quicksort, int inicio, int fim) {
    int i = inicio, j;

    for (; i <= fim; i++) {
        int aux = quicksort->lista[i];
        j = i-1;

        quicksort->numeroComparacoes++;
        while ((j >= inicio) && (aux < quicksort->lista[j])) {
            quicksort->numeroComparacoes++;
            quicksort->lista[j+1] = quicksort->lista[j];
            j--;
        }
        quicksort->lista[j+1] = aux;
        quicksort->numeroTrocas++;
        quicksort->guardarIteracoes();
    }
}
