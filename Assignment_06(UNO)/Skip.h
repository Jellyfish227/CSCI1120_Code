#ifndef SKIP_H
#define SKIP_H

#include "ActionCard.h"

class Skip : public virtual ActionCard { //virtual inheritance to make sure only one copy of member
public:
    Skip(Color c);
    virtual void play(GameState& uno) override;
};

#endif // SKIP_H