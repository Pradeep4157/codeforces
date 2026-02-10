#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    we know contrast of a..

    some subsequence should make that

    if its possible from 1 ele then i just return 1..

    else if :

        if 2 ele's diff make it then yes..

    ok so all the adj elements that have the same value i am just going to

    take one of them..

    because they dont contri..

    so there are down and up thing we just connect lowest with highest..




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
        int contrast = 0;
        vector<pair<int, int>> subarrays;
        vector<int> new_arr;
        for (int i = 0; i < n; i++)
        {
            if (!new_arr.empty() && new_arr.back() == arr[i])
                continue;
            else
                new_arr.push_back(arr[i]);
        }
        // now all unq..
        arr = new_arr;
        n = arr.size();

        bool inc = false;
        if (arr[0] < arr[1])
        {
            inc = true;
        }
        int right = 0;
        int res = 1;
        while (right < n - 1)
        {
            res++;
            if (inc)
            {
                // now its a inc slope..
                while ((right < n - 1) && arr[right] < arr[right + 1])
                    right++;
                inc = false;
            }
            else
            {
                while (right < n - 1 && arr[right] > arr[right + 1])
                    right++;
                inc = true;
            }
        }
        cout << res << endl;
    }
    return 0;
}
