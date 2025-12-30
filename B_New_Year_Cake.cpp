#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
int find(int first, int second)
{
    bool f = 1;
    int req = 1;
    int res = 0;
    while (true)
    {
        if (f)
        {
            if (first < req)
                break;
            first -= req;
            f = false;
            res++;
        }
        else
        {
            if (second < req)
                break;
            second -= req;
            f = true;
            res++;
        }
        req *= 2;
    }
    return res;
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
        int res = find(a, b);
        res = max(res, find(b, a));
        cout << res << endl;
    }
    return 0;
}
