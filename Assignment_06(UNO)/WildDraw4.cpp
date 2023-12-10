// Name:       Yu Ching Hei
// Student ID: 1155193237
// Email:      chyu@link.cuhk.edu.hk

#include <iostream>
#include "WildDraw4.h"

using namespace std;

WildDraw4::WildDraw4() : ActionCard(Color::Wild, Action::Draw4), Draw2(Color::Wild) {
    setDrawCount(4);
}

bool WildDraw4::match(Card* top) {
    return WildCard::match(top);
}

void WildDraw4::play(GameState& uno) {
    Draw2::play(uno);
    WildCard::play(uno);
}

string WildDraw4::toString() {
    return WildCard::toString();
}