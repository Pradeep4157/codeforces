#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so the prev peice needs to be either above it or below it..

    dp[i] is going to be cost to make i - 1 row above it or below it..

    and the cost is going to be either at ith index / i - 1 th index / i + 1 th idex..

    cost is index where i want - arr[i - 1] abs of this times no of prev blocks..

    but this might sometimes cause double counting..

    we can only move up now down..

    so ans is min row's above or same or 1 below..

    the min row is not going to move..

    or maybe we can start bfs from all these smallest rows..

    and if the column's dp is more than what is required then update dp[i]

    dp[i] tells how many steps above has that column gone..

    so either i move this one below the side or above or same



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
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> dp(n, LLONG_MAX);
        int mini = *min_element(arr.begin(), arr.end());
        queue<vector<int>> q;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == mini)
            {
                if (i)
                    q.push({i, i - 1});
                if (i + 1 < n)
                    q.push({i, i + 1});
            }
        }
        while (!q.empty())
        {
            int prev = q.front()[0];
            int curr = q.front()[1];
            q.pop();
            int cell_of_prev = arr[prev];
            cell_of_prev += dp[prev];
            
        }
    }
    return 0;
}
