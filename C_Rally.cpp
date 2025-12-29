#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    SINCE X AND N ARE REALLY SMALL WE CAN CHECK FOR EVERY X WHAT IS THE DISTANCE AND RETURN THE MINIMUM


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int res = LLONG_MAX;
    for (int i = 1; i <= 100; i++)
    {
        int curr = 0;
        for (int j = 0; j < n; j++)
        {
            curr += ((i - arr[j]) * (i - arr[j]));
        }
        res = min(res, curr);
    }
    cout << res << endl;
    return 0;
}
