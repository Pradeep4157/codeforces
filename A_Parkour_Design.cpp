#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so he can do : x + 2,y + 1 and x + 3,y and x + 4 ,y - 1..

    if i want to reach y ..

    so i will have to do 0...y

    once i reach y..

    then i can only increase x ..

    i will keep doing x + 3..




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
        bool ok = false;
        if (y < 0)
        {
            // now i will min do x + 4 abs y times..
            int times = abs(y);
            int X = times * 4;
            int rem = x - X;
            if (rem >= 0 && ((rem % 3) == 0))
                ok = 1;
        }
        else
        {
            int X = y * 2;
            int rem = x - X;
            if (rem >= 0 && ((rem % 3) == 0))
                ok = 1;
        }
        cout << ((ok) ? "YES" : "NO") << endl;
    }
    return 0;
}
