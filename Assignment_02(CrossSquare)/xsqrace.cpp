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
            return "Scissors";
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
    hi = 0, hj = 0; // initial grid location of human piece
    ci = n-1, cj = 0; // initial grid location of computer piece

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
                    cout << "C ";
                }
                else if (hi == i && hj == j) {
                    cout << "H ";
                }
                else if (0 == i || n - 1 == i) {
                    cout << "* ";
                }
                else if (0 == j || n - 1 == j) {
                    cout << "* ";
                }
                else if (i == j || i == n - 1 - j) {
                    cout << "* ";
                }
                else {
                    cout << "  ";
                }
            }
            cout << endl;
        }

        bool isHComplemented = false;
        bool isCComplemented = false;

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
                cout << "Draw!" << endl;
                continue;
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

                int maxLim = n - 1;
                int minLim = 0;

                if (isHumanWin) {
                    cout << "Human wins and moves " << d << " step(s)." << endl;
                    hSteps += d;
                    int dx = hj + d;
                    if (hi == minLim || hi == maxLim) { //from horizontal row
                        if (dx > maxLim) { //from horizontal row, larger than limit
                            isHComplemented = (dx / maxLim) % 2 == 1 ? !isHComplemented : isHComplemented;
                            dx %= maxLim;
                            if (isHComplemented) { //from horizontal, larger than limit, to diagonal
                                hj = maxLim - dx;
                                hi = hi == minLim ? hi + dx : maxLim - dx; //flip when hi is at max
                                break;
                            }
                            else { //from horizontal row,larger than limit, to horizontal
                                hj = dx;
                                hi = (hi == minLim) ? maxLim : minLim;
                                break;
                            }
                        }
                        else { //from horizontal, less then limit
                            hj = dx;
                            hi = hi;
                            break;
                        }
                    }
                    else { //from diagonal
                        int dy = hi + d;
                        if (dy > maxLim) { //from diagonal, larger than limit
                            isHComplemented = ((d - hj) / maxLim) % 2 == 1 ? !isHComplemented : isHComplemented;
                            dx %= maxLim;
                            if (!isHComplemented) { //from diagonal, larger than limit, to horizontal
                                hj = (d - hj) % maxLim;
                                hi = d < 3 * maxLim - 2 ? maxLim : minLim;
                                break;
                            }
                            else { //from diagonal, larger than limit, to diagonal
                                hj = maxLim - dx;
                                hi = maxLim - dx;
                                break;
                            }

                        }
                        else { //from diagonal, less than limit
                            hj = maxLim - d;
                            hi = dy;
                            break;
                        }
                    }
                }
                else {
                    cout << "Computer wins and moves " << d << " step(s)." << endl;
                    cSteps += d;
                    int dx = cj + d;
                    if (ci == minLim || ci == maxLim) { //from horizontal row
                        if (dx > maxLim) { //from horizontal row, larger than limit
                            isCComplemented = (dx / maxLim) % 2 == 1 ? !isCComplemented : isCComplemented;
                            dx %= maxLim;
                            if (isCComplemented) { //from horizontal, larger than limit, to diagonal
                                cj = maxLim - dx;
                                ci = ci == maxLim ? maxLim - dx : ci + dx; //flip when ci is at max
                                break;
                            }
                            else { //from horizontal row,larger than limit, to horizontal
                                cj = dx;
                                ci = (ci == maxLim) ? minLim : maxLim;
                                break;
                            }
                        }
                        else { //from horizontal, less then limit
                            cj = dx;
                            ci = ci;
                            break;
                        }
                    }
                    else { //from diagonal
                        int dy = ci - d;
                        if (dy < minLim) { //from diagonal, over limit
                            isCComplemented = ((d - cj) / maxLim) % 2 == 1 ? !isCComplemented : isCComplemented;
                            dx %= maxLim;
                            if (!isCComplemented) { //from diagonal, larger than limit, to horizontal
                                cj = (d - hi) % maxLim;
                                ci = d < 3 * maxLim - 2 ? minLim : maxLim;
                                break;
                            }
                            else { //from diagonal, larger than limit, to diagonal
                                cj = maxLim - dx;
                                ci = dx;
                                break;
                            }
                        }
                        else { //from diagonal, less than limit
                            cj = maxLim - d;
                            ci = maxLim - d;
                            break;
                        }
                    }
                }
            }

        }
            int winningSteps = 3 * n - 2;
            if (hSteps >= winningSteps) {
                isGameOver = true;
                cout << "Game over! " << endl;
                cout << "Human wins the game!" << endl;
            }
            else if (cSteps >= winningSteps) {
                isGameOver = true;
                cout << "Computer wins the game!" << endl;
            }
            
    }

    return 0;
}
