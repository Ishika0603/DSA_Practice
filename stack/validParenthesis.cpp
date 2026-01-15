#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;   

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                st.push(s[i]);
            } 
            else if (s[i] == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                } else return false;
            } 
            else if (s[i] == '}') {
                if (!st.empty() && st.top() == '{') {
                    st.pop();
                } else return false;
            } 
            else if (s[i] == ']') {
                if (!st.empty() && st.top() == '[') {
                    st.pop();
                } else return false;
            }
        }

        return st.empty();
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter a string of parentheses: ";
    cin >> s;
    if (sol.isValid(s)) {
        cout << "Valid Parentheses" << endl;
    } else {
        cout << "Invalid Parentheses" << endl;
    }
    return 0;
}