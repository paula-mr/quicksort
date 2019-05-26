#ifndef QUICKSORT_H
#define QUICKSORT_H

void particao(int esquerda, int direita, int *i, int *j, int *lista, int tipoPivo);
void ordena(int esquerda, int direita, int *lista, int tipoPivo);
void quicksort(int *lista, int tamanho, int tipoPivo);
int selecionaPivo(int tipoPivo, int *i, int *j, int *lista);
int calculaMediana(int *i, int *j, int *lista);

#endif
