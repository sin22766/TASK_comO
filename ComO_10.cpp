#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    bool finded = false;
    cin >> a >> b >> c;
    for (int x = -100; x < 100; ++x) {
        for (int y = -100; y < 100; ++y) {
            for (int z = -100; z < 100; ++z) {
                if (x != y && x != z && z != y && !finded) {
                    if (x + y + z == a && x * y * z == b && x * x + y * y + z * z == c) {
                        cout << x << " " << y << " " << z;
                        finded = true;
                    }
                }
            }
        }
    }
    if (!finded) {
        cout << "No solution.";
    }
}
