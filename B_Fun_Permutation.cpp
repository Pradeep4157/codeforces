#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

        IF IT IS DIVISIBLE BY 3 THEN WE CAN JUST EXCHANGE 1 WITH
        2 AND 2 WITH ONE (REMAINDERS)
        SIMILAR FROM N%3==2

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
        if (n == 2)
        {
            vector<int> res;
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == 1)
                    res.push_back(2);
                else
                    res.push_back(1);
            }
            for (auto a : res)
                cout << a << " ";
            cout << endl;
            continue;
        }
        vector<int> res;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == n)
                res.push_back(arr[i]);
            else
                res.push_back(n - arr[i]);
        }
        for (auto a : res)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
