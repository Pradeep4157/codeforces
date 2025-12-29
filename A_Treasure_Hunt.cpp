#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        int x, y;
        double deep;

        cin >> x >> y >> deep;
        deep += 0.5;
        if (x + y >= deep)
        {
            if (x >= deep)
            {
                cout << "NO" << endl;
            }
            else
            {
                cout << "YES" << endl;
            }
            continue;
        }
        int total = x + y;
        int multiple = deep / (x + y);
        x = x * multiple;
        y *= multiple;

        deep = deep - (x + y);

        x /= multiple;
        deep = deep - x;

        if (deep < 0)
        {
            cout << "NO" << endl;
        }
        else
            cout << "YES" << endl;
    }
    return 0;
}
