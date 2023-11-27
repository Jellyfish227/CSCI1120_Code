#ifndef SKIP_H
#define SKIP_H

#include "ActionCard.h"

class Skip : public virtual ActionCard {
public:
    Skip(Color c);
    virtual void play(GameState& uno) override;
};

#endif // SKIP_H