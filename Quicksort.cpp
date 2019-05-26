#include "Quicksort.h"

void particao(int esquerda, int direita, int *i, int *j, int *lista) {
    int pivo;
    *i = esquerda;
    *j = direita;

    pivo = lista[(*i + *j)/2];

    do {
        while (pivo > lista[*i])
            (*i)++;

        while (pivo < lista[*j])
            (*j)--;

        if (*i <= *j) {
            int auxiliar = lista[*i];
            lista[*i] = lista[*j];
            lista[*j] = auxiliar;
            (*i)++;
            (*j)--;
        }
    } while (*i <= *j);
}

void ordena(int esquerda, int direita, int *lista) {
    int i, j;

    particao(esquerda, direita, &i, &j, lista);

    if (esquerda < j)
        ordena(esquerda, j, lista);

    if (i < direita)
        ordena(i, direita, lista);
}

void quicksort(int *lista, int tamanho) {
    ordena(0, tamanho-1, lista);
}
