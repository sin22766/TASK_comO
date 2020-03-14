#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    bool have = false;
    unsigned long long n, i = 1234, dividend, num_temp;
    string temp;
    cin >> n;
    dividend = n * i;
    while (dividend <= 98765) {
        dividend = n * i;
        num_temp = dividend * 100000 + i;
        temp = to_string(num_temp);
        sort(temp.begin(), temp.end());
        if (temp == "0123456789" || temp == "123456789") {
            cout << setfill('0') << setw(5) << dividend << " / " << setfill('0') << setw(5) << i << " = " << n << "\n";
            have = true;
        }
        i++;
    }
    if (!have) {
        cout << "There are no solutions for N.";
    }
}