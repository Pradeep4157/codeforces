#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    k--;
    int left = -1;
    int right = -1;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            if (left == -1)
            {
                left = i;
            }
            right = i;
        }
    }
    if (left == -1)
    {
        cout << res << endl;
        return 0;
    }
    // go left
    for (int i = k; i >= left; i--)
    {
        if (arr[i] == 0)
            res++;
        else
            res += 2;
    }
    for (int i = k + 1; i <= right; i++)
    {
        if (arr[i] == 0)
            res++;
        else
            res += 2;
    }
    cout << res << endl;
    return 0;
}
