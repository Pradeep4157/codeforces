#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so  2 of them should be in same row

    and 2 of them should be in same col..

    so dp of every row where there is 0 it would be no of 0's in row - 1..

    and then dp2 will be for a 0 in the same col it will go above and below and add if that is 0 add dp of that to res..




*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<char>> arr(n, vector<char>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
        vector<vector<int>> dp(n, vector<int>(n));
        // i dont think we need another dp because that res will be added to overall res..
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            int curr = 0;
            for (int j = 0; j < n; j++)
            {
                curr += ((arr[i][j] == 'o') ? 1 : 0);
            }
            for (int j = 0; j < n; j++)
            {
                if (arr[i][j] == 'o')
                {
                    dp[i][j] = curr - 1;
                }
            }
        }

        for (int j = 0; j < n; j++)
        {
            // for this row find all the contri's..
            int curr = 0;
            for (int i = 0; i < n; i++)
            {

                if (arr[i][j] == 'o')
                {
                    curr += dp[i][j];
                }
            }
            for (int i = 0; i < n; i++)
            {
                // if this is a o then we can combine it with all the o's  in this row..
                if (arr[i][j] == 'o')
                {
                    res += (curr - dp[i][j]);
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
