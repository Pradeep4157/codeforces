#include <bits/stdc++.h>
#define int long long
using namespace std;
pair<bool, pair<int, int>> possible(int median, int k, vector<int> &arr)
{
    int n = arr.size();
    vector<int> b(n), prefix(n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < median)
            b[i] = -1;
        else
            b[i] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        prefix[i] = b[i];
        if (i)
            prefix[i] += prefix[i - 1];
    }
    /*if (median == 3)
        for (auto a : prefix)
            cout << a << " ";
    cout << endl;
    */
    bool ok = false;
    int left = -1, right = -1;
    int remove = 0;
    for (int i = k - 1; i < n; i++)
    {
        if (i != k - 1)
        {
            if (remove == 0)
            {
                if (prefix[i - k] < 0)
                {
                    remove = i - k + 1;
                }
            }
            else
            {
                if (prefix[i - k] < prefix[remove - 1])
                {
                    remove = i - k + 1;
                }
            }
        }
        int curr = prefix[i];
        if (remove != 0)
            curr -= prefix[remove - 1];
        if (curr >= 0)
        {
            ok = true;
            left = remove;
            right = i;
            break;
        }
        // deciding the window size
    }

    if (ok)
        return {true, {left, right}};
    else
        return {false, {-1, -1}};
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        int left = 1, right = n;
        int res = 0, l = -1, r = -1;
        while (left <= right)
        {
            int mid = (left + right) / 2;
            auto ans = possible(mid, k, arr);
            if (ans.first == true)
            {
                res = mid;
                l = ans.second.first;
                r = ans.second.second;
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        cout << res << " " << l + 1 << " " << r + 1 << endl;
    }
    return 0;
}
