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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int zeroes = 0, ones = 0;
        for (auto a : s)
        {
            if (a == '0')
                zeroes++;
            else
                ones++;
        }
        zeroes = max(zeroes, ones);
        int res = zeroes - n / 2;
        if (k < res)
        {
            cout << "NO" << endl;
            continue;
        }
        k -= res;
        if (k & 1)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
