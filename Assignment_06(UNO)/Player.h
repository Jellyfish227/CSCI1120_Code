#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include "Card.h"
#include "DrawPile.h"
#include "DiscardPile.h"

using std::string;
using std::vector;

const int H = 7;  // hand size

class Player
{
public:
    Player();
    string getName() const;
    void setName(string name_);
    void printHand(bool flipped = true);
    Color mostFrequentColor();
    int handSize() const;
    int handPoints() const;
    int drawCard(DrawPile* drawPile, int n = 1);
    virtual int pickCard(GameState& uno) = 0;
    virtual void playCard(int idx, GameState& uno);
    static int count;
protected:
    string name;
    vector<Card*> hand;
};

#endif // PLAYER_H