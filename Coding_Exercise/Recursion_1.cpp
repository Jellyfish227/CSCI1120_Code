#include <iostream>

using namespace std;

int count(string s, char ch) {
    // TODO: Your code here
    if (s == "")
        return 0;
    if (s.at(0) == ch)
        return 1 + count(s.substr(1), ch);
    else
        return count(s.substr(1), ch);
}

int main() {
    cout << count("Computer Science", 'e') << endl; // print 3
    cout << count("Computer Science", 'a') << endl; // print 0
}
