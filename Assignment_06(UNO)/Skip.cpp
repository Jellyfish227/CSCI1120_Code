#include <iostream>
#include "Skip.h"

using namespace std;

Skip::Skip(Color c) : ActionCard(c, Action::Skip) {
}

void Skip::play(GameState& uno) {
    Card::play(uno);
    *(uno.turnSkipped) = true;
}