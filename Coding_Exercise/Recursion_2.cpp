#include <cctype>
#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string& str, int start, int end) {
    // TODO: Implement this function
    if (start >= end)
        return true;
    if (tolower(str.at(start)) == tolower(str.at(end)))
        return isPalindrome(str, start + 1, end - 1);
    else
        return false;
}

bool isPalindrome(const string& str) {
    int start = 0;
    int end = str.length() - 1;
    return isPalindrome(str, start, end);
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    bool result = isPalindrome(str);
    cout << "It is " << (result ? "" : "not ") << "a palindrome.\n";

    return 0;
}