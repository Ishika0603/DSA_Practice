#include <iostream>
#include <queue>

using namespace std;

class MyStack {
private:
    queue<int> q1;
    queue<int> q2;

public:
    MyStack() {
    }

    void push(int x) {
        if (q1.empty()) {
            q1.push(x);
        } else {
            while (!q1.empty()) {
                q2.push(q1.front());
                q1.pop();
            }
            q1.push(x);
            while (!q2.empty()) {
                q1.push(q2.front());
                q2.pop();
            }
        }
    }

    int pop() {
        int temp;
        if (!q1.empty()) {
            temp = q1.front();
            q1.pop();
            return temp;
        }
        return -1;
    }

    int top() {
        if (!q1.empty()) {
            return q1.front();
        }
        return -1;
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack st;

    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top element: " << st.top() << endl;
    cout << "Popped: " << st.pop() << endl;
    cout << "Top element after pop: " << st.top() << endl;
    cout << "Is stack empty? " << (st.empty() ? "Yes" : "No") << endl;

    return 0;
}