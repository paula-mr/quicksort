#include "Quicksort.h"
#include <iostream>

using namespace::std;

int calculaMediana(int *i, int *j, int *lista);
void ordenaCrescente(int *i, int *j, int *lista, int pivo);
void ordenaDecrescente(int *i, int *j, int *lista, int pivo);
int selecionaPivo(int tipoPivo, int *i, int *j, int *lista);
void ordena(int esquerda, int direita, int *lista, int tipoOrdenacao, int tipoPivo);
void particao(int esquerda, int direita, int *i, int *j, int *lista, int tipoOrdenacao, int tipoPivo);

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

int selecionaPivo(int tipoPivo, int *i, int *j, int *lista) {
    switch (tipoPivo) {
        case 1:
            return lista[(*i + *j)/2];
        case 2:
            return calculaMediana(i, j, lista);
        case 3:
            return lista[*i];
    }
    return 0;
}

void ordenaCrescente(int *i, int *j, int *lista, int pivo) {
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

void ordenaDecrescente(int *i, int *j, int *lista, int pivo) {
    do {
        while (pivo < lista[*i])
            (*i)++;

        while (pivo > lista[*j])
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

void particao(int esquerda, int direita, int *i, int *j, int *lista, int tipoOrdenacao, int tipoPivo) {
    int pivo;
    *i = esquerda;
    *j = direita;

    pivo = selecionaPivo(tipoPivo, i, j, lista);

    if (tipoOrdenacao < 0)
        ordenaDecrescente(i, j, lista, pivo);
    else
        ordenaCrescente(i, j, lista, pivo);
}



void ordena(int esquerda, int direita, int *lista, int tipoOrdenacao, int tipoPivo) {
    int i, j;

    particao(esquerda, direita, &i, &j, lista, tipoOrdenacao, tipoPivo);

    if (esquerda < j)
        ordena(esquerda, j, lista, tipoOrdenacao, tipoPivo);

    if (i < direita)
        ordena(i, direita, lista, tipoOrdenacao, tipoPivo);
}

void quicksort(int *lista, int tamanho, int tipoOrdenacao, int tipoPivo) {
    ordena(0, tamanho-1, lista, tipoOrdenacao, tipoPivo);
}
