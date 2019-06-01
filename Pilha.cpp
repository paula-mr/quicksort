#include "Pilha.h"

Pilha::Pilha() {
    this->head = nullptr;
}

Pilha::~Pilha() = default;

void Pilha::empilha(Item* item) {
    if (this->head != nullptr)
        this->head->proximo = item;

    item->anterior = this->head;
    this->head = item;
}

Item* Pilha::desempilha() {
    Item* item = this->head;

    if (head->anterior == nullptr) {
        head = nullptr;
    } else {
        this->head = item->anterior;
        this->head->proximo = nullptr;
    }

    item->anterior = nullptr;
    return item;
}

bool Pilha::estaVazia() {
    return head == nullptr;
}
