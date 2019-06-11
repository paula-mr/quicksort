#include "Quicksort.h"
#include "Insercao.h"
#include <iostream>
#include "Pilha.h"

using namespace::std;

void Quicksort::quicksort() {
    ordena(0, tamanho-1);
}

void Quicksort::quicksortInsercao() {
    int quantidadeElementosInsercao = (porcentagemInsercao*tamanho)/100;

    ordenaInsercao(0, tamanho-1, quantidadeElementosInsercao);
}

void Quicksort::quicksortNaoRecursivo() {
    Pilha* pilha = new Pilha();
    Item* item = new Item();
    int esquerda = 0, direita = tamanho-1, i, j;

    item->esquerda = esquerda;
    item->direita = direita;
    pilha->empilha(item);

    do {
        if (direita > esquerda) {
            particao(esquerda, direita, &i, &j);

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

void Quicksort::ordena(int esquerda, int direita) {
    int i, j;

    particao(esquerda, direita, &i, &j);

    if (esquerda < j)
        ordena(esquerda, j);

    if (i < direita)
        ordena(i, direita);
}

void Quicksort::ordenaInsercao(int esquerda, int direita, int quantidadeElementosInsercao) {
    int i, j;

    particao(esquerda, direita, &i, &j);

    if (esquerda < j) {
        if (j-esquerda > quantidadeElementosInsercao) {
            ordenaInsercao(esquerda, j, quantidadeElementosInsercao);
        }
        else {
            insercao(this, esquerda, j);
        }
    }

    if (i < direita) {
        if (direita-j > quantidadeElementosInsercao) {
            ordenaInsercao(i, direita, quantidadeElementosInsercao);
        }
        else {
            insercao(this, i, direita);
        }
    }

}

void Quicksort::particao(int esquerda, int direita, int *i, int *j) {
    int pivo;
    *i = esquerda;
    *j = direita;

    pivo = selecionaPivo(i, j);

    do {

        numeroComparacoes++;
        while (pivo > lista[*i]) {
            (*i)++;
            numeroComparacoes++;
        }

        numeroComparacoes++;
        while (pivo < lista[*j]) {
            (*j)--;
            numeroComparacoes++;
        }

        if (*i <= *j) {
            int auxiliar = lista[*i];
            lista[*i] = lista[*j];
            lista[*j] = auxiliar;
            (*i)++;
            (*j)--;
            numeroTrocas++;
        }

        if (exibirVetores)
            guardarIteracoes();

    } while (*i <= *j);

    if (exibirVetores)
        guardarIteracoes();
}

int Quicksort::calculaMediana(int *i, int *j) {
    int inicio, meio, fim;
    inicio = lista[*i];
    meio = lista[(*i + *j)/2];
    fim = lista[*j];

    numeroComparacoes++;
    if (inicio < meio) {
        numeroComparacoes++;
        if (meio < fim)
            return meio;
        else {
            numeroComparacoes++;
            if (inicio < fim)
                return fim;
            else
                return inicio;
        }
    } else {
        numeroComparacoes++;
        if (inicio < fim)
            return inicio;
        else {
            numeroComparacoes++;
            if (meio < fim)
                return fim;
            else
                return meio;
        }
    }
}

int Quicksort::selecionaPivo(int *i, int *j) {
    switch (tipoPivo) {
        case 1:
            return lista[(*i + *j)/2];
        case 2:
            return calculaMediana(i, j);
        case 3:
            return lista[*i];
    }
    return 0;
}

void Quicksort::guardarIteracoes() {
    if (exibirVetores) {
        int **auxiliar = (int **)malloc((numeroTrocas+1) * sizeof(int*));
        std::copy(iteracoes, iteracoes+numeroTrocas, auxiliar);
        auxiliar[numeroTrocas] = (int*)malloc(tamanho * sizeof(int*));
        for (int i=0; i < tamanho; i++) {
            auxiliar[numeroTrocas][i] = lista[i];
        }

        free(iteracoes);
        iteracoes = auxiliar;
    }
}
