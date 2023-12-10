// Name:       Yu Ching Hei
// Student ID: 1155193237
// Email:      chyu@link.cuhk.edu.hk

#ifndef WILDDRAW4_H
#define WILDDRAW4_H
#include "WildCard.h"
#include "Draw2.h"

class WildDraw4 : public WildCard, public Draw2 {
public:
    WildDraw4();
    virtual bool match(Card* top) override;
    virtual void play(GameState& uno) override;
    virtual std::string toString() override;
};

#endif // WILDDRAW4_H