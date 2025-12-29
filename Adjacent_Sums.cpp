#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    from a2 onwards we have to make that ai-1 + ai+1  which is impossible

    so there are two ways from i = 0 either we make i 0 and i + 1 and i + 2 equal  and

    but if i + 1 and i + 2 are not there then i + 1 also  becomes 0

    there are 3 possibilities either i make none of first zeroes

    or first as zero

    or first two as zero

    the remaining pattern remains same


    so this is not a greedy question instead this is a dp question

    here the dp goes like this :

    at every i either i  try to make arr[i] == arr[i-1 ] OR arr[i] == arr[i+1]

    cost to make arr[i] == arr[i-1] is abs(arr[i]-arr[i-1]) + prev cost of dp[i-2]

    the thing is that the dp for arr[i]==arr[i+1] this state will be covered when i -> i + 1 and at that point arr[i] making

    equal to arr[i-1] this is the state that will be covered so we dont need to worry about that right now

    only prev index

    so the total cost is abs(arr[i]- arr[i-1]) +  if i -2 exists then + arr[i-2] because we need to make that also as 0
    + if i-3 exists then + dp[i-3]
    that's it !!

    but  what if i choose to make this i as 0 ?

    that would be arr[i] + dp[i-1] ?

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
        vector<int> dp(n);
        dp[0] = arr[0];
        for (int i = 1; i < n; i++)
        {
            // if i choose to make this equal  to arr[i-1]
            int curr = abs(arr[i] - arr[i - 1]);
            // i will also need to  make arr[i-2] as 0
            if (i - 2 >= 0)
                curr += arr[i - 2];
            // cost till i - 3
            if (i - 3 >= 0)
                curr += dp[i - 3];
            // if i choose to make this i as 0
            int curr2 = arr[i];
            if (i - 1 >= 0)
                curr2 += dp[i - 1]; // best cost till i - 1
            dp[i] = min(curr, curr2);
        }
        cout << dp[n - 1] << endl;
    }
}
