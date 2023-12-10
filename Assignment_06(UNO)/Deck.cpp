// Name:       Yu Ching Hei
// Student ID: 1155193237
// Email:      chyu@link.cuhk.edu.hk

#include <iostream>
#include <algorithm>
#include <iomanip>
#include "Deck.h"

using namespace std;

Deck::Deck(bool fill) {
    if (fill) {
        for (int c = int(Color::Red); c <= int(Color::Blue); c++) {
            // Create number cards
            for (int v = int(Value::N0); v <= int(Value::N9); v++) {
                cards.push_back(new Card(Color(c), Value(v)));
            }
            // Create action cards
            for (int i = 0; i < 2; i++) {
                cards.push_back(new Reverse(Color(c)));
                cards.push_back(new Skip(Color(c)));
                cards.push_back(new Draw2(Color(c)));
            }
        }
        // Create wild cards
        for (int i = 0; i < 4; i++) {
            cards.push_back(new WildCard());
            cards.push_back(new WildDraw4());
        }
    }
}

void Deck::shuffle() {
    random_shuffle(cards.begin(), cards.end());
}

void Deck::print() {
    int counter = 0;
    for (Card *c : cards) 
    {   
        string str = c->toString() + "=" + to_string((int)c->getValue());
        cout << setw(8) << left << str;
        counter++;
        if (counter == 10 || c == cards.back())
        {
            cout << endl;
            counter = 0;
        }
    }
}
