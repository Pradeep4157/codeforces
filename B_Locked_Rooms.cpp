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
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int left = -1, right = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i])
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
        cout << 0 << endl;
        return 0;
    }
    cout << right - left << endl;
    return 0;
}
