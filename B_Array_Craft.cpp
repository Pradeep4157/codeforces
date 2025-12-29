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
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> arr(n, 1);
        if (x == n && y == 1)
        {
            for (auto a : arr)
                cout << a << " ";
            cout << endl;
        }
        else
        {
            bool turn = 1;
            for (int i = x; i < n; i++)
            {
                if (turn)
                {
                    arr[i] = -1;
                    turn = 0;
                }
                else
                {
                    turn = 1;
                }
            }
            turn = 1;
            for (int i = y - 2; i >= 0; i--)
            {
                if (turn)
                {
                    turn = 0;
                    arr[i] = -1;
                }
                else
                {
                    turn = 1;
                }
            }

            for (auto a : arr)
                cout << a << " ";
            cout << endl;
        }
    }
    return 0;
}
