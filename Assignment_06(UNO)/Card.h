// Name:       Yu Ching Hei
// Student ID: 1155193237
// Email:      chyu@link.cuhk.edu.hk

#ifndef CARD_H
#define CARD_H
#include <string>
#include "Uno.h"

const std::string COLORS[5] = { "Red", "Yellow", "Green", "Blue", "Wild" };
enum class Color : int { Red, Yellow, Green, Blue, Wild };
enum class Value : int { N0, N1, N2, N3, N4, N5, N6, N7, N8, N9, A = 20, W = 50 };

class Card {
public:
	Card(Color c, Value v);
	Color getColor() const;
	Value getValue() const;
	void setColor(Color c);
	void setValue(Value v);
	virtual bool match(Card* top);
	virtual void play(GameState& uno);
	virtual std::string toString();
private:
	Color color;
	Value value;
};

#endif // CARD_H