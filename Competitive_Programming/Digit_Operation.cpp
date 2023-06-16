#include <bits/stdc++.h>
using namespace std;
#define int long long

void placementlelo()
{
    int n, k;
    cin >> n >> k;
    vector<string> A(n), B(n);
    vector<int> another_array(10, 0);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        A[i] = s;
        for (auto it : s)
        {
            another_array[it - '0']++;
        }
    }

    vector<int> char_arrrayr(10, 0);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        B[i] = s;
        for (auto it : s)
        {
            char_arrrayr[it - '0']++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (A[i].size() != B[i].size())
        {
            cout << "NO" << endl;
            return;
        }
    }

    int to_be_s = 0, add = 0;
    for (int i = 0; i < 10; i++)
    {
        if (another_array[i] == char_arrrayr[i])
            continue;
        else if (another_array[i] < char_arrrayr[i])
        {
            to_be_s += (char_arrrayr[i] - another_array[i]);
        }
        else
        {
            add += abs(char_arrrayr[i] - another_array[i]);
        }
    }

    if (to_be_s != add)
    {
        cout << "NO" << endl;
        return;
    }

    if (to_be_s <= k)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}
int32_t main()
{

        int t = 1;
    cin >> t;
    while (t--)
    {
        placementlelo();
    }
    return 0;
}