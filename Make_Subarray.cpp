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
        string s;
        cin >> s;
        int first = -1, end = -1;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '1')
            {
                if (first == -1)
                    first = i;
                end = i;
            }
        }
        if (first == -1)
        {
            cout << 0 << endl;
            continue;
        }
        int res = 0;
        for (int i = first; i < end; i++)
        {
            if (s[i] == '0')
                res++;
        }
        cout << res << endl;
    }
    return 0;
}
