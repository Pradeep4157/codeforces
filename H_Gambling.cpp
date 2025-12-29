#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

        so we can keep map of indexes and apply dp for each arr[i]

        but how will the dp go ?

        while travelling in the indexes array for each index first i will simply push 2, then if we take dp
        of prev then payment which i will have to do is dp[prev]/2^(index[i]-index[i-1]-1)*2
        if this is better the current dp, then dp[i]=dp[prev]/2^(index[i]-index[i-1]-1)*2


        do i need to  calculate 2^ difference in their indexes ?
            because i can get 2 as result why would i every try to go below that

            so now i have some numerator x,


        Instead of all of this dp[0] should not be the whole number instead it should be the power of 2 like what is the power of 2


*/

signed main()
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
        map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[arr[i]].push_back(i);
        }
        int ele = -1;
        int l = -1;
        int r = -1;
        int maxres = INT_MIN;
        for (auto a : mp)
        {
            vector<vector<int>> dp;
            vector<int> &indexes = a.second;
            int size = indexes.size();
            dp.push_back({1, indexes[0], indexes[0]});
            for (int i = 1; i < size; i++)
            {
                int best = 1;
                int currleft = indexes[i];
                int currright = indexes[i];
                int exp = indexes[i] - indexes[i - 1] - 1;

                int best2 = (dp.back()[0] + 1) - exp;
                if (best2 > best)
                {
                    best = best2;
                    currleft = dp.back()[1];
                    currright = indexes[i];
                }
                dp.push_back({best, currleft, currright});
            }
            int currbest = dp[0][0];
            int left = dp[0][1];
            int right = dp[0][2];
            for (auto a : dp)
            {
                if (a[0] > currbest)
                {
                    currbest = a[0];
                    left = a[1];
                    right = a[2];
                }
            }
            if (currbest > maxres)
            {
                maxres = currbest;
                l = left;
                r = right;
                ele = a.first;
            }
        }
        cout << ele << " " << l + 1 << " " << r + 1 << endl;
    }
    return 0;
}
