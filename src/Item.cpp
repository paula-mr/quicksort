#include "Item.h"

Item::Item() {
    this->proximo = nullptr;
    this->anterior = nullptr;
}

Item::~Item() = default;
