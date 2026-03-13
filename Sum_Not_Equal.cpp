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
        bool found = false;
        for (auto a : arr)
        {
            if (a != 0)
                found = 1;
        }
        if (found == false)
        {
            cout << -1 << endl;
            continue;
        }
        vector<pair<int, int>> temp;
        for (int i = 0; i < n; i++)
        {
            temp.push_back({arr[i], i});
        }

        sort(temp.begin(), temp.end());
        int first = temp[0].second;
        int last = temp[n - 1].second;
        int second = temp[1].second;
        cout << second + 1 << " " << last + 1 << " " << first + 1 << endl;
    }
    return 0;
}
