// Name:       Yu Ching Hei
// Student ID: 1155193237
// Email:      chyu@link.cuhk.edu.hk

#include <iostream>
#include "Card.h"

using namespace std;

Card::Card(Color c, Value v) : color(c), value(v) {
}

Color Card::getColor() const {
    return color;
}

Value Card::getValue() const {
    return value;
}

void Card::setColor(Color c) {
    color = c;
}

void Card::setValue(Value v) {
    value = v;
}

bool Card::match(Card* top) {
    return color == top->getColor() || value == top->getValue();
}

void Card::play(GameState& /* uno */) {
    cout << "Discarded " << this->toString() << endl;
}

string Card::toString() {
    return string() + "[" + COLORS[int(color)][0] + to_string(int(value)) + "]";
}