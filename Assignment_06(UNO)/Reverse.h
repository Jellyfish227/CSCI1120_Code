// Name:       Yu Ching Hei
// Student ID: 1155193237
// Email:      chyu@link.cuhk.edu.hk

#ifndef REVERSE_H
#define REVERSE_H

// TODO:
// Define the Reverse class which inherits from ActionCard.
#include "ActionCard.h"
class Reverse : public ActionCard
{
public:
    Reverse(Color c);
    virtual void play(GameState& uno) override;
};

#endif // REVERSE_H