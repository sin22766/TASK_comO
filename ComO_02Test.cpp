#include <iostream>

using namespace std;

int main() {
    string word, temp = "";
    int cursor = 0;
    cin >> word;
    for (char i:word) {
        if (i == '[') {
            cursor = 0;
        } else if (i == ']') {
            cursor = temp.size();
        } else {
            string s(1, i);
            temp.insert(cursor, s);
            cursor++;
        }
    }
    cout << temp;
    return 0;
}
