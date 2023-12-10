// Name:       Yu Ching Hei
// Student ID: 1155193237
// Email:      chyu@link.cuhk.edu.hk

#include <iostream>
#include "Reverse.h"

using namespace std;

Reverse::Reverse(Color c) : ActionCard(c, Action::Reverse) {
}

void Reverse::play(GameState& uno) {
    *(uno.delta) *= -1;
    Card::play(uno);
}