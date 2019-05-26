#ifndef QUICKSORT_H
#define QUICKSORT_H

void particao(int esquerda, int direita, int *i, int *j, int *lista, int tipo);
void ordena(int esquerda, int direita, int *lista, int tipo);
void quicksort(int *lista, int tamanho, int tipo);
int selecionaPivo(int tipo, int *i, int *j, int *lista);
int calculaMediana(int *i, int *j, int *lista);

#endif
