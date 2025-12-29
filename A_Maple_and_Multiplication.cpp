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
        int a, b;
        cin >> a >> b;
        if (a > b)
            swap(a, b);
        if (a == b)
            cout << 0 << endl;
        else
        {
            if (b % a)
                cout << 2 << endl;
            else
                cout << 1 << endl;
        }
    }
    return 0;
}
