#include<stdio.h>
#include<string.h>

#define ll long long
#define MOD 1000000007
#define SIZE 1000002

void solve(){
    char s[SIZE];
    scanf("%s", s);
    int n = strlen(s);
    int mp[10] = {0};
    for(int i=0;i<n;i++) mp[s[i]-'0']++;
    int sz=0;
    for(int i=0;i<10;i++) if(mp[i]) sz++;
    if(sz==4 || sz==3) printf("4\n");
    else if(sz==1) printf("-1\n");
    else{
        for(int i=0;i<10;i++){
            if(mp[i]==3) {
                printf("6\n");
                return;
            }
        }
        printf("4\n");
    }
}

int main(){
    ll t;
    scanf("%lld", &t);
    while(t--){
        solve();
    }
    return 0;
}