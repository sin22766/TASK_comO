#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    int x, y, z;
    char mode;
    cin >> n >> m;
    stack<int> mem[n];
    for (int j = 0; j < n; ++j) {
        mem[j].push(0);
    }
    stack<int> change;
    for (int i = 0; i < m; ++i) {
        cin >> mode >> x;
        switch (mode) {
            case '=':
                cin >> y;
                mem[x - 1].push(y);
                change.push(x - 1);
                break;
            case '+':
                cin >> y >> z;
                mem[z - 1].push(mem[x - 1].top() + mem[y - 1].top());
                change.push(z - 1);
                break;
            case '-':
                cin >> y >> z;
                mem[z - 1].push(mem[x - 1].top() - mem[y - 1].top());
                change.push(z - 1);
                break;
            case 'C':
                cin >> y;
                mem[y - 1].push(mem[x - 1].top());
                change.push(y - 1);
                break;
            case 'P':
                cout << mem[x - 1].top() << "\n";
                break;
            case 'U':
                for (int l = 0; l < x; ++l) {
                    if (!change.empty()) {
                        if (!mem[change.top()].empty()) {
                            mem[change.top()].pop();
                            change.pop();
                        }
                    }
                }
                break;
            default:
                break;
        }
    }
    return 0;
}
