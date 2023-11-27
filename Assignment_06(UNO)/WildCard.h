#ifndef WILDCARD_H
#define WILDCARD_H

#include "ActionCard.h"

class WildCard : public virtual ActionCard {
public:
    WildCard();
    virtual bool match(Card* /* top */) override;
    virtual void play(GameState& uno) override;
    virtual std::string toString() override;
};

#endif // WILDCARD_H