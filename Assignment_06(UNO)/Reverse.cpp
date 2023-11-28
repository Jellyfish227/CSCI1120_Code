// TODO: //done, REMOVE after test
// Implement the Reverse class
// Name:       Yu Ching Hei
// Student ID: 1155193237
// Email:      chyu@link.cuhk.edu.hk

#include <iostream>
#include "Reverse.h"

using namespace std;

Reverse::Reverse() : ActionCard(Color::Wild, Action::ChgColor) {
}

void Reverse::play(GameState& uno) {
    *(uno.delta) *= -1;
}