/*  Name: Yu Ching Hei
    SID: 1155193237
    email: chyu@link.cuhk.edu.hk  */

#include <iostream>
#include <random>
#include <string>

using namespace std;

//mapping rps value
string rpsChoice(int rps) {
    switch (rps) {
        case 1:
            return "Rock";
            break;
        case 2:
            return "Paper";
            break;
        case 3:
            return "Stone";
        default:
            break;
    }
}

int move(int original, int step, int limit) {
    limit -= 1;
    if (original + step > limit) {
        return -1 * (original + step);
    }
}

int main() {
    //input seed and size
    int seed, n;
    cout << "Enter seed and board size: ";
    cin >> seed >> n;

    //implement random
    mt19937 rps(seed), die(seed);  // random number generators
    uniform_int_distribution<> play(1, 3);  // random int in [1, 3]
    uniform_int_distribution<> roll(1, 6);  // random int in [1, 6]

    //initial position declaration
    int hi, hj, ci, cj;
    hi = 1, hj = 1; // initial grid location of human piece
    ci = n, cj = 1; // initial grid location of computer piece

    //round counter
    int round = 0;

    //move counter
    int hSteps = 0;
    int cSteps = 0;

    //main loop by game over detection
    bool isGameOver = false;
    while (!isGameOver) {
        round++;

        //print board
        cout << "Round " << round << ": " << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (ci == i && cj == j) {
                    cout << 'C';
                }
                else if (hi == i && hj == j) {
                    cout << 'H';
                }
                else if (0 == i || n - 1 == i) {
                    cout << '*';
                }
                else if (0 == j || n - 1 == j) {
                    cout << '*';
                }
                else if (i == j || i == n - 1 - j)
                {
                    cout << '*';
                }
                else
                {
                    cout << ' ';
                }
            }
            cout << endl;
        }

        // play rock, paper, scissors
        int hRPS, cRPS = 0;
        while (true) {
            cout << "Choose (1=R, 2=P, 3=S): ";
            cin >> hRPS;
            cRPS = play(rps); // random choice of R, P or S

            //print human vs computer
            cout << "Human picks " << rpsChoice(hRPS) << ". " << endl;
            cout << "Computer picks " << rpsChoice(cRPS) << ". " << endl;
            
            //win detemination
            bool isDraw = false;
            bool isHumanWin = false;

            if (0 == hRPS - cRPS) {
                isDraw = true;
            }
            else if (-2 == hRPS - cRPS || 1 == hRPS - cRPS) {
                isHumanWin = true;
            }
            else {
                isHumanWin = false;
            }

            //moving player
            if (!isDraw) {
                // roll a die for random d steps to move
                int d = 0;
                d = roll(die);

                int maxLim = n - 1, int minLim = 0;
                
                if (isHumanWin) {
                    hSteps += d;
                    if (hj + d > maxLim) {
                        int move = hj + d;
                        hi = maxLim - move % maxLim;
                        hj += move % maxLim;
                    }
                }
                else {
                    cSteps += d;
                    ci;
                    cj;
                }
                        add d to H’s distance away from its start
                        else
                            add d to C’s distance away from its start
                            break
                }
        }
        
        int winningSteps = 3 * n - 2;
        if (hSteps >= winningSteps || cSteps >= winningSteps) {
            isGameOver = true;
        }
    }


    return 0;
}
