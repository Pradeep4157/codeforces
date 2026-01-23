#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
int find(vector<int> &arr)
{
    int res = 0;
    int maxi = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
        res += maxi;
    }
    return res;
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
        int res = find(arr);
        for (int right = 1; right < n; right++)
        {
            for (int left = 0; left < right; left++)
            {
                swap(arr[left], arr[right]);
                res = max(res, find(arr));
                swap(arr[left], arr[right]);
            }
        }
        cout << res << endl;
    }
    return 0;
}
