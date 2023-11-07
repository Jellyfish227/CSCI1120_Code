#ifndef RUSHHOUR_H
#define RUSHHOUR_H

#include <string>

class RushHour {
public:
    RushHour(std::string g[]);
    bool locateCar(int car, int& row, int& col) const;
    int moveCar(int car, int step);
    bool isSolved() const;
    int getTotalSteps() const;
    void print() const;
private:
    std::string grid[8];
    int totalSteps;
};

#endif // RUSHHOUR_H