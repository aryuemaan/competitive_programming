#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MOD=1e9+7;

ll power(ll a,ll b){
    ll res=1;
    while(b){
        if(b&1)
            res=(res*a)%MOD;
        a=(a*a)%MOD;
        b=b>>1;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--){
        ll n,cnt=0;
        cin>>n;
        ll i=1;
        while(1LL<<i<=n)
            i++;
        for(ll j=1;j<i;j++){
            ll b = (n - (1LL << j)) / (1LL << (j - 1));
            ll a = (n - (1LL << j) + 1) / (1LL << (j - 1));
            cnt=(cnt+((a-b)*(n&(1LL<<(j-1)))%MOD*power(2,j-1))%MOD)%MOD;
            cnt=(cnt+(((a-b-1)*(1LL<<(j-1)))%MOD*power(2,j-1))%MOD)%MOD;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
