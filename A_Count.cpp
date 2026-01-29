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

    string s;
    cin >> s;
    int res = 0;
    for (auto a : s)
    {
        if (a == 'i' || a == 'j')
            res++;
    }
    cout << res << endl;

    return 0;
}
