#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> findigits(int n)
{
    vector<int> res;
    while (n)
    {
        int last = n % 10;
        if (last > 0)
        {
            res.push_back(last);
        }
        n /= 10;
    }
    return res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    queue<int> q;
    q.push(n);
    dp[n] = 0;
    int steps = 1;
    bool found = false;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            int curr = q.front();
            q.pop();
            vector<int> digits = findigits(curr);
            for (auto a : digits)
            {
                int newnumber = curr - a;
                if (dp[newnumber] == -1)
                {
                    dp[newnumber] = steps;
                    if (newnumber == 0)
                    {
                        found = 1;
                        break;
                    }
                    q.push(newnumber);
                }
            }
            if (found)
                break;
        }
        steps++;
        if (found)
            break;
    }
    cout << dp[0] << endl;
    return 0;
}
