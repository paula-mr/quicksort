#ifndef QUICKSORT_H
#define QUICKSORT_H

void quicksortNaoRecursivo(int *lista, int tamanho, int *numeroComparacoes, int *numeroTrocas);
void quicksort(int *lista, int tamanho, int tipoPivo, int *numeroComparacoes, int *numeroTrocas);
void quicksortInsercao(int *lista, int tamanho, int porcentagemInsercao, int *numeroComparacoes, int *numeroTrocas);

#endif
