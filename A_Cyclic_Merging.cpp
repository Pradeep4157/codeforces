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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<pair<int, int>> temp;
        for (int i = 0; i < n - 1; i++)
        {
            int first = arr[i];
            int second = arr[i + 1];
            if (first > second)
                swap(first, second);
            temp.push_back({second, first});
        }
        int F = arr[0];
        int S = arr[n - 1];
        if (F > S)
            swap(F, S);
        temp.push_back({S, F});
        sort(temp.begin(), temp.end());
        int res = 0;
        for (int i = 0; i < n - 1; i++)
        {
            res += temp[i].first;
        }
        cout << res << endl;
    }
    return 0;
}
