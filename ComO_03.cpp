#include <iostream>
#include <stack>

using namespace std;

bool areBracket(string expr) {
    stack<char> s;
    char x;

    for (int i = 0; i < expr.length(); i++) {
        if (expr[i] == '(' || expr[i] == '[' || expr[i] == '{') {
            s.push(expr[i]);
            continue;
        }
        if (s.empty())
            return false;

        switch (expr[i]) {
            case ')':
                x = s.top();
                s.pop();
                if (x == '{' || x == '[')
                    return false;
                break;

            case '}':

                x = s.top();
                s.pop();
                if (x == '(' || x == '[')
                    return false;
                break;

            case ']':

                x = s.top();
                s.pop();
                if (x == '(' || x == '{')
                    return false;
                break;
        }
    }

    return (s.empty());
}

int main() {
    int num;
    stack<char> bracket;
    string word;
    cin >> num;
    for (int i = 0; i < num; ++i) {
        cin >> word;
        (areBracket(word)) ? cout << "Yes\n" : cout << "No\n";
    }
    return 0;
}
