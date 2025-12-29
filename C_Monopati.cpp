#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so there's 2n cells..

    f(l,r) we create a binary grid..

    bij is 1 only if aij is within l,r

    we need to go from top left to bottom right..

    so an aij is valid for what all ..

    it is valid for all i from i to 2n..

    so maybe we just need to find a path from top left

    to bottom right such that the max of that path is as min

    as possible and min found should be as max as possible..

    so for every aij min , max will be

    dp[i][j].first = max(dp[i-1][j].first,dp[i][j-1].first);

    dp[i][j].second=min(dp[i-1][j].second,dp[i][j-1].second);

    will min and max ever cross..

    if i take good from both sides..

    it might cross..

    lets say top is (2,2) left is (1,1) i will take

    (2,1)

    ok maybe since the grid is 2*n

    we will go down only once..

    what if it was just 1d

    we could only come from left.

    that means that the values ranges are fixed..

    atleast for the 1st row..

    for the 2nd row..

    either i get

    so at any i if i choose to go down..

    it will be whatever min , max found so far..

    and suffix of 2nd row..
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
        vector<vector<int>> arr(2, vector<int>(n));
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }

        vector<pair<int, int>> prefix(n); // for 1st row..
        vector<pair<int, int>> suffix(n); // for 2nd row..
        for (int i = 0; i < n; i++)
        {
            prefix[i].first = arr[0][i];
            prefix[i].second = arr[0][i];
            if (i)
                prefix[i].first = min(prefix[i].first, prefix[i - 1].first);
            if (i)
                prefix[i].second = max(prefix[i].second, prefix[i - 1].second);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            suffix[i].first = arr[1][i];
            suffix[i].second = arr[1][i];

            if (i < n - 1)
                suffix[i].first = min(suffix[i].first, suffix[i + 1].first);
            if (i < n - 1)
                suffix[i].second = max(suffix[i].second, suffix[i + 1].second);
            // cout<<suffix[i].first<<":"<<suffix[i].second<<endl;
        }
        // for(auto a:suffix) cout<<a.first<<"--"<<a.second<<endl;
        int res = 0;
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int mini = min(prefix[i].first, suffix[i].first);
            int maxi = max(prefix[i].second, suffix[i].second);
            if (mp.find(mini) == mp.end())
                mp[mini] = maxi;
            else
                mp[mini] = min(mp[mini], maxi);
            int first = mini;
            int second = 2 * n - maxi + 1;
            int curr = (first * second);
            // cout << mini << "::" << maxi << "->" << curr << endl;
        }
        int minisofar = 0;
        for (auto a : mp)
        {
            int mini = a.first;
            int maxi = a.second;
            int curr = 1;

            int first = mini;
            int second = (2 * n - maxi + 1);
            if (minisofar >= first && minisofar <= second)
                continue;
            if (minisofar < mini)
                first -= minisofar;
            else
                second -= minisofar;
            curr = (first * second);
            // curr += (mini - 1);
            // curr += (2 * n - maxi);
            res += curr;
            minisofar = mini;
            // cout << mini << ":" << maxi << "->" << curr << endl;
        }
        cout << res << endl;
    }
    return 0;
}
