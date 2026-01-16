#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n <= 2)
            cout << n << endl;
        else if (n == 3)
        {
            cout << 3 << endl;
        }
        else if (n & 1)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
