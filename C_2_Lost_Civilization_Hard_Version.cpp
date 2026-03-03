#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    1 2 3 4 5

    1..n for all these subarrays we need only 1 = 5

    for l = 2 :
        res = 9

    for the subarray that is continued that is l..r that we found in the prev question

    what is def :

        for the l..r
        1 + 1 + 1... how many times.

        size of subarray times..

        now for r + 1..n

        we would have found r + 1..n

{5},{5,8}
{1,1}
so there should be two things first is the sum

that it has seen and second is the no of component

that it has seen when we add l..r to r + 1

then all the components that r + 1 has seen all the components

size increase by 1..

sum + no of components
        1 2 5 8
        {1,2}{5}{8}
        dp[3][0] = 1
        dp[3][1] = 1
        dp[2][0] = 1(size of this subarray) + 1 + 1 = 3
        dp[2][1] = 1 + dp[r + 1] = 1 == 2
        dp[]

    for this segment from l...r though l...r costs 1 each but it doesnt mean that all mid where mid > l and mid < r

    it is going to be the same..

    there are some segments that dont independently count as 1..

    like 2,3,4,4

    {2,3,4,4}, {3,4,4} is valid but {4,4} first takes 1,2 = 3..

    does checking only i + 1 is enough ?

    2,3,4,5,3

    3 -> 1
    5 -> 3

    no its not...

    so we have these valid subarrays now in these subarrays W.K.T for ele at index 0 max is the last index there.

    now for all these other elements in this subarray will the end going to be the <= arr[index] and ..


\

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
        int right = 1;
        int left = 0;
        int size = 1;
        map<int, int> mp;
        while (right < n)
        {
            while (right < n)
            {
                if (arr[right] > arr[right - 1] + 1)
                    break;
                // now it is either less than or equal to prev..
                if (arr[right] <= arr[left])
                    break;
                right++;
            }
            for (int i = left; i < right; i++)
            {
                mp[i] = right - 1;
            }
            if (right == n)
                break;

            size++;
            // now the currnet component is left..right -1..

            left = right;
            right++;
        }
        mp[n - 1] = n - 1;
        // for (auto a : mp)
        // {
        //     cout << a.first << ":" << a.second << endl;
        // }
        vector<pair<int, int>> dp(n);
        dp[n - 1].first = 1;
        dp[n - 1].second = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            // firt find where does this segment end..
            int left = i;
            int right = mp[i];
            if (arr[right + 1])
                int size = right - left + 1;
            dp[i].first += size;
            dp[i].second = 1;
            // now merging with right + 1.
            if (right + 1 < n)
            {
                // then whatever components it has seen we are going to be added in that..
                int second = n - (right + 1);
                int curr = second + dp[right + 1].first;
                dp[i].first += curr;
            }
        }
        for (auto a : dp)
        {
            cout << a.first << "::" << a.second << endl;
        }
        int res = 0;
        for (auto a : dp)
            res += a.first;
        cout << res << endl;
    }
    return 0;
}
