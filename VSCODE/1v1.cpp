#include <iostream>
using namespace std;

int main(){
int l, r;
    cin >> l, r;
    int ans = 0;
    for (int i = l; i <= r; i++)
    {
        string s = to_string(i);
        int x = max_element(s.begin(), s.end()) - min_element(s.begin(), s.end());
        ans = max(ans,x);
    }

    cout << ans << endl;

return 0;
}
