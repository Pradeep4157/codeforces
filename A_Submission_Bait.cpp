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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        unordered_map<int, int> mp;
        for (auto a : arr)
            mp[a]++;
        bool possible = false;
        for (auto a : mp)
        {
            if (a.second & 1)
            {
                possible = 1;
                break;
            }
        }
        if (possible)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}
