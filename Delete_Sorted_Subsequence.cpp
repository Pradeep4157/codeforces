#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so no matter what happens at every index number of zeroes >= number of ones ..

        and at the end number of zeroes == number of ones ..

            so at max 2 operations req...
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
        int oc = 0, zc = 0;
        bool onefound = 0, zerofound = 0;
        for (auto a : s)
        {
            if (a == '1')
            {
                if (zc <= oc)
                {
                    onefound = 1;
                }
                else
                {
                    oc++;
                }
            }
            else
            {
                zc++;
            }
        }
        if (zc != oc)
            zerofound = 1;
        int res = 0;
        if (zerofound)
            res++;
        if (onefound)
            res++;
        cout << res << endl;
    }
    return 0;
}
