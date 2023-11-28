#ifndef REVERSE_H
#define REVERSE_H

// TODO:
// Define the Reverse class which inherits from ActionCard.
class Reverse
{
private:
    Card card;
public:
    Reverse(Color c);
    
};

Reverse::Reverse(Color c) {
    this->card = Card(c, "reverse");
}

#endif // REVERSE_H