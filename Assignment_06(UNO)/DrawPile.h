// Name:       Yu Ching Hei
// Student ID: 1155193237
// Email:      chyu@link.cuhk.edu.hk

#ifndef DRAWPILE_H
#define DRAWPILE_H

#include "Deck.h"

class DrawPile : public Deck
{
public:
    DrawPile();
    int size() const;
    int draw(vector<Card*> &hand, int n = 1);
};

#endif // DRAWPILE_H