#include <iostream>
#include <stack>

using namespace std;

class MyQueue {
    stack<int> s1;
    stack<int> s2;

public:
    MyQueue() {
    }

    void push(int x) {
        if (s1.empty()) {
            s1.push(x);
        } else {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
            s2.push(x);
            while (!s2.empty()) {
                s1.push(s2.top());
                s2.pop();
            }
        }
    }

    int pop() {
        int x = s1.top();
        s1.pop();
        return x;
    }

    int peek() {
        return s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {
    MyQueue q;

    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.peek() << endl;
    cout << "Popped: " << q.pop() << endl;
    cout << "Front element after pop: " << q.peek() << endl;
    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}