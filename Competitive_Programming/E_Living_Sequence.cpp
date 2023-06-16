#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int ii() {
    int x;
    cin >> x;
    return x;
}

vector<int> ai() {
    vector<int> v;
    string s;
    cin >> s;
    for (char c : s) {
        v.push_back(c - '0');
    }
    return v;
}

int base9(int x) {
    vector<int> digits;
    int base9_int = 0;
    while (x > 0) {
        digits.push_back(x % 9);
        x = x / 9;
    }
    reverse(digits.begin(), digits.end());
    for (int digit : digits) {
        base9_int = base9_int * 10 + digit;
    }
    return base9_int;
}

int main() {
    int t = ii();
    while (t--) {
        int n = ii();
        vector<int> s = ai();
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 5) {
                s[i] = s[i] + 1;
            }
        }
        int base_10 = 0;
        for (int digit : s) {
            base_10 = base_10 * 9 + digit;
        }
        cout << base9(base_10) << endl;
    }
    return 0;
}
