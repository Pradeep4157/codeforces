#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    unordered_map<int, int> mp1, mp2;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        mp1[arr[i] + i]++;
        mp2[i - arr[i]]++;
    }
    for (auto a : mp2)
    {
        // cout << a.first << ":" << a.second << endl;
    }
    for (auto a : mp1)
    {
        int count1 = a.second;
        int count2 = mp2[a.first];
        res += (count1 * (count2));
    }
    cout << res << endl;
    return 0;
}
