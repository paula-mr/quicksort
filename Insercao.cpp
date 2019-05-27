#include "Insercao.h"

void insereCrescente(int *lista, int inicio, int fim);
void insereDecrescente(int *lista, int inicio, int fim);

void insereCrescente(int *lista, int inicio, int fim) {
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

void insereDecrescente(int *lista, int inicio, int fim) {
    int i = fim, j;

    for (i; i >= inicio; i--) {
        int aux = lista[i];
        j = i+1;
        while ((j < fim) && (aux < lista[j])) {
            lista[j-1] = lista[j];
            j++;
        }
        lista[j-1] = aux;
    }
}

void insercao(int *lista, int inicio, int fim, int tipoOrdenacao) {
    if (tipoOrdenacao < 0)
        insereDecrescente(lista, inicio, fim);
    else
        insereCrescente(lista, inicio, fim);
}
