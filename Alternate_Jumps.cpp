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
        int i = 1;
        int x = n;
        while (i < n)
        {
            if (i & 1)
            {
                // he will jump left
                x = x - (n - i);
            }
            else
            {
                x = x + (n - i);
            }
            i++;
        }
        cout << x << endl;
    }
    return 0;
}
