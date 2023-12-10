// Name:       Yu Ching Hei
// Student ID: 1155193237
// Email:      chyu@link.cuhk.edu.hk

#include <iostream>
#include "Player.h"

#include <algorithm>

using namespace std;

int Player::count = 0; 

Player::Player() {
    count++;
    name = "Player " + to_string(count);
}

string Player::getName() const {
    return name;
}

void Player::setName(string name_) {
    name = name_;
}

int Player::drawCard(DrawPile* drawPile, int n) {
    int d = drawPile->draw(hand, n);
    if (d == 0) {
        cout << "No more cards on draw pile!" << endl;
    }
    else {
        cout << name << " drawn " << d << " card(s)." << endl;
    }
    return d;
}

void Player::printHand(bool flipped) {
    for (Card *c : hand) 
    {
        if (flipped) 
            cout << c->toString();
        else 
            cout << "[Uno]";
        if (c != hand.back()) cout << " ";
    }
    cout << endl;
}

int Player::handSize() const {
    return int(hand.size());
}

int Player::handPoints() const {
    int sum = 0;
    for (Card *c : hand) {
        sum += (int)c->getValue();
    }
    return sum;
}

void Player::playCard(int idx, GameState& uno) {
    Card *card = hand.at(idx);
    card->play(uno);

    // Move the card from hand to discard pile
    uno.discardPile->stack(card);
    hand.erase(hand.begin() + idx);
}

Color Player::mostFrequentColor() {
    int count[5] = {0,0,0,0,0};
    for (Card *c : hand)
        count[(int)c->getColor()]++;
    int idx = max_element(count, count + 4) - count;
    
    return Color(idx);
}
