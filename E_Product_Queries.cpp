#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    for all the i's we will store the factorization of that number..

    and then among all the factors we will see in the dp

    table the min req to make the two that make up this..


    since we are going from small to big it should work..

*/
vector<vector<pair<int, int>>> find_factors(int limit)
{
    vector<vector<pair<int, int>>> factors(limit + 1);
    for (int i = 1; i <= limit; i++)
    {
        for (int j = i; j <= limit; j += i)
        {
            factors[j].push_back({i, j / i});
        }
    }
    return factors;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        vector<vector<pair<int, int>>> factors;
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int maxi = *max_element(arr.begin(), arr.end());
        maxi = max(maxi, n + 1);
        vector<int> dp(maxi + 1, -1);
        for (int i = 0; i < n; i++)
        {
            dp[arr[i]] = 1;
        }
        vector<vector<pair<int, int>>> all_factors = find_factors(maxi + 1);

        for (int i = 1; i <= n; i++)
        {
            vector<pair<int, int>> curr_factors = all_factors[i];
            int min_req = LLONG_MAX;
            for (auto a : curr_factors)
            {
                int first = a.first;
                int second = a.second;

                if (dp[first] != -1 && dp[second] != -1)
                {

                    min_req = min(min_req, dp[first] + dp[second]);
                }
            }
            if (min_req != LLONG_MAX)
            {
                if (dp[i] == -1)
                {
                    dp[i] = min_req;
                }
                else
                    dp[i] = min(dp[i], min_req);
            }
            cout << dp[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
