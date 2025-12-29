#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

        x should be from 0 to a

        if b is greater than a then it is impossible

        else :



*/
int msb(int n)
{
    if (n == 0)
        return -1;
    int msbPos = 0;
    while (n >>= 1)
    {
        msbPos++;
    }
    return msbPos;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        if (a == b)
        {
            cout << 0 << endl;
            continue;
        }
        if (b > a)
        {
            int bmsb = msb(b);
            int amsb = msb(a);
            if (bmsb > amsb)
            {
                cout << -1 << endl;
                continue;
            }
        }

        {
            int xorr = a ^ b;
            vector<int> res;
            int number = 0;
            while (xorr)
            {
                if (xorr & 1)
                {
                    res.push_back((1 << number));
                }
                number++;
                xorr >>= 1;
            }
            cout << res.size() << endl;
            for (auto a : res)
                cout << a << endl;
        }
    }
    return 0;
}
