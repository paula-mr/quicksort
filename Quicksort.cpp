#include "Quicksort.h"

int calculaMediana(int *i, int *j, int *lista) {
    int inicio, meio, fim;
    inicio = lista[*i];
    meio = lista[(*i + *j)/2];
    fim = lista[*j];

    if (inicio < meio) {
        if (meio < fim)
            return meio;
        else {
            if (inicio < fim)
                return fim;
            else
                return inicio;
        }
    } else {
        if (inicio < fim)
            return inicio;
        else {
            if (meio < fim)
                return fim;
            else
                return meio;
        }
    }
}

int selecionaPivo(int tipo, int *i, int *j, int *lista) {
    switch (tipo) {
        case 1:
            return lista[(*i + *j)/2];
        case 2:
            return calculaMediana(i, j, lista);
        case 3:
            return lista[*i];
    }
}

void particao(int esquerda, int direita, int *i, int *j, int *lista, int tipo) {
    int pivo;
    *i = esquerda;
    *j = direita;

    pivo = selecionaPivo(tipo, i, j, lista);

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

void ordena(int esquerda, int direita, int *lista, int tipo) {
    int i, j;

    particao(esquerda, direita, &i, &j, lista, tipo);

    if (esquerda < j)
        ordena(esquerda, j, lista, tipo);

    if (i < direita)
        ordena(i, direita, lista, tipo);
}

void quicksort(int *lista, int tamanho, int tipo) {
    ordena(0, tamanho-1, lista, tipo);
}
