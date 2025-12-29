#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    if x==y we cant reach
    if x< y we can reach there in 2 steps
    else:
        here x >y we need to first make y-1 steps then y then rem
        but this rem should be > y

        this will only happen if y<=x/2
*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int x, y;
        cin >> x >> y;
        if (x == y)
        {
            cout << -1 << endl;
            continue;
        }
        else if (x < y)
        {
            cout << 2 << endl;
        }
        else
        {
            if (y - 1 > 0 && 1 + y < x)
            {
                cout << 3 << endl;
            }
            else
                cout << -1 << endl;
        }
    }
    return 0;
}
