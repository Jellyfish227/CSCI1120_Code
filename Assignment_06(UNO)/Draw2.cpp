#include <iostream>
#include "Draw2.h"

using namespace std;

Draw2::Draw2(Color c) : ActionCard(c, Action::Draw2), Skip(c), drawCount(2) {
}

int Draw2::getDrawCount() const {
    return drawCount;
}

void Draw2::setDrawCount(int d) {
    drawCount = d;
}

void Draw2::play(GameState& uno) {
    Skip::play(uno);
    *(uno.cardsToDraw) = drawCount;
}
