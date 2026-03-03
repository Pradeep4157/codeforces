#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    so for each arr[i]..

    all the values from 1...arr[i] - 1

    should be there..

    maybe all the ones can be the start

    point..

    some would not workout

    so just remove them..

    and that should be the answer..

    also end points matter..

    so min ans is the no of ones that are present in the array..

    now to these ones how many end points can i merge..

    dp thing..

    for every arr[i] == 2 i can merge it will all the ways that arr[1] is possible till now

    that is basically the no of ones that i have seen till now.

    now for arr[i] == 3 it is nothing but the no of ways i have found dp[2] till now..

    to that i will just merge this


    for every r we need to find possible ls

    such that l..r everything is good..

    so when an arr[i] comes such that there is no dp[i - 1] then we cannot take

    l before this for any r >= i..

    because this ele will make that arr bad..

    so its like a 2 pointer..

    we will have to move left till this arr[i] if dp[i - 1] == 0..

    else it is dp[i - 1]


    if arr[i] is 1..

    then it can for 1 sized with itself

    also it can connect with all 1's before this..

    so if arr[i] is 1..

    then res += dp[1] + 1

    also dp[1]++

    for the rest elements...

    we can only connect this r to the l's that dp[i - 1] has found..

    that is res += dp[i - 1]..

    if dp[i - 1] == 0 :

        then move left till  here and make all dpi's  === 0

    the wrong thing is that just blindly adding dp[arr[i] - 1] is not correct..

    because we might be able to connect that element with this but we cannot connect some max ele that is in between..

    so it is maybe dp[max_ele]

    that is also not correct because that max ele might have come very early and now

    we can merge with some l's that are beyond that max ele..

    bf is that we have some left

    we iterate from i..that left and if that window is ok then res++..

    maybe it only depends on arr[i - 1]..

    if that ele is == arr[i] :

        then the no of subarrays that arr[i - 1] has found we can just add this ele at the end..

        so  res += dp[i - 1]..

    else if arr[i - 1] >  arr[i] :

        then it's still the same whatever dp[i - 1] is there i can literally add this element at the end..

        and it wont break anything..

    else arr[i - 1] < arr[i] :

        here.. we cannot blindly merge this arr[i] to wherever arr[i - 1] has got ..

        because arr[i - 1] doesnt require a lot of things..

        here i will need something else :

            the no of ways dp[i - 1] is there..

            those many no of ways i can merge it else :

                dp[i] = 0 that should do it..




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
        int maxi = *max_element(arr.begin(), arr.end()) + 1;
        maxi = max(maxi, n + 1);
        vector<int> dp(maxi, 0);
        int res = 0;
        int left = 0;
        int ans = 0;
        vector<int> DP(maxi, 0);
        dp[0] = ((arr[0] == 1) ? 1 : 0);
        ans += dp[0];
        dp[arr[0]] = dp[0];

        for (int i = 1; i < n; i++)
        {
            int ele = arr[i];

            if (arr[i] <= arr[i - 1])
            {
                // then it is just the no of ways arr[i - 1] has found..

                dp[i] = dp[i - 1];

                if (arr[i] == 1)
                    dp[i]++;
                // but if arr[i] is 1.. then i can make an {l,r} of this only..
            }
            else
            {
                // now for this it is no of ways DP[arr[i] - 1] has found..
                if (DP[ele - 1] == 0)
                {

                    while (left <= i)
                    {
                        DP[arr[left]] = 0;
                        left++;
                    }
                }
                else
                {
                    DP[ele] = DP[ele - 1];
                    dp[i] = DP[ele];
                }
            }
            DP[ele] = dp[i];
            ans += dp[i];
        }
        for (auto a : dp)
            cout << a << " ";
        cout << endl;
        cout << ans << endl;
        for (int i = 0; i < dp.size(); i++)
        {
            DP[i] = 0;
            dp[i] = 0;
        }
        left = 0;
        for (int i = 0; i < n; i++)
        {
            int ele = arr[i];
            int curr = 0;
            if (arr[i] == 1)
            {
                res++;
                curr++;
                res += dp[arr[i]];
                curr += dp[arr[i]];
                dp[arr[i]]++;
            }
            else
            {
                if (dp[ele - 1] == 0)
                {
                    // then move left till this index..
                    while (left <= i)
                    {
                        dp[arr[left]] = 0;
                        left++;
                    }
                }
                else
                {
                    res += dp[ele - 1];
                    curr += dp[ele - 1];
                    dp[ele] = dp[ele - 1];
                }
            }
            DP[i] = curr;
        }
        for (auto a : DP)
            cout << a << " ";
        cout << endl;
        cout << res << endl;
    }
    return 0;
}
