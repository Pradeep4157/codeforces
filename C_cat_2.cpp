#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    some x concatenated == some y concatenated..

    so removal of these things..




*/
int factorial(int n)
{
    int result = 1;
    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }
    return result;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> arr(n);
    map<string, int> mp;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        string curr = arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            string temp = arr[i] + arr[j];
            mp[temp]++;
        }
    }
    int res = mp.size();
    cout << res << endl;

    return 0;
}
