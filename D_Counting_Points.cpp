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
        int n, m;
        cin >> n >> m;

        vector<int> xi(n), ri(n);
        for (int i = 0; i < n; i++)
            cin >> xi[i];
        for (int i = 0; i < n; i++)
            cin >> ri[i];

        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
        {
            arr[i] = {xi[i], ri[i]};
        }

        sort(arr.begin(), arr.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             {
            int left = a.first - a.second;
            int right = b.first - b.second;
            if (left == right)
                return a.second > b.second; 
            return left < right; });
        int res = 0;
        int xright = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            int centre = arr[i].first;
            int radius = arr[i].second;

            int wholearea = ((radius + 1) * (radius + 2)) / 2 + 2 * (max(0LL, (radius * (radius + 1)) / 2)) + (radius * (radius - 1)) / 2;
            cout << wholearea << endl;
            res += wholearea;
            if (xright >= (centre - radius))
            {
                int dist = xright - (centre - radius) + 1;
                int half = dist / 2LL;
                if (dist % 2)
                {

                    int sub = ((half + 1) * (half + 2)) / 2 + 2 * ((half * (half + 1)) / 2) + (half * (half - 1)) / 2;
                    res -= sub;
                    cout << sub << endl;
                }
                else
                {
                    int sub = ((half + 1) * (half)) + (half * (half - 1));
                    res -= sub;
                    cout << sub << endl;
                }
            }
            xright = max(xright, centre + radius);
        }
        cout << res << endl;
    }

    return 0;
}
