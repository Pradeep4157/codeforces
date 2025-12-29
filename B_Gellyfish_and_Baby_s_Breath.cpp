#include <bits/stdc++.h>
using namespace std;

const int mod = int(998244353);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int64_t t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n), b(n);

        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        vector<int> dp(n, 0);
        dp[0] = 1;
        for (int i = 1; i < n; i++)
            dp[i] = (dp[i - 1] * 2) % mod;

        vector<int> res(n);
        res[0] = (dp[arr[0]] + dp[b[0]]) % mod;

        int firstmax = 0, secondmax = 0;

        for (int i = 1; i < n; i++)
        {
            if (arr[i] > arr[firstmax])
                firstmax = i;
            if (b[i] > b[secondmax])
                secondmax = i;

            if (arr[firstmax] == b[secondmax])
            {
                if (b[i - firstmax] >= arr[i - secondmax])
                {

                    int val1 = (dp[arr[firstmax]] + dp[b[i - firstmax]]) % mod;
                    res[i] = val1;
                }
                else
                {
                    int val2 = (dp[b[secondmax]] + dp[arr[i - secondmax]]) % mod;
                    res[i] = val2;
                }
            }
            else if (arr[firstmax] > b[secondmax])
            {
                int val1 = (dp[arr[firstmax]] + dp[b[i - firstmax]]) % mod;
                res[i] = val1;
            }
            else
            {
                int val2 = (dp[b[secondmax]] + (dp[arr[i - secondmax]])) % mod;

                res[i] = val2;
            }
        }
        for (auto a : res)
            cout << a << " ";
        cout << "\n";
    }

    return 0;
}
