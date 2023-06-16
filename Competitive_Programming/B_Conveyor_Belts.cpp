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


#include <bits/stdc++.h>
using namespace std;

int finding(int a, int b, int n){
  a--; 
  b--;
  a = min(a, n-a-1); 
  b = min(b, n-b-1); 
  return min(a, b); 
}
int main(){
    int tc, n, x1, y1, x2, y2;
    cin >> tc; 
    while(tc--){
      cin >> n >> x1 >> y1 >> x2 >> y2; 
      cout << abs(finding(x1, y1, n) - finding(x2, y2, n)) << "\n";
    }
    return 0;
}
