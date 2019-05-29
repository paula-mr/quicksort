#include "Insercao.h"

void insercao(int *lista, int inicio, int fim) {
    int i = inicio, j;

    for (i; i <= fim; i++) {
        int aux = lista[i];
        j = i-1;
        while ((j >= inicio) && (aux < lista[j])) {
            lista[j+1] = lista[j];
            j--;
        }
        lista[j+1] = aux;
    }
}
