#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    ok so there's no dp here at each step we just find the best amoung the right and down and store it and move forward

    lets say that the after the worse something really smaller char  appears appears it doesnt matter because it already became
    bigger than the first one


    but what if both of them are equal ?

    we could go in either direction

    so we will solve it using 2 methods :
        1) dijsktra
        2) dp


    so dijsktra gives TLE :(

    2nd method:
        for an i,j there are only two ways of reaching this cell that is arr[i-1][j] and arr[i][j-1] and before we reach
        this cell we already must have build these two dp's so the answer is basically :
            we will traverse from i=0->n:
                                    j=0->n:
                                        dp[i][j]=min(dp[i-1][j],dp[i][j-1])+arr[i][j]

            and just return dp[n-1][n-1] at the end





*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<char>> arr(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    }

    vector<vector<string>> dp(n, vector<string>(n));
    dp[0][0] = string("") + arr[0][0]; // because we will have to take arr[0][0] no matter what

    // the first row and first column we dont have any choice we will have to take the prev prefix and add the current char to that

    // first row creation

    for (int j = 1; j < n; j++)
    {
        dp[0][j] = dp[0][j - 1] + arr[0][j];
    }

    // first col creation
    for (int i = 1; i < n; i++)
    {
        dp[i][0] = dp[i - 1][0] + arr[i][0];
    }

    // for remaining cells we have 2 choices

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + arr[i][j];
        }
    }
    cout << dp[n - 1][n - 1] << endl;
    return 0;
}
