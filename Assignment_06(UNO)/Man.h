#ifndef MAN_H
#define MAN_H

#include "Player.h"

class Man : public Player
{
public:
    Man();
    virtual int pickCard(GameState& uno) override;
};

#endif // MAN_H