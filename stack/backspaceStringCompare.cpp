#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> st1;
        stack<char> st2;

        for (auto i : s) {
            if (i == '#') {
                if (!st1.empty()) st1.pop();
            } else {
                st1.push(i);
            }
        }

        for (auto i : t) {
            if (i == '#') {
                if (!st2.empty()) st2.pop();
            } else {
                st2.push(i);
            }
        }

        return st1 == st2;
    }
};

int main() {
    Solution sol;
    string s, t;

    cout << "Enter first string: ";
    cin >> s;

    cout << "Enter second string: ";
    cin >> t;

    if (sol.backspaceCompare(s, t)) {
        cout << "Strings are equal after backspace processing." << endl;
    } else {
        cout << "Strings are NOT equal after backspace processing." << endl;
    }

    return 0;
}