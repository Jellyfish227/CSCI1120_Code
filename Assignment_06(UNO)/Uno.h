// Name:       Yu Ching Hei
// Student ID: 1155193237
// Email:      chyu@link.cuhk.edu.hk

#ifndef UNO_H
#define UNO_H

// Global constants
const int PASSED = -1;  // a flag meaning player has no matching card to play and draw pile is empty
const int DRAWN = -2;   // a flag meaning player has drawn a card not matching discard pile's top

// Forward declaration
class Player;  
class DrawPile;
class DiscardPile;

struct GameState {
    Player** players;
    DrawPile* drawPile;
    DiscardPile* discardPile;
    bool* turnSkipped;
    int* cardsToDraw;
    int* turn;
    int* delta;
    int P;
    bool debugMode;
};

#endif  // UNO_H