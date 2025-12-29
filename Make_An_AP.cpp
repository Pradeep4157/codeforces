#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    arr is  inc. strictly..

    convert it to AP..

    so some ele we select and insert it into the arrr..


    min op to make it AP..

    always poss..

    diff must be same..

    if only 1 diff then 0..

    if there are diff diffs then we will select the min of

    the diffs and make all rem diffs equal to that..


*/

long long gcdArray(vector<long long> &arr)
{
    long long ans = arr[0];
    for (int i = 1; i < arr.size(); i++)
    {
        ans = __gcd(ans, arr[i]);
        if (ans == 1)
            break; // early exit
    }
    return ans;
}
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
        set<int> st;
        int min_diff = LLONG_MAX;
        for (int i = 0; i < n - 1; i++)
        {
            int curr_diff = arr[i + 1] - arr[i];
            st.insert(curr_diff);
        }
        vector<int> temp(st.begin(), st.end());

        min_diff = gcdArray(temp);
        int res = 0;
        bool ok = 1;
        for (int i = 0; i < n - 1; i++)
        {
            int curr_diff = arr[i + 1] - arr[i];
            int ele = (curr_diff / min_diff) - 1;
            if (curr_diff % min_diff)
            {
                ok = false;
                break;
            }
            res += ele;
        }

        if (ok == false)
        {
            // then i  will have to make all diffs 1.
            int ans = 0;
            for (int i = 0; i < n - 1; i++)
            {
                int curr_diff = arr[i + 1] - arr[i] - 1;
                ans += curr_diff;
            }
            cout << ans << endl;
        }
        else
            cout << res << endl;
    }
    return 0;
}
