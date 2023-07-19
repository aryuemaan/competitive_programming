#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int m;
        cin >> m;

        vector<int> last_winner(50001, 0);
        vector<set<int>> participants(m);
        for(int i=0; i<m; i++) {
            int ni;
            cin >> ni;

            for(int j=0; j<ni; j++) {
                int participant;
                cin >> participant;
                participants[i].insert(participant);
            }

            auto winner = participants[i].upper_bound(last_winner[i]);
            if(winner == participants[i].end()) {
                cout << "-1\n";
                break;
            }
            cout << *winner << " ";
            last_winner[i+1] = *winner;
        }
        cout << "\n";
    }

    return 0;
}
