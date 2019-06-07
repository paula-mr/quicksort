#ifndef QUICKSORT_H
#define QUICKSORT_H

void quicksortNaoRecursivo(int *lista, int tamanho, unsigned long int *numeroComparacoes, unsigned long int *numeroTrocas);
void quicksort(int *lista, int tamanho, int tipoPivo, unsigned long int *numeroComparacoes, unsigned long int *numeroTrocas);
void quicksortInsercao(int *lista, int tamanho, int porcentagemInsercao, unsigned long int *numeroComparacoes, unsigned long int *numeroTrocas);

#endif
