#include <iostream>
#include <list>

using namespace std;

int main() {
    string word;
    list<char> temp;
    list<char>::iterator cursor = temp.begin();
    cin >> word;
    for (char i:word) {
        if (i == '[') {
            cursor = temp.begin();
        } else if (i == ']') {
            cursor = temp.end();
        } else {
            temp.insert(cursor, i);
        }
    }
    for (auto j:temp) {
        cout << j;
    }
    return 0;
}
