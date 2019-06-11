#ifndef ITEM_H
#define ITEM_H

class Item {
    public:
        int esquerda;
        int direita;
        Item* proximo;
        Item* anterior;
        Item();
        ~Item();
};

#endif


