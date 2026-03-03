#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so we can swap a bullet or in short we put a necessary bullet ahead..

    after we use all it takes k seconds..

    so it will be something like all + k + all + k + all + k .. some bullets..

    so this first part is const to optimize this second part we swap a bullet..

    first = h / sum of array..

    time = first*n + first*k

    now we have rem = h % sum

    here we see how if any swap or no swap helps..


    when we are swapping we expect it to end at i - 1 if we swap

    so prefix will do..

*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, h, k;
        cin >> n >> h >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int sum = accumulate(arr.begin(), arr.end(), 0LL);
        int f = h / sum;
        int rem = h % sum;

        int first = (f * n);
        if (f)
            first += (f - 1) * k;

        int second = 0;

        if (rem)
        {

            second = 0;
            if (f)
                first += k;
            vector<int> prefix(n, 0);
            for (int i = 0; i < n; i++)
            {
                prefix[i] = arr[i];
                if (i)
                    prefix[i] += prefix[i - 1];
            }
            vector<pair<int, int>> dp(n);
            for (int i = 0; i < n; i++)
            {
                dp[i].first = arr[i];
                if (i)
                    dp[i].first = min(dp[i].first, dp[i - 1].first);
            }
            for (int i = n - 1; i >= 0; i--)
            {
                dp[i].second = arr[i];
                if (i < n - 1)
                    dp[i].second = max(dp[i].second, dp[i + 1].second);
            }

            for (int i = 0; i < n; i++)
            {
                second++;
                int c_sum = prefix[i];
                if (c_sum >= rem)
                    break;
                if (i < n - 1)
                {
                    c_sum -= dp[i].first;
                    c_sum += dp[i + 1].second;
                }
                if (c_sum >= rem)
                    break;
            }
        }

        cout << (first + second) << endl;
    }
    return 0;
}
