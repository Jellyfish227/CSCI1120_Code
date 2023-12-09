#include <iostream>
#include <string>
#include <cctype>
#include <iomanip>
#include <climits>
// You may add additional headers if needed

#include "ActionCard.h"
#include "Man.h"
#include "Bot.h"
#include "DrawPile.h"
#include "DiscardPile.h"

using namespace std;

int main()
{
	// Get the game start-up parameters 
	string input;
	unsigned int seed = 123;
	cout << "Enter seed (or hit Enter): ";
	getline(cin, input);
	if (!input.empty()) {
		seed = stoi(input);
	}
	cout << "Seed: " << seed << endl;
	srand(seed);

	bool debugMode = false;
	cout << "Play in debug mode (Y/N)? ";
	getline(cin, input);
	if (input == "Y" || input == "y" || input == "") {
		debugMode = true;
	}
	cout << "Debug mode: " << boolalpha << debugMode << endl;

	int turnsMax = 100;
	cout << "Max. turns to play: ";
	getline(cin, input);
	if (!input.empty()) {
		turnsMax = stoi(input);
	}
	cout << "Max. turns: " << turnsMax << endl;

	int M, B, P;
	while (true) {
		cout << "Enter # man and bot players: ";
		cin >> M >> B;
		P = M + B;
		if (P >= 2 && P <= 5)
			break;
		cout << "Require 2 to 5 players!" << endl;
	}
	cout << "#Men: " << M << "; #Bots: " << B << endl;

	// Create an array of pointers to Player objects
	Player** players = new Player * [P];
	for (int i = 0; i < P; i++) {
		if (i < M)
			players[i] = new Man;
		else
			players[i] = new Bot;
	}
	Player* player = players[0];  // current player

	// Define variables to track the game state
	DrawPile drawPile;
	DiscardPile discardPile;
	bool turnSkipped = false;
	int cardsToDraw = 0;
	int delta = 1;
	int turn = 0;

	GameState uno{ players, &drawPile, &discardPile,
		&turnSkipped, &cardsToDraw, &turn, &delta, P, debugMode
	};

	// Shuffle the deck and deal cards to each player
	if (debugMode)
	{
		cout << "Cards created:" << endl;
		drawPile.print();
	}
	drawPile.shuffle();
	for (int i = 0; i < P; i++) {
		players[i]->drawCard(&drawPile, H);
	}

	// Draw the first card onto discard pile
	vector<Card*> firstCard;
	drawPile.draw(firstCard, 1);
	discardPile.stack(firstCard.at(0)); 
	if (debugMode) {
		cout << "Draw pile after shuffling and dealing:" << endl;
		drawPile.print();
	}

	// Start the game loop
	int round = 0;
	while (true)
	{	
		round++;
		player = players[turn];

		// TODO:  //done, REMOVE after test
		// Print the "turn header" which shows discard pile's top card,
		// current color and current size of draw pile.
		cout << string(57,'=') << endl;
		cout << "Turn " << round << ":" << endl;
		cout << setw(20) << left;
		cout << "Discard Pile: " << uno.discardPile->top()->toString();
		cout << setw(23) << left;
		cout << "Current Color: " << COLORS[(int)uno.discardPile->top()->getColor()];
		cout << "Draw Pile: " << uno.drawPile->size() << endl;
		cout << string(57,'-') << endl;

		// Print the name of the current player.
		// (Hint: you can use the turn integer to index the players array
		//  to get a pointer to the current player.)
		cout << player->getName() << endl;

		// If cardsToDraw > 0, current player draws the required # cards.
		// If turnSkipped is true, current player skips picking and playing
		// a card in this turn.
		// Otherwise, call the pickCard() method to get the index of a
		// selected card in hand.
		// Then call the playCard() method with the obtained index if it is
		// not PASSED and not DRAWN.
		if (cardsToDraw > 0)
		{
			player->drawCard(uno.drawPile, cardsToDraw);
		} 
		if (turnSkipped)
			continue;
		else {
			int act = player->pickCard(uno);
			if (act != PASSED && act != DRAWN)
				player->playCard(act, uno);
		}
		
		// Check game over condition. Exit the game loop if either:
		// (1) current player's hand has no cards.
		// (2) all players consecutively passed their turns
		//     (i.e., no one can play a card or draw).
		int allPass = 0;
		for (int i = 0; i < P; i++)
		{
			allPass += players[i]->pickCard(uno);
		}
		if (0 == player->handSize() || allPass == PASSED * P || turnsMax == round)
		{
			break;
		}
		
		

		// Reset cardsToDraw and turnSkipped for clean state for next turn.
		cardsToDraw = 0;
		turnSkipped = false;
		// Update the turn integer to let the next player become current.
		turn = (turn + delta + P) % P;
	}

	// TODO:  //done, REMOVE after test
	// Print the game over message.
	// List all players' hands and the sum of points of all cards in hand.
	// Print the name of the winner.
	cout << string(10,'*') << endl;
	cout << "Game Over!" << endl;
	cout << string(10, '*') << endl;
	Player* minPlayer = players[P - 1];
	for (int i = 0; i < P; i++)
	{
		cout << players[i]->getName() << " owes";
		cout << setw(16) << right;
		cout << players[i]->handPoints() << " point(s): ";
		players[i]->printHand();
		if (players[P - 1 - i]->handPoints() <= minPlayer->handPoints())
			minPlayer = players[P - 1 - i];
	}
	cout << "The winner is " << minPlayer->getName() << endl;
}