// Name:       Yu Ching Hei
// Student ID: 1155193237
// Email:      chyu@link.cuhk.edu.hk

#ifndef BOT_H
#define BOT_H

#include "Player.h"

class Bot : public Player
{
public:
    Bot();
    virtual int pickCard(GameState &uno) override;
};


#endif // BOT_H