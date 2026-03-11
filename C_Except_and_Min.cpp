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
    int t = 1;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> arr(n);

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        multiset<int> ms;
        for (auto a : arr)
        {
            ms.insert(a);
        }
        while (q--)
        {
            int k;
            cin >> k;
            vector<int> curr(k);
            for (int i = 0; i < k; i++)
            {
                cin >> curr[i];
                curr[i] = arr[curr[i] - 1];
                auto it = ms.lower_bound(curr[i]);
                if (it != ms.end())
                {
                    ms.erase(it);
                }
            }
            cout << (*ms.begin()) << endl;
            for (int i = 0; i < k; i++)
            {
                ms.insert(curr[i]);
            }
        }
    }
    return 0;
}
