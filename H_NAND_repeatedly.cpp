#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    0 + 1 + 0 + 0 + 1


    so maybe we dont need to exaclty traverse the whole

    string from i...n to find what is the res that we get..

    if we think of subarrays..

    what happends in zero subarrays..

        000000
        if current if 1 :

            1111111...

            the res increases by no of zeroes here..

        else if current is 0 :

            1111...

            here also it increase by the no of zeroes in the subarray..

    now what happens in one subarrays :

        11111.....

        if current is 1 :

            010101010

            i.e., every odd index becomes 1 so for this  : n / 2

        if current is 0 :

            1010101010..

            i.e., every even index becomes 1 so for this : (n + 1) / 2


    so maybe we can find dp[i] with the help of dp[i + 1] or maybe we cant..

    dp[n - 1] = 0 if arr[n - 1] is 0 else 1..

    now for all i -> n - 2...0

    if arr[i] is 1 then dp[i] = 1

    also maybe we will store the result for both that what would happend if till this nand is 1 and nand is 0..

    for all dp[i].second == 1

    now dp[i].first means nand till here is zero and dp[i].second means nand till here is 1


    now we imagine if this was 1 then what

    find 1 nand arr[i + 1] whatever it gives store in dp[i].second

    also find 0 nand arr[i + 1] whatever it gives store in dp[i].first

    also arr[i] nand arr[i + 1] whatever it gives add that d[i + 1] to res...


    now move back..

*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> arr;
    for (auto a : s)
    {
        if (a == '0')
            arr.push_back(0);
        else
            arr.push_back(1);
    }
    vector<pair<int, int>> dp(n);
    for (int i = 0; i < n; i++)
    {
        dp[i].second = 1;
    }
    int res = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int curr = 0;
        if (arr[i] == 1)
        {
            curr++;
            if (i + 1 < n)
            {
                // merge with whatever nand u get..
                if (arr[i + 1] == 1)
                    curr += dp[i + 1].first;
                else
                    curr += dp[i + 1].second;
            }
            // now curr for this is done now we try to fill dp for this .
            if (i + 1 < n)
            {
                if (arr[i + 1] == 1)
                {
                    // then merge with first
                    dp[i].second += dp[i + 1].first;
                    dp[i].first += dp[i + 1].second;
                }
                else
                {
                    // it will be 1..
                    dp[i].second += dp[i + 1].second;
                    dp[i].first += dp[i + 1].second;
                }
            }
        }
        else
        {
            if (i + 1 < n)
            {
                if (arr[i + 1] == 1)
                {
                    // then nand is 1..
                    curr += dp[i + 1].second;
                }
                else
                    curr += dp[i + 1].second; // still it will be 1 only..
                // now forming dp..
                // if nand till here is 0..
                if (arr[i + 1] == 1)
                {
                    dp[i].first += dp[i + 1].second; // bcause it bcomes 1..
                    // if nand till here is 1..
                    dp[i].second += dp[i + 1].first;
                }
                else
                {
                    // if this is 0 .. then next is 0 nand becomes 1
                    dp[i].first += dp[i + 1].second;
                    // if till here its 1 .. then next is 0 nand becomes 1..
                    dp[i].second += dp[i + 1].second;
                }
            }
        }

        res += curr;
    }

    cout << res << endl;
}
