#include <bits/stdc++.h>

using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef LOCAL
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define ar array
#define ll long long
#define ld long double
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

void solve();

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}

void solve() {
    int array_size;
    cin >> array_size;
    int arr[array_size];
    map<int, int> freq_count;
    for (int i = 0; i < array_size; i++) {
        cin >> arr[i];
        freq_count[arr[i]]++;
    }
    sort(arr, arr + array_size);
    if (freq_count.size() == 1 || array_size <= 2) {
        cout << "NO\n";
    } else if (freq_count[arr[array_size - 1]] == 1 && freq_count.size() == 2) {
        cout << "NO\n";
    } else if (freq_count[arr[array_size - 1]] > (array_size + 1) / 2) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}
