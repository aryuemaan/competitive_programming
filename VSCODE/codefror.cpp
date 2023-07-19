#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define all(a) a.begin(),a.end()
using namespace std;

void solve(){
  ll n, rem, add;
  cin >> n >> rem >> add;

  vector<ll> v;
  map<ll,ll> m1;
  ll extra = 0;

  for (ll i = 0; i < n; i++) {
    ll x;
    cin >> x;
    if (m1[x] > 0) {
      extra += rem;
      continue;
    }
    v.push_back(x);
    m1[x]++;
  }

  sort(all(v));
  n = v.size();
  vector<ll> prefix(n, 0);
  ll start = 1;

  if (v[0] == 1) {
    prefix[0] = 0;
  } else {
    prefix[0] = add + (rem * (v[0] - 2));
  }

  start = v[0] + 1;

  for (ll i = 1; i < n; i++) {
    prefix[i] = prefix[i-1] + (v[i]-start);
    start = v[i] + 1;
  }

  ll ans = INT_MAX;

  if (v[0] != 1) {
    ll tp1 = add + (n * rem);
    ans = min(ans, tp1);
  }

  for (ll i = 0; i < n; i++) {
    ll cur = (prefix[i] * add) + (rem * (n - i - 1));
    ans = min(ans, cur);
  }

  cout << extra + ans << endl;
}

int main(){
    int t = 1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
