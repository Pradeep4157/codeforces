#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
        when mex is lesser than k then even after replacing the values might be


*/
int findMex(const vector<int> &v)
{
    unordered_set<int> s(v.begin(), v.end());
    int mex = 0;
    while (s.count(mex))
    {
        mex++;
    }
    return mex;
}
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int mex = findMex(arr);
        if (mex == k)
        {
            cout << 0 << endl;
        }
        else if (mex < k)
        {
            int res = 0;
            map<int, int> mp;
            for (auto a : arr)
            {
                mp[a]++;
            }
            for (int i = 0; i < k; i++)
            {
                if (mp.find(i) == mp.end())
                    res++;
            }
            cout << max(res, mp[k]) << endl;
        }
        else
        {
            // we need to remove some element >=mex

            int res = 0;
            for (auto a : arr)
            {
                if (a == k)
                    res++;
            }
            cout << res << endl;
        }
    }
    return 0;
}
