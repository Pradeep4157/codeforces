#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll count = 0;
        int n = s.size();
        int i = n - 1;
        while (i >= 0)
        {
            if (s[i] != '0')
                break;
            i--;
        }
        int res = 0;
        res += (n - i - 1);
        i--;
        while (i >= 0)
        {
            if (s[i] != '0')
                res++;
            i--;
        }
        cout << res << endl;
    }

    return 0;
}