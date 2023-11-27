#ifndef ACTION_CARD_H
#define ACTION_CARD_H
#include "Card.h"

const std::string ACTIONS[5] = { "Skip", "Reverse", "Draw 2", "Draw 4", "Change Color" };
enum class Action : int { Skip, Reverse, Draw2, Draw4, ChgColor };

class ActionCard : public Card {
public:
    ActionCard(Color c, Action a);
    Action getAction() const;
    void setAction(Action a);
    virtual bool match(Card* top) override;
    virtual std::string toString() override;
private:
    Action action;
};

#endif // ACTION_CARD_H