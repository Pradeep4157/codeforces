#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> dp;
    for (auto a : arr)
    {
        auto it = lower_bound(dp.begin(), dp.end(), a);
        if (it == dp.end())
        {
            dp.push_back(a);
        }
        else
        {
            *it = a;
        }
    }
    cout << dp.size() << endl;
    return 0;
}
