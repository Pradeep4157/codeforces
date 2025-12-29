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
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].first >> arr[i].second;
        }
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        vector<pair<int, int>> xp(n), xs(n), yp(n), ys(n);
        xp[0].first = arr[0].first;
        xp[0].second = arr[0].first;
        yp[0].first = arr[0].second;
        yp[0].second = arr[0].second;
        // prefix creation
        for (int i = 1; i < n; i++)
        {
            int minx = xp[i - 1].first;
            int maxx = xp[i - 1].second;
            int miny = yp[i - 1].first;
            int maxy = yp[i - 1].second;
            int currx = arr[i].first;
            int curry = arr[i].second;
            minx = min(minx, currx);
            maxx = max(maxx, currx);
            miny = min(miny, curry);
            maxy = max(maxy, curry);
            xp[i].first = minx;
            xp[i].second = maxx;
            yp[i].first = miny;
            yp[i].second = maxy;
        }
        // suffix creation
        xs[n - 1].first = arr[n - 1].first;
        xs[n - 1].second = arr[n - 1].first;
        ys[n - 1].first = arr[n - 1].second;
        ys[n - 1].second = arr[n - 1].second;
        for (int i = n - 2; i >= 0; i--)
        {

            int minx = xs[i + 1].first;
            int maxx = xs[i + 1].second;
            int miny = ys[i + 1].first;
            int maxy = ys[i + 1].second;
            int currx = arr[i].first;
            int curry = arr[i].second;
            minx = min(minx, currx);
            maxx = max(maxx, currx);
            miny = min(miny, curry);
            maxy = max(maxy, curry);
            xs[i].first = minx;
            xs[i].second = maxx;
            ys[i].first = miny;
            ys[i].second = maxy;
        }
        int res;
        int length = xs[1].second - xs[1].first + 1;
        int height = ys[1].second - ys[1].first + 1;
        int area = length * height;
        if (area < n)
        {
            // will have to increase
            res = min((length + 1) * height, (height + 1) * length);
        }
        else
            res = area;
        length = xp[n - 2].second - xp[n - 2].first + 1;
        height = yp[n - 2].second - yp[n - 2].first + 1;
        area = length * height;
        if (area < n)
        {
            int currres = min((length + 1) * height, (height + 1) * length);
            res = min(res, currres);
        }
        else
            res = min(res, area);
        for (int i = 1; i < n - 1; i++)
        {
            int minx = min(xp[i - 1].first, xs[i + 1].first);
            int maxx = max(xp[i - 1].second, xs[i + 1].second);
            int miny = min(yp[i - 1].first, ys[i + 1].first);
            int maxy = max(yp[i - 1].second, ys[i + 1].second);
            length = maxx - minx + 1;
            height = maxy - miny + 1;
            int currres = length * height;
            if (currres < n)
            {
                currres = min((length + 1) * height, (height + 1) * length);
                res = min(res, currres);
            }
            else
                res = min(res, currres);
        }
        cout << res << endl;
    }
    return 0;
}
