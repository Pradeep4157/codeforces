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
    int x, n;
    cin >> x >> n;
    int ogx = x;
    x = (x / 1000) * 1000;
    while (true)
    {
        int currpay = (x / 1000) * n;
        if (currpay + x <= ogx)
        {
            break;
        }
        x -= 1000;
    }

    cout << x << endl;
    return 0;
}
