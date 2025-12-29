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
        int first = n;
        int second = 0;
        int res = 0;

        while (true)
        {

            if (first == 1 && second == 1)
            {
                res++;
                break;
            }
            res += (first / 2) + (second / 2);

            second = (second + 1) / 2 + (first / 2);
            first = (first + 1) / 2;
        }

        cout << res << endl;
    }
    return 0;
}
