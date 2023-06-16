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



void solve() {
    
}

vector<ll> fibonacci;

bool can_reach(ll x, ll y, ll n) {
    if (n == 1) return true;
    if (min(y, fibonacci[n+1] - y + 1) > fibonacci[n+1] - fibonacci[n]) {
        return false;
    }
    y = min(y, fibonacci[n+1] - y + 1);
    return can_reach(y, x, n-1);
}

int main() {
    ll t, n, x, y;
    cin >> t;
    fibonacci.push_back(1);
    fibonacci.push_back(1);
    for (int i = 0; i < 46; i++) {
        fibonacci.push_back(fibonacci[i] + fibonacci[i+1]);
    }
    while (t--) {
        cin >> n >> x >> y;
        if (can_reach(x, y, n)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    return 0;
}
