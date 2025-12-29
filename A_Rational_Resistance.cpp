#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    A/B=
    IF B IS 1 ALL ARE CONNECTED IN SEQUENCE?
    WHAT IF A<B:


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a, b;
    cin >> a >> b;
    int res = 0;
    if (a == 1 && b == 1)
    {
        cout << 1 << endl;
        return 0;
    }
    while (true)
    {
        if (a <= 1 && b <= 1)
            break;
        if (a > b)
        {
            int moves = a / b;

            a -= moves * b;
            res += moves;
        }

        else
        {
            int moves = b / a;
            b -= (a * moves);
            res += moves;
        }
    }
    cout << res << endl;
    return 0;
}
