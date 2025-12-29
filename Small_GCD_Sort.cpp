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
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
        {
            int curr = i + 1;
            int score = __gcd(curr, n);
            arr.push_back({score, curr});
        }
        sort(arr.begin(), arr.end(), [](pair<int, int> &a, pair<int, int> &b)
             {
            if(a.first!=b.first) return a.first>b.first;
            else return  a.second<b.second; });
        for (auto a : arr)
            cout << a.second << " ";
        cout << endl;
    }
    return 0;
}
