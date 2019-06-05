#include <iostream>
#include "Orquestrador.h"

int main() {
    int* lista;

    lista = gerarVetor(3, 100);

    for (int i=0; i<100; i++) {
        std::cout << lista[i] << " ";
    }

    return 0;
}
