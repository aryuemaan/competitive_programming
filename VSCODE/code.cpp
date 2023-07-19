#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> v(n);
    for(int i = 0; i < n; ++i) {
        int m;
        cin >> m;
        for(int j = 0; j < m; ++j) {
            int person;
            cin >> person;
            v[i].push_back(person);
        }
    }
    set<int> s;
    vector<int> ans;
    for(int i = n - 1; i >= 0; i--) {
        int winner = -1;
        for(int j = 0; j < v[i].size(); ++j) {
            if(s.find(v[i][j]) == s.end() && winner == -1) {
                winner = v[i][j];
            }
            s.insert(v[i][j]);
        }
        if(winner == -1) {
            cout << "-1\n";
            return;
        }
        ans.push_back(winner);
    }
    reverse(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
