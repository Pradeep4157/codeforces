#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
    OBSERVATIONS:

    WE ARE TRYING TO MAXIMIZE SAVINGS:
        ANS=SUM[ARR]-DP[0]

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
        {
            cin >> arr[i];
        }
        vector<int> dp(n + 1, 0);
        int index = n;
        int sum = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            dp[i] = dp[i + 1];

            if (arr[i + 1] <= (i + 1))
            {
                // next will be destroyed
                if (index == n)
                {
                    // all the elements will get destroyed by falling continously
                    dp[i] = sum;
                }
                else
                {
                    // the closest index where arr[i]>1 will remain
                    //+1 because the fall damage will cause 1 extra save to the save that index did already
                    dp[i] = max(dp[i], dp[index] + 1);
                }
            }
            else
            {
                // if next ele is greater than i+1 then we are saving i+1 damage + the savings done by i+1?
                dp[i] = max(dp[i], (i + 1) + dp[i + 2]);
            }
            sum += arr[i];
            if (arr[i + 1] > 1)
                index = i + 1;
        }

        cout << sum - dp[0] << endl;
    }
    return 0;
}
