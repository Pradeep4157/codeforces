#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i].first;
        for (int i = 0; i < n; i++)
            cin >> arr[i].second;
        for (int i = 0; i < n; i++)
        {
            if (arr[i].second < arr[i].first)
            {
                swap(arr[i].first, arr[i].second);
            }
        }
        int res = 0;
        for (auto a : arr)
        {
            res += (a.second - a.first);
        }
        // trying to find overlap
        sort(arr.begin(), arr.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             {
            if(a.first!=b.first){
                return a.first<b.first;
            }
            else{
                return a.second>b.second;
            } });
        int maxri = -1;
        bool found = false;
        for (auto a : arr)
        {
            if (a.first <= maxri)
            {
                found = true;
                break;
            }
            maxri = max(maxri, a.second);
        }
        if (found == true)
        {
            cout << res << endl;
            continue;
        }
        // now i will try to find closest segments
        int mindiff = LLONG_MAX;
        for (int i = 0; i < n - 1; i++)
        {
            auto a = arr[i];
            auto b = arr[i + 1];
            int currres = a.second - a.first + b.second - b.first;
            int bres = b.second - a.first + b.first - a.second;
            int currdiff = bres - currres;
            mindiff = min(mindiff, currdiff);
        }
        res += mindiff;
        cout << res << endl;
    }
    return 0;
}
