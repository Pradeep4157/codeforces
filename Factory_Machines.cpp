#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
bool possible(int time, vector<int> &arr, int k)
{
    int res = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int curprod = time / arr[i];
        res += curprod;
        if (res >= k)
            return true;
    }
    return false;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int low = 0, high = LLONG_MAX;
    int res = 1e9;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (possible(mid, arr, k))
        {

            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    cout << res << endl;

    return 0;
}
