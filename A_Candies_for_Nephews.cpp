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
        int rem = n % 3;
        if (rem == 0)
            cout << 0 << endl;
        else
        {
            cout << 3 - rem << endl;
        }
    }
    return 0;
}
