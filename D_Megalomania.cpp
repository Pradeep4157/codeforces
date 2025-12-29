#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    sorting on the basis of bi  and then increasing on the basis of ai

    because we need to complete all the jobs not some of them so the most

    time consuming should be completed first ?



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
        arr[i] = {second, first};
    }
    sort(arr.begin(), arr.end(), [](auto &a, auto &b)
         {
            if(a.first!=b.first) return  a.first < b.first;
            else return a.second > b.second; });
    bool ok = 1;

    int currtime = 0;
    for (int i = 0; i < n; i++)
    {
        currtime += arr[i].second;
        if (currtime > arr[i].first)
        {
            ok = false;
            break;
        }
    }
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
