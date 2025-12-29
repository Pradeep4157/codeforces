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
        int w, h, a, b;
        cin >> w >> h >> a >> b;
        int x1min, y1min, x2min, y2min;
        cin >> x1min >> y1min >> x2min >> y2min;
        int x1max = x1min + a;
        int y1max = y1min + b;
        int x2max = x2min + a;
        int y2max = y2min + b;
        bool ok = 1;
        // case 1 checking
        int xleft = max(x1min, x2min);
        int xright = min(x1max, x2max);
        int yleft = max(y1min, y2min);
        int yright = min(y1max, y2max);
        if (xright > xleft || yright > yleft)
        {
            if (xright > xleft)
            {
                // block needs to be inserted between them
                int minheight = min(y1max, y2max);
                int maxheight = max(y1min, y2min);
                int height = maxheight - minheight;
                if (height % b)
                {
                    ok = false;
                }
            }

            if (yright > yleft)
            {
                int minheight = min(x1max, x2max);
                int maxheight = max(x1min, x2min);
                int height = maxheight - minheight;
                if (height % a)
                {
                    ok = false;
                }
            }
        }
        // case 2: blocks are totally apart and we need to fill the area either vertically or horizontally
        else
        {
            int verticalheight = max(y1min, y2min) - min(y1max, y2max);
            int horizontalheight = max(x1min, x2min) - min(x1max, x2max);
            if (horizontalheight % a && verticalheight % b)
            {
                ok = false;
            }
        }
        if (ok)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
