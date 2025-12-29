#include <bits/stdc++.h>
#define int long long
using namespace std;

int_fast32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        unordered_map<int, int> x;
        unordered_map<int, int> xplusy;
        for (int i = 0; i < n; i++)
        {
            int X, y;
            cin >> X >> y;
            x[X]++;
            xplusy[X + y]++;
        }
        int oddx;
        int oddxplusy;
        for (auto a : x)
        {
            if (a.second & 1)
            {
                oddx = a.first;
                break;
            }
        }
        for (auto a : xplusy)
        {
            if (a.second & 1)
            {
                oddxplusy = a.first;
                break;
            }
        }
        cout << oddx << " " << oddxplusy - oddx << endl;
    }
    return 0;
}
