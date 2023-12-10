#ifndef BOT_H
#define BOT_H

// TODO: //done, REMOVE after test
// Define the Bot class which inherits from Player.
#include "Player.h"

class Bot : public Player
{
public:
    Bot();
    virtual int pickCard(GameState &uno) override;
};


#endif // BOT_H