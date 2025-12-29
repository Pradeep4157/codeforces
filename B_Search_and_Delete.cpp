#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < m; i++)
    {
        int ele;
        cin >> ele;

        mp[ele]++;
    }
    for (auto a : arr)
    {
        if (mp.find(a) == mp.end())
            cout << a << " ";
        else
        {
            mp[a]--;
            if (mp[a] == 0)
                mp.erase(a);
        }
    }
    cout << endl;
    return 0;
}
