#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        int k = 0;
        while (k * (k + 1) / 2 < a + b) {
            k++;
        }
        if (k * (k + 1) / 2 - a == b) {
            cout << k << endl;
        } else {
            cout << k + 1 << endl;
        }
    }
    return 0;
}
