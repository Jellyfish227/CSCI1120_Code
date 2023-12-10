// Name:       Yu Ching Hei
// Student ID: 1155193237
// Email:      chyu@link.cuhk.edu.hk

#include <iostream>
#include "DiscardPile.h"

using namespace std;

DiscardPile::DiscardPile() : Deck(false) {
}

Card* DiscardPile::top() const {
    if (cards.size() > 0)
        return cards.back();
    else
        return nullptr;
}

void DiscardPile::stack(Card* card) {
    cards.push_back(card);
}
