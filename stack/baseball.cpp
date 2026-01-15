#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& operations) {
        int sum = 0;
        stack<int> st;

        for (int i = 0; i < operations.size(); i++) {
            if (operations[i] != "+" && operations[i] != "D" && operations[i] != "C") {
                st.push(stoi(operations[i]));
            } else if (operations[i] == "+") {
                int temp = st.top();
                st.pop();
                int newRecord = temp + st.top();
                st.push(temp);
                st.push(newRecord);
            } else if (operations[i] == "D") {
                st.push(2 * st.top());
            } else if (operations[i] == "C") {
                st.pop();
            }
        }

        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};

int main() {
    Solution sol;
    vector<string> operations;
    int n;
    
    cout << "Enter number of operations: ";
    cin >> n;

    cout << "Enter operations (use numbers, +, D, C): ";
    for (int i = 0; i < n; i++) {
        string op;
        cin >> op;
        operations.push_back(op);
    }
    int result = sol.calPoints(operations);
    cout << "Total points: " << result << endl;
    return 0;
}