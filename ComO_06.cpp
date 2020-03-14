#include <iostream>
#include <stack>

using namespace std;

struct Queue {
    stack<int> s1, s2;

    void enq(int x) {
        s1.push(x);
        cout << "push 1\n";
    }

    void deq() {
        if (s1.empty() && s2.empty()) {
            exit(0);
        }
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
                cout << "move 1 2\n";
            }
        }
        cout << "pop 2\n";
        cout << s2.top() << "\n";
        s2.pop();
    }
};

int main() {
    Queue newQueue;
    int command;
    cin >> command;
    for (int i = 0; i < command; ++i) {
        string word;
        int val;
        cin >> word;
        if (word == "enq") {
            cin >> val;
            newQueue.enq(val);
        } else {
            newQueue.deq();
        }
    }
    return 0;
}
