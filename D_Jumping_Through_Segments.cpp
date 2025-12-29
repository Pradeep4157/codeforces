#include <bits/stdc++.h>
#define int long long
using namespace std;
int n;
bool xinside(int minxi, int maxi, int left, int right)
{
    return (minxi >= left && maxi <= right);
}
bool segmentinsidex(int minxi, int maxi, int left, int right)
{
    return (left >= minxi && right <= maxi);
}
bool overlap(int minxi, int maxi, int left, int right)
{
    return ((minxi >= left && minxi <= right) || (maxi >= left && maxi <= right));
}
bool rightt(int minxi, int maxi, int left, int right)
{
    return (maxi <= left);
}
bool possible(int k, vector<pair<int, int>> &arr)
{
    int minxi = 0, maxi = 0;
    for (int i = 0; i < n; i++)
    {
        int left = arr[i].first;
        int right = arr[i].second;
        if (left == minxi && right == maxi)
            continue;
        if (xinside(minxi, maxi, left, right))
        {
            // never false here
            // increase the segment size
            minxi -= k;
            minxi = max(minxi, left);
            maxi += k;
            maxi = min(maxi, right);
        }
        else if (segmentinsidex(minxi, maxi, left, right))
        {
            // never false
            minxi = left;
            maxi = right;
        }
        // do i need to check overlapping
        else if (overlap(minxi, maxi, left, right))
        {
            // never false
            if (minxi >= left && minxi <= right)
            {
                maxi = right;
                minxi -= k;
                minxi = max(minxi, left);
            }
            else
            {
                minxi = left;
                maxi += k;
                maxi = min(maxi, right);
            }
        }
        // no contact
        else
        {
            // false condition
            if (rightt(minxi, maxi, left, right))
            {
                // the current segment is on the right side
                if ((maxi + k) < left)
                    return false;
                minxi = left;
                maxi += k;
                maxi = min(maxi, right);
            }
            else
            {
                // the current segment is on the left side
                if ((minxi - k) > right)
                    return false;
                maxi = right;
                minxi -= k;
                minxi = max(minxi, left);
            }
        }
    }
    return true;
}
int_fast32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].first >> arr[i].second;
        }
        int low = 0, high = 1e9;
        int res = high;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (possible(mid, arr))
            {
                high = mid - 1;
                res = mid;
            }
            else
                low = mid + 1;
        }
        cout << res << endl;
    }
    return 0;
}
