#include "Insercao.h"

void insercao(int *lista, int inicio, int fim, unsigned long int *numeroComparacoes, unsigned long int *numeroTrocas) {
    int i = inicio, j;

    for (i; i <= fim; i++) {
        int aux = lista[i];
        j = i-1;

        (*numeroComparacoes)++;
        while ((j >= inicio) && (aux < lista[j])) {
            (*numeroComparacoes)++;
            lista[j+1] = lista[j];
            j--;
        }
        lista[j+1] = aux;
        (*numeroTrocas)++;
    }
}
