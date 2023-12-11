// Name:       Yu Ching Hei
// Student ID: 1155193237
// Email:      chyu@link.cuhk.edu.hk

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
	bool gameOver = false;
	int consecPass = 0;
	while (!gameOver)
	{	
		bool haveValueToPass = false;
		round++;

		cout << string(57,'=') << endl;
		cout << "Turn " << round << ":" << endl;
		cout << setw(20) << left;
		cout << "Discard Pile: " + uno.discardPile->top()->toString();
		cout << setw(23) << left;
		cout << "Current Color: " + COLORS[(int)uno.discardPile->top()->getColor()];
		cout << "Draw Pile: " << uno.drawPile->size() << endl;
		cout << string(57,'-') << endl;

		player = players[turn];
		cout << player->getName() << ":" << endl;

		int act = 0;
		if (cardsToDraw > 0)
			player->drawCard(uno.drawPile, cardsToDraw);
		if (!turnSkipped)
		{
			act = player->pickCard(uno);
			if (act != PASSED && act != DRAWN)
			{
				player->playCard(act, uno);
				if (turnSkipped)
					haveValueToPass = true;
			}
			else if (act == PASSED)
			{
				cout << "Turn passed!" << endl;
			}
		}
		else
			cout << "Turn skipped!" << endl;
		

		if (0 == player->handSize() || turnsMax == round) //either this player have no card or this is the last round
		{
			gameOver = true;
		}
		else if (act == PASSED) //consecutive pass check if this player is PASSED
		{
			consecPass += PASSED; //cumulate consecutive pass counter
			if (consecPass == P * PASSED) //P player passed
				gameOver = true;
		}
		else
			consecPass = 0; //this player didn't pass, no longer consecutive and therefore reset the counter
		
		// Reset cardsToDraw and turnSkipped for clean state for next turn.
		if (turnSkipped && !haveValueToPass) {
			cardsToDraw = 0;
			turnSkipped = false;
		}
		// Update the turn integer to let the next player become current.
		turn = (turn + delta + P) % P;
	}

	cout << string(10,'*') << endl;
	cout << "Game Over!" << endl;
	cout << string(10, '*') << endl;
	Player* minPlayer = players[P - 1];
	for (int i = 0; i < P; i++)
	{
		cout << players[i]->getName() << " owes";
		cout << setw(16) << right;
		cout << to_string(players[i]->handPoints()) + " point(s): ";
		players[i]->printHand();
		if (players[P - 1 - i]->handPoints() == 0 && minPlayer->handPoints() == 0)
		{
			if (players[P - 1 - i]->handSize() <= minPlayer->handSize())
				minPlayer = players[P - 1 - i];
		}
		else if (players[P - 1 - i]->handPoints() <= minPlayer->handPoints())
			minPlayer = players[P - 1 - i];
	}
	cout << "The winner is " << minPlayer->getName() << "!" << endl;
}