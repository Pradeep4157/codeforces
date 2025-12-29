#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    only k letters should be used..

    i,j if div by x then si!=sj

    n no valid string exists..



*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int k, x;
        cin >> k >> x;
        cout << (k * x + 1) << endl;
    }
    return 0;
}
