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
        bool twosix = false, twofive = false;
        for (int i = 0; i < n - 3; i++)
        {
            if (s[i] == '2' && s[i + 1] == '0' && s[i + 2] == '2')
            {
                if (s[i + 3] == '5')
                    twofive = 1;
                else if (s[i + 3] == '6')
                    twosix = 1;
            }
        }
        if (twosix)
        {
            cout << 0 << endl;
        }
        else
        {
            if (twofive == false)
                cout << 0 << endl;
            else
                cout << 1 << endl;
        }
    }
    return 0;
}
