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
        int n;
        cin >> n;
        vector<vector<int>> res;
        res.push_back({0, 1, n - 1});
        int col = 1;
        for (int row = 1; row < n; row++)
        {
            res.push_back({row, 0, col});
            if (col + 1 < n - 1)
                res.push_back({row, col + 1, n - 1});
            col++;
        }
        cout << res.size() << endl;
        for (auto a : res)
        {
            for (auto b : a)
                cout << b + 1 << " ";
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
