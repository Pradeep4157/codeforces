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
        int dupn = n;
        int number = 1;
        vector<int> res;
        while (dupn)
        {
            if (dupn & 1)
            {
                res.push_back(number);
            }
            number <<= 1;
            dupn >>= 1;
        }
        if (res.size() == 1)
        {
            cout << 1 << endl;
            cout << n << endl;
            continue;
        }
        sort(res.rbegin(), res.rend());
        vector<int> ans;
        for (auto a : res)
        {
            int curr = n - a;
            ans.push_back(curr);
        }
        ans.push_back(n);
        cout << ans.size() << endl;
        for (auto a : ans)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
