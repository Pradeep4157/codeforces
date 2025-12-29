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
        int n, m;
        cin >> n >> m;
        int res = 0;
        int prev = 0;
        int prevtime = 0;
        for (int i = 0; i < n; i++)
        {
            int time, place;
            cin >> time >> place;
            int ftime = time;
            time -= prevtime;
            if ((place) == (prev))
            {
                // i can reach this at even time only
                if (time % 2 == 0)
                {
                    res += time;
                }
                else
                    res += (time - 1);
            }
            else
            {
                // i can reach this at odd time only
                if (time & 1)
                {
                    res += time;
                }
                else
                    res += (time - 1);
            }
            prev = place;
            prevtime = ftime;
        }
        res += (m - prevtime);

        cout << res << endl;
    }
    return 0;
}
