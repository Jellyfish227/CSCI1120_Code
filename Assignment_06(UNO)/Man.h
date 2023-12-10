// Name:       Yu Ching Hei
// Student ID: 1155193237
// Email:      chyu@link.cuhk.edu.hk

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