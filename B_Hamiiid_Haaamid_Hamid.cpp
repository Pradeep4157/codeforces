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
        int n, x;
        cin >> n >> x;
        x--;

        vector<char> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        deque<int> left, right;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == '#')
            {
                if (i > x)
                    right.push_back(i);
                else
                    left.push_back(i);
            }
        }

        if (left.empty() && right.empty())
        {
            cout << 1 << endl;
            continue;
        }

        else if (left.empty() || right.empty())
        {
            if (left.empty())
            {
                // mani will block the left path
                int res = min(x + 1, n - right.front() + 1);
                cout << res << endl;
            }
            else
            {
                int res = min(n - (x + 1) + 1, left.back() + 1 + 1);
                cout << res << endl;
            }
        }
        else
        {
            // mani will block the direction which has lesser rooms after the first wall
            int leftwall = left.back();
            int rightwall = right.front();
            int lefttime = leftwall + 2;
            int righttime = n - rightwall + 1;
            // this is if i try to jump to  the first wall on left/right
            int res = max(lefttime, righttime);
            res = min(res, x + 1);
            res = min(res, n - x);
            cout << res << endl;
        }
    }

    return 0;
}