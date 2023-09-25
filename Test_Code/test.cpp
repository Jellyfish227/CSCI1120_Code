/*  Name: Yu Ching Hei
    SID: 1155193237
    email: chyu@link.cuhk.edu.hk  */

#include <iostream>
#include <random>

using namespace std;

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

    //main loop by game over detection
    bool isGameOver;
    while (!isGameOver) {
        //run nested loop here to print the grid of * with H and C
        //at their current grid locations (hi, hj) and (ci, cj)
        for (int i = 0; i < n; i++){
            for (int j = n; j > 0; j--){
                if (0 == i || n-1 == i){
                    cout << '*';
                }
                else if (0 == j || n-1 == j){
                    cout << '*';
                }
                
            }
        }
    
        // play rock, paper, scissors
        while (true) {
            human choice = input from cin // R, P or S
            computer choice = play(rps) // random choice of R, P or S
            print human vs. computer choice 
            if (not draw) {
                // roll a die for random d steps to move
                d = roll(die)
                if (human wins)
                    add d to H’s distance away from its start
                else
                    add d to C’s distance away from its start
                    break
            }
        }
        adjust H’s location (hi, hj) based on its distance away from start
        adjust C’s location (ci, cj) based on its distance away from start
    
        if either end is reached
        set game over to true

    }
}
