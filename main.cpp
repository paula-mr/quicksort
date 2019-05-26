#include <iostream>
#include "Quicksort.h"

int main() {
    int tamanho;
    int lista[100];

    std::cin >> tamanho;

    for (int i=0; i<tamanho; i++) {
        std::cin >> lista[i];
    }

    quicksort(lista, tamanho, 1, 2);

    for (int i=0; i<tamanho; i++) {
        std::cout << lista[i] << " ";
    }

    return 0;
}
