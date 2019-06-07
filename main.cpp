#include <iostream>
#include "Orquestrador.h"
#include "Quicksort.h"

int main() {
    unsigned long int numeroComparacoes = 0, numeroTrocas = 0;
    int *lista, tamanho = 500000;

    lista = gerarVetor(3, tamanho);

    quicksortNaoRecursivo(lista, tamanho, &numeroComparacoes, &numeroTrocas);

    std::cout << "Comparacoes " << numeroComparacoes << " Trocas " << numeroTrocas << "\n";

    return 0;
}
