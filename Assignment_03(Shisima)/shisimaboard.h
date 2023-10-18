// Name:       Yu Ching Hei
// Student ID: 1155193237
// Email:      chyu@link.cuhk.edu.hk

#ifndef SHISIMABOARD_H
#define SHISIMABOARD_H

// Function prototypes
int boardState(int board, int pos);
void printBoard(int board);
bool movePiece(int& board, int pos1, int pos2, int p);
int formLine(int board);

/* You may put in extra function prototypes here if you have written extra
   functions in shisimaboard.cpp. */
int power(int base, int index);
bool isAdj(int pos1, int pos2);
int Coo(int board);


#endif // SHISIMABOARD_H