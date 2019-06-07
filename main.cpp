#include <iostream>
#include "Orquestrador.h"
#include "Quicksort.h"

int main() {
    int *lista, numeroComparacoes = 0, numeroTrocas = 0, tamanho = 500000;

    lista = gerarVetor(2, tamanho);

    /*for (int i=0; i<tamanho; i++) {
        std::cout << lista[i] << " ";
    }
    std::cout << "\n ";*/

    quicksortNaoRecursivo(lista, tamanho, &numeroComparacoes, &numeroTrocas);

    /*for (int i=0; i<tamanho; i++) {
        std::cout << lista[i] << " ";
    }
    std::cout << "\n ";*/

    std::cout << "Comparacoes " << numeroComparacoes << " Trocas " << numeroTrocas << "\n";

    return 0;
}
