#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        vector<ll> a;
        for (auto &x : s)
        {
            a.push_back(x - '0' - 1);
        }

        unordered_map<ll, ll> mp;
        ll sum = 0, cnt = 0;
        mp[0] = 1;

        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            if (mp.count(sum))
            {
                cnt += mp[sum];
                cout << i << "::" << sum << ":::" << mp[sum] << endl;
            }

            mp[sum]++;
        }

        cout << cnt << "\n";
    }
    return 0;
}