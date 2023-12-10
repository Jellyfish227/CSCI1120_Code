// Name:       Yu Ching Hei
// Student ID: 1155193237
// Email:      chyu@link.cuhk.edu.hk

#include <iostream>
#include "ActionCard.h"

using namespace std;

ActionCard::ActionCard(Color c, Action a) : Card(c, Value::A), action(a) {
}

Action ActionCard::getAction() const {
    return action;
}

void ActionCard::setAction(Action a) {
    action = a;
}

bool ActionCard::match(Card* top) {
    ActionCard* cardToCompare = dynamic_cast<ActionCard*>(top);
    return top->getColor() == getColor()
        || (cardToCompare != nullptr && cardToCompare->getAction() == getAction());
}

string ActionCard::toString() {
    return string() + "[" + COLORS[int(getColor())][0] + ACTIONS[(int)action][0] + "]";
}