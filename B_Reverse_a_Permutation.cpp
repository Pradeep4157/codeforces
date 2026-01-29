#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    4 1 2 3

    4 3 2 1

    so for any index if the current ele is max till

    now then continue

    else reverse from this tell that ele..

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
        vector<int> res = arr;
        sort(res.rbegin(), res.rend());
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]] = i;
        }
        int left = -1, right = -1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != res[i])
            {
                left = i;
                right = mp[res[i]];
                break;
            }
        }
        if (left != -1)
        {

            while (left < right)
            {
                swap(arr[left], arr[right]);
                left++;
                right--;
            }
        }
        for (auto a : arr)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
