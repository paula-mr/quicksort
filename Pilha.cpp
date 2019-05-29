#include "Pilha.h"

Pilha::Pilha() {
    this->head = nullptr;
}

Pilha::~Pilha() = default;

void Pilha::empilha(Item* item) {
    this->head->proximo = item;
    item->anterior = this->head;
    this->head = item;
}

Item* Pilha::desempilha() {
    Item* item = this->head;
    this->head = item->anterior;

    item->anterior = nullptr;
    this->head->proximo = nullptr;

    return item;
}

bool Pilha::estaVazia() {
    return head == nullptr;
}
