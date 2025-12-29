#include <bits/stdc++.h>
#define int long long
using namespace std;

int_fast32_t main()
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
        int res = 0;
        for (auto a : s)
        {
            if (a == '0')
                res++;
            else
                res += n - 1;
        }
        cout << res << endl;
    }
    return 0;
}
