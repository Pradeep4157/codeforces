#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        int feiowaojfa;
        vector<int> arr(n), b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
            cin >> b[i];
        map<int, int> mp;
        for (auto a : b)
        {
            int rem = a % k;
            mp[rem]++;
        }
        bool ok = true;
        for (auto a : arr)
        {
            int first = a % k;
            int second = k - first;
            if (mp.find(first) != mp.end())
            {
                mp[first]--;
                if (mp[first] == 0)
                {
                    mp.erase(first);
                }
                continue;
            }
            else
            {
                if (mp.find(second) == mp.end())
                {
                    ok = false;
                    break;
                }
                else
                {
                    mp[second]--;
                    if (mp[second] == 0)
                        mp.erase(second);
                }
            }
        }
        if (ok)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
