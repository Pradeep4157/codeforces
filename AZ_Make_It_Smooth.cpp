#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    so we can select non decreasing subarray and increase all ele by 1 in single op..

    the array will look something like this : inc,inc,inc,inc,inc,dec,inc,inc,inc


    so first store all these increasing subarrays and then add to res the diff between max till now - min of this

    and then make max = max( maxi, maxi of this subarray + diff )

    and move ahead..


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
        vector<pair<int, int>> subarrays;
        int i = 0;
        while (i < n)
        {
            int j = i + 1;
            while (j < n && arr[j] >= arr[j - 1])
                j++;
            j--;
            subarrays.push_back({arr[i], arr[j]});
            i = j + 1;
        }
        int res = 0;
        int size = subarrays.size();
        int mini = subarrays[size - 1].first;
        for (int i = size - 2; i >= 0; i--)
        {
            int curr_mini = subarrays[i].first;
            int curr_maxi = subarrays[i].second;
            int req = curr_maxi - mini;
            res += req;
            mini = curr_mini;
        }
        cout << res << endl;
    }
    return 0;
}
