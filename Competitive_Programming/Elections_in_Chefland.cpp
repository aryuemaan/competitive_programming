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

int count_values_greater_than_x(const std::vector<int>& values, int x) {
    int count = 0;
    for (auto value : values) {
        if (value >= x) {
            count++;
        }
    }
    return count;
}

int main() {
    int num_cases;
    std::cin >> num_cases;
    while (num_cases--) {
        int num_values, threshold;
        std::cin >> num_values >> threshold;
        std::vector<int> values(num_values);
        for (auto& value : values) {
            std::cin >> value;
        }
        int count = count_values_greater_than_x(values, threshold);
        std::cout << count << '\n';
    }
    return 0;
}
