#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    int end = n - 1 - b;
    for (int i = 0; i < n; i++)
    {
        if (i >= a && i <= end)
            cout << s[i];
    }
    cout << endl;
    return 0;
}
