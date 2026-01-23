#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so max diff between any two points should be min..

    we bs on diff..

    and if a mid is poss:
        res = mid
        right = mid -1
    else :
        left = mid + 1

    in the possible function i need to check whether i can reduce this dist between arr[i],arr[i+1] to <= mid..

    so if any dist > mid :
        i will place these things to red it to mid..




*/
int n, k;
bool possible(int max_gap, vector<int> &arr)
{
    int k_left = k;
    for (int i = 0; i < n - 1; i++)
    {
        int curr_dist = arr[i + 1] - arr[i];
        if (curr_dist > max_gap)
        {
            // this is only where we place these points..
            if (k_left <= 0)
            {
                return false;
            }
            // now we have some but are they enough ..
            int req = curr_dist / max_gap;
            if ((curr_dist % max_gap) == 0)
            {
                req--; // because there is already a point present..
            }
            if (req > k_left)
                return false;
            k_left -= req;
        }
    }
    // we have filled all larger gaps..
    return true;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int left = 1, right = 0;
        for (int i = 0; i < n - 1; i++)
        {
            right = max(right, arr[i + 1] - arr[i]);
        }
        int res = right;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            if (possible(mid, arr))
            {
                res = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        cout << res << endl;
    }
    return 0;
}
