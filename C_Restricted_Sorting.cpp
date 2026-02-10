#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    if already sorted return -1..

    else the min k is min difference in the swapped elements

    one more thing can be done is that we use a dummy number

    to swap with every other number and at the end we will put

    it in its place..

    this dummy element will mostly be the min / max element in the array..



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
        {
            cin >> arr[i];
        }
        vector<int> temp = arr;
        sort(temp.begin(), temp.end());
        bool sorted = 1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != temp[i])
            {
                sorted = false;
                break;
            }
        }
        if (sorted)
        {
            cout << -1 << endl;
            continue;
        }
        int min_ele = temp[0];
        int max_ele = temp[n - 1];
        int res = LLONG_MAX;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != temp[i])
            {
                // for mini..
                int first = abs(arr[i] - min_ele);
                int second = abs(arr[i] - max_ele);
                int curr = max(first, second);
                res = min(res, curr);
            }
        }

        cout << (res) << endl;
    }
    return 0;
}
