#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so to maximize profit we will try to  complete sjf ?

    but then longer will give -ve res

*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        int first, second;
        cin >> first >> second;
        arr[i] = {first, second};
    }
    sort(arr.begin(), arr.end(), [&](auto a, auto b)
         {
                if(a.first!=b.first) return  a.first < b.first;
                else return b.second > b.second; });
    int res = 0;
    int currtime = 0;
    for (int i = 0; i < n; i++)
    {
        currtime += arr[i].first;
        res += (arr[i].second - currtime);
        cout << res << endl;
    }
    cout << res << endl;

    return 0;
}
