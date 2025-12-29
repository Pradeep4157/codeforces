#include <bits/stdc++.h>
#define int long long
using namespace std;
int find(vector<pair<int, int>> &points)
{
    int n = points.size();
    double sumx = 0, sumy = 0;
    for (auto a : points)
    {
        int x = a.first;
        int y = a.second;
        sumx += x;
        sumy += y;
    }

    double cx = sumx / n;
    double cy = sumy / n;

    int best = LLONG_MAX;

    // Try all integer points in a 3x3 grid around the centroid
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            int tx = round(cx) + dx;
            int ty = round(cy) + dy;

            int max_dist = 0;
            for (auto a : points)
            {
                int x = a.first;
                int y = a.second;
                int dist = max(abs(tx - x), abs(ty - y));
                max_dist = max(max_dist, dist);
            }

            best = min(best, max_dist);
        }
    }

    return best;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << sizeof(string) << endl;

    return 0;
}
