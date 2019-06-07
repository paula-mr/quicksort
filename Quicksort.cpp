#include "Quicksort.h"
#include "Insercao.h"
#include <iostream>
#include "Pilha.h"

using namespace::std;

int calculaMediana(int *i, int *j, int *lista);
int selecionaPivo(int tipoPivo, int *i, int *j, int *lista);
void ordena(int esquerda, int direita, int *lista, int tipoPivo);
void particao(int esquerda, int direita, int *i, int *j, int *lista, int tipoPivo);
void ordenaInsercao(int esquerda, int direita, int *lista, int quantidadeElementosInsercao);
void imprimirLista(int *lista, int tamanho);

void imprimirLista(int *lista, int tamanho) {
    std::cout << "\n";
    for (int i=0; i<tamanho; i++) {
        std::cout << lista[i] << " ";
    }

}

int calculaMediana(int *i, int *j, int *lista, int *numeroComparacoes) {
    int inicio, meio, fim;
    inicio = lista[*i];
    meio = lista[(*i + *j)/2];
    fim = lista[*j];

    (*numeroComparacoes)++;
    if (inicio < meio) {
        (*numeroComparacoes)++;
        if (meio < fim)
            return meio;
        else {
            (*numeroComparacoes)++;
            if (inicio < fim)
                return fim;
            else
                return inicio;
        }
    } else {
        (*numeroComparacoes)++;
        if (inicio < fim)
            return inicio;
        else {
            (*numeroComparacoes)++;
            if (meio < fim)
                return fim;
            else
                return meio;
        }
    }
}

int selecionaPivo(int tipoPivo, int *i, int *j, int *lista, int *numeroComparacoes) {
    switch (tipoPivo) {
        case 1:
            return lista[(*i + *j)/2];
        case 2:
            return calculaMediana(i, j, lista, numeroComparacoes);
        case 3:
            return lista[*i];
    }
    return 0;
}

void particao(int esquerda, int direita, int *i, int *j, int *lista, int tipoPivo, int *numeroComparacoes, int *numeroTrocas) {
    int pivo;
    *i = esquerda;
    *j = direita;

    pivo = selecionaPivo(tipoPivo, i, j, lista, numeroComparacoes);

    do {

        (*numeroComparacoes)++;
        while (pivo > lista[*i]) {
            (*i)++;
            (*numeroComparacoes)++;
        }

        (*numeroComparacoes)++;
        while (pivo < lista[*j]) {
            (*j)--;
            (*numeroComparacoes)++;
        }

        if (*i <= *j) {
            int auxiliar = lista[*i];
            lista[*i] = lista[*j];
            lista[*j] = auxiliar;
            (*i)++;
            (*j)--;
            (*numeroTrocas)++;
        }

    } while (*i <= *j);
}

void ordena(int esquerda, int direita, int *lista, int tipoPivo, int *numeroComparacoes, int *numeroTrocas) {
    int i, j;

    particao(esquerda, direita, &i, &j, lista, tipoPivo, numeroComparacoes, numeroTrocas);

    if (esquerda < j)
        ordena(esquerda, j, lista, tipoPivo, numeroComparacoes, numeroTrocas);

    if (i < direita)
        ordena(i, direita, lista, tipoPivo, numeroComparacoes, numeroTrocas);
}

void ordenaInsercao(int esquerda, int direita, int *lista, int quantidadeElementosInsercao, int *numeroComparacoes, int *numeroTrocas) {
    int i, j;

    particao(esquerda, direita, &i, &j, lista, 2, numeroComparacoes, numeroTrocas);

    if (esquerda < j) {
        if (j-esquerda > quantidadeElementosInsercao) {
            ordenaInsercao(esquerda, j, lista, quantidadeElementosInsercao, numeroComparacoes, numeroTrocas);
        }
        else {
            insercao(lista, esquerda, j, numeroComparacoes, numeroTrocas);
        }
    }

    if (i < direita) {
        if (direita-j > quantidadeElementosInsercao) {
            ordenaInsercao(i, direita, lista, quantidadeElementosInsercao, numeroComparacoes, numeroTrocas);
        }
        else {
            insercao(lista, i, direita, numeroComparacoes, numeroTrocas);
        }
    }

}

void quicksortInsercao(int *lista, int tamanho, int porcentagemInsercao, int *numeroComparacoes, int *numeroTrocas) {
    int quantidadeElementosInsercao = (porcentagemInsercao*tamanho)/100;

    ordenaInsercao(0, tamanho-1, lista, quantidadeElementosInsercao, numeroComparacoes, numeroTrocas);
}

void quicksort(int *lista, int tamanho, int tipoPivo, int *numeroComparacoes, int *numeroTrocas) {
    ordena(0, tamanho-1, lista, tipoPivo, numeroComparacoes, numeroTrocas);
}

void quicksortNaoRecursivo(int *lista, int tamanho, int *numeroComparacoes, int *numeroTrocas) {
    Pilha* pilha = new Pilha();
    Item* item = new Item();
    int esquerda = 0, direita = tamanho-1, i, j;

    int tipoPivo = 1;

    item->esquerda = esquerda;
    item->direita = direita;
    pilha->empilha(item);

    do {
        if (direita > esquerda) {
            particao(esquerda, direita, &i, &j, lista, tipoPivo, numeroComparacoes, numeroTrocas);

            if ((j-esquerda)>(direita-1)) {
                item = new Item();
                item->direita = j;
                item->esquerda = esquerda;
                pilha->empilha(item);
                esquerda = i;
            } else {
                item = new Item();
                item->direita = direita;
                item->esquerda = i;
                pilha->empilha(item);
                direita = j;
            }

        } else {
            item = pilha->desempilha();
            direita = item->direita;
            esquerda = item->esquerda;
        }
    } while (!pilha->estaVazia());
}
