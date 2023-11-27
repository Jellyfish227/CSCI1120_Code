#include <iostream>
#include <algorithm>
#include "DrawPile.h"

using namespace std;

DrawPile::DrawPile() : Deck(true) {
}

int DrawPile::size() const {
    return int(cards.size());
}

int DrawPile::draw(vector<Card*> &hand, int n) {
    if (size() == 0)
        return 0;

    n = min(n, size());
    for (int i = 0; i < n; i++) {
        hand.push_back(cards.at(i));
    }
    cards.erase(cards.begin(), cards.begin() + n);
    return n;
}
