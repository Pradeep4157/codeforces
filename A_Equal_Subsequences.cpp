#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        for (int i = 0; i < k; i++)
        {
            s += '1';
        }
        for (int i = k; i < n; i++)
        {
            s += '0';
        }
        cout << s << endl;
    }
    return 0;
}
