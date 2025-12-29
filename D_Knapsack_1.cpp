#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    sum of the weights that i take <=w..

    and then i need to return the max value sum..

    if sum of weights at the end <=w then return 0

    else return INT_MIN or some small value..

*/
int n, max_weight;
vector<vector<int>> dp;
int recursion(int start, int curr_weight, vector<int> &values, vector<int> &weights)
{
    if (start == n)
    {
        return 0;
    }
    if (dp[start][curr_weight] != -1)
        return dp[start][curr_weight];
    int res = recursion(start + 1, curr_weight, values, weights);
    if (weights[start] + curr_weight <= max_weight)
        res = max(res, values[start] + recursion(start + 1, curr_weight + weights[start], values, weights));
    return dp[start][curr_weight] = res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> max_weight;
    vector<int> values(n), weight(n);
    for (int i = 0; i < n; i++)
    {
        cin >> values[i];
        cin >> weight[i];
    }
    dp.assign(n + 1, vector<int>(max_weight + 1, -1));
    cout << recursion(0, 0, weight, values) << endl;

    return 0;
}
