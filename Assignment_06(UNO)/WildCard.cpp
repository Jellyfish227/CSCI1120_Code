// Name:       Yu Ching Hei
// Student ID: 1155193237
// Email:      chyu@link.cuhk.edu.hk

#include <iostream>
#include "cctype"
#include "WildCard.h"
#include "WildDraw4.h" 
#include "Bot.h"

using namespace std;

WildCard::WildCard() : ActionCard(Color::Wild, Action::ChgColor) {
    setValue(Value::W);
}

bool WildCard::match(Card* /* top */) {
    return true;
}

void WildCard::play(GameState& uno) {
    WildCard *card = dynamic_cast<WildDraw4*>(this);
    if (card == nullptr)
        Card::play(uno);

    Player *player = dynamic_cast<Bot*>(uno.players[*uno.turn]);
    if (player != nullptr) //isBot
        this->setColor(player->mostFrequentColor());
    else //isHuman
        while (true) 
        {
            cout << "Choose a color [R, Y, G, B]: ";
            char c; cin >> c;
            c = tolower(c);
            switch (c){
                case 'r':
                    this->setColor(Color::Red);
                    break;
                case 'y':
                    this->setColor(Color::Yellow);
                    break;
                case 'g':
                    this->setColor(Color::Green);
                    break;
                case 'b':
                    this->setColor(Color::Blue);
                    break;
                default:
                    cout << "Invalid option! Try again." << endl;
                    continue;
            }
            break;
        }

    cout << "Color changed to " << COLORS[int(getColor())] << "!" << endl;
}

string WildCard::toString() {
    return string() + "[W" + ACTIONS[(int)getAction()][0] + "]";
}