#include <iostream>
#include "Quicksort.h"
#include "Insercao.h"

int main() {
    int tamanho;
    int lista[100];

    std::cin >> tamanho;

    for (int i=0; i<tamanho; i++) {
        std::cin >> lista[i];
    }

    quicksortInsercao(lista, tamanho, 40, 1);

    for (int i=0; i<tamanho; i++) {
        std::cout << lista[i] << " ";
    }

    return 0;
}
