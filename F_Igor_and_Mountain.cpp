#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m, d;
int mod = 998244353;

bool distance(int currx, int curry, int prevx, int prevy, int d)
{
    int dist = (currx - prevx) * (currx - prevx);
    dist += (prevy - curry) * (prevy - curry);
    return (dist <= d);
}
vector<vector<int>> dp;
int recursion(int prevx, int prevy, int d, vector<vector<char>> &arr)
{
    int currx = prevx - 1;
    if (currx < 0)
        return 1;
    if (dp[prevx][prevy] != -1)
        return dp[prevx][prevy];
    int res = 0;
    for (int curry = 0; curry < m; curry++)
    {
        if (distance(prevx, prevy, currx, curry, d) && arr[currx][curry] == 'X')
        {
            int currres = recursion(currx, curry, d, arr);
            int secondres = 0;
            for (int k = curry + 1; k < m; k++)
            {
                if (!distance(currx, curry, currx, k, d))
                    break;
                if (arr[currx][k] == 'X')
                    secondres = (secondres + recursion(currx, k, d, arr));
            }
            for (int k = curry - 1; k >= 0; k--)
            {
                if (!distance(currx, curry, currx, k, d))
                    break;
                if (arr[currx][k] == 'X')
                    secondres = (secondres + recursion(currx, k, d, arr)) % mod;
            }
            currres = (currres + secondres) % mod;
            res = (res + currres) % mod;
        }
    }

    return dp[prevx][prevy] = res;
}
int_fast32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m >> d;
        d = d * d;
        dp = vector<vector<int>>(n, vector<int>(m, -1));

        vector<vector<char>> arr(n, vector<char>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        }
        int res = 0;
        for (int j = 0; j < m; j++)
        {
            if (arr[n - 1][j] == 'X')
            {
                int currres = recursion(n - 1, j, d, arr);
                int secondres = 0;
                for (int k = j + 1; k < m; k++)
                {
                    if (!distance(n - 1, j, n - 1, k, d))
                        break;
                    if (arr[n - 1][k] == 'X')
                    {

                        secondres = (secondres + recursion(n - 1, k, d, arr)) % mod;
                    }
                }
                for (int k = j - 1; k >= 0; k--)
                {
                    if (!distance(n - 1, j, n - 1, k, d))
                        break;
                    if (arr[n - 1][k] == 'X')
                    {
                        secondres = (secondres + recursion(n - 1, k, d, arr)) % mod;
                    }
                }
                currres = (currres + secondres) % mod;
                res = (res + currres) % mod;
            }
        }
        cout << res << endl;
    }
    return 0;
}
