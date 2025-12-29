#include <bits/stdc++.h>
#define ll int64_t
using namespace std;
bool possible(int mex, vector<int> &arr, int k)
{
    if (mex == 0)
        return true;

    unordered_set<int> current;
    int count = 0;

    for (int val : arr)
    {
        if (val < mex)
        {
            current.insert(val);
        }

        if (current.size() == mex)
        {
            count++;
            current.clear();
        }
    }

    return count >= k;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int window = n / k;

        int low = 0, high = window;
        int res = 0;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (possible(mid, arr, k))
            {
                res = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        cout << res << endl;
    }
    return 0;
}
