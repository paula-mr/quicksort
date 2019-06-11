#ifndef PILHA_H
#define PILHA_H

#include "Item.h"

class Pilha {
    public:
        Item* head;
        Pilha();
        ~Pilha();
        void empilha(Item* item);
        Item* desempilha();
        bool estaVazia();
};

#endif


