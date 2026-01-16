#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    0 -7 7 0

    so every cell can contri its pos effect on only the right or down cell

    and in return whatever it has if its -ve then it will return that first and

    second comp is min of right and down which will be >= 0..

    if this is monster :

        whatever's min of right and down to that add this abs part and return

    else if its some +ve thing :
        whatever's min of right and down to that subtract this part and return max of

        0, whatever's remaining..


*/
int n, m;
vector<vector<int>> dp;
bool isvalid(int i, int j)
{
    return (i >= 0 && j >= 0 && i < n && j < m);
}
int recursion(int i, int j, vector<vector<int>> &arr)
{
    int second_comp = LLONG_MAX;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (isvalid(i + 1, j))
    {
        second_comp = recursion(i + 1, j, arr);
    }
    if (isvalid(i, j + 1))
    {
        second_comp = min(second_comp, recursion(i, j + 1, arr));
    }
    if (second_comp == LLONG_MAX)
    {
        // then there's no right and down..
        second_comp = 0;
    }
    int first_comp = arr[i][j];
    int res = 0;
    if (first_comp < 0)
    {
        // this is just bad thing and would increase the need of good..
        res = second_comp + abs(first_comp);
    }
    else
    {
        // this can reduce the good req..
        res = second_comp - first_comp;
        res = max(res, 0LL);
    }
    return dp[i][j] = res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        dp.assign(n, vector<int>(m, -1));
        vector<vector<int>> arr(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                cin >> arr[i][j];
        }
        cout << ((recursion(0, 0, arr)) + 1) << endl;
    }
    return 0;
}
