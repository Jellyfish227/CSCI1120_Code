#ifndef DRAW2_H
#define DRAW2_H

#include "Skip.h"

class Draw2 : public Skip {
public:
    Draw2(Color c);
    int getDrawCount() const;
    void setDrawCount(int d);
    virtual void play(GameState& uno) override;
private:
    int drawCount;
};

#endif // DRAW2_H