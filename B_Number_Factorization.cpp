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
        int n;
        cin >> n;
        unordered_map<int, int> mp;
        for (int i = 2; i * i <= n; i++)
        {
            int count = 0;
            while (n % i == 0)
            {
                count++;
                n /= i;
                if (mp.find(count) == mp.end())
                {
                    mp[count] = i;
                }
                else
                    mp[count] *= i;
            }
        }
        if (n != 1)
        {
            if (!mp.count(1))
                mp[1] = n;
            else
                mp[1] *= n;
        }
        int res = 0;
        for (auto a : mp)
        {
            res += a.second;
        }
        cout << res << endl;
    }
    return 0;
}
