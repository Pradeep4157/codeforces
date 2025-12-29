#include <bits/stdc++.h>
#define int long long
using namespace std;
int maxi;
int n;
vector<int> onetwothree(vector<int> a, vector<int> b, vector<int> c)
{
    int la, ra, lb, rb, lc, rc;
    int currsum = 0;
    bool possible = false;
    for (int i = 0; i < n; i++)
    {
        currsum += a[i];
        if (currsum >= maxi)
        {
            la = 0;
            ra = i;
            possible = true;
            break;
        }
    }
    if (possible == false)
    {
        return {-1};
    }
    possible = false;
    currsum = 0;
    for (int i = ra + 1; i < n; i++)
    {
        currsum += b[i];
        if (currsum >= maxi)
        {
            lb = ra + 1;
            rb = i;
            possible = 1;
            break;
        }
    }
    if (possible == false)
    {
        return {-1};
    }
    possible = false;
    currsum = 0;
    for (int i = rb + 1; i < n; i++)
    {
        currsum += c[i];
        if (currsum >= maxi)
        {
            possible = 1;
            lc = rb + 1;
            rc = n - 1;
            break;
        }
    }
    if (possible == false)
    {
        return {-1};
    }
    return {la, ra, lb, rb, lc, rc};
}
int_fast32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {

        cin >> n;
        vector<int> a(n), b(n), c(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < n; i++)
            cin >> c[i];
        vector<int> res = {-1};
        int sum = accumulate(a.begin(), a.end(), 0LL);
        maxi = (sum + 2) / 3;
        res = onetwothree(a, b, c);
        if (res[0] != -1)
        {
            for (auto a : res)
                cout << a + 1 << " ";
            cout << endl;
            continue;
        }
        res = onetwothree(a, c, b);
        if (res[0] != -1)
        {
            cout << res[0] + 1 << " " << res[1] + 1 << " " << res[4] + 1 << " " << res[5] + 1 << " " << res[2] + 1 << " " << res[3] + 1 << endl;
            continue;
        }
        res = onetwothree(b, a, c);
        if (res[0] != -1)
        {
            cout << res[2] + 1 << " " << res[3] + 1 << " " << res[0] + 1 << " " << res[1] + 1 << " " << res[4] + 1 << " " << res[5] + 1 << endl;
            continue;
        }
        res = onetwothree(b, c, a);
        if (res[0] != -1)
        {

            cout << res[4] + 1 << " " << res[5] + 1 << " " << res[0] + 1 << " " << res[1] + 1 << " " << res[2] + 1 << " " << res[3] + 1 << endl;
            continue;
        }
        res = onetwothree(c, a, b);
        if (res[0] != -1)
        {

            cout << res[2] + 1 << " " << res[3] + 1 << " " << res[4] + 1 << " " << res[5] + 1 << " " << res[0] + 1 << " " << res[1] + 1 << endl;
            continue;
        }
        res = onetwothree(c, b, a);
        if (res[0] != -1)
        {

            cout << res[4] + 1 << " " << res[5] + 1 << " " << res[2] + 1 << " " << res[3] + 1 << " " << res[0] + 1 << " " << res[1] + 1 << endl;
            continue;
        }
        cout << -1 << endl;
        continue;
    }
    return 0;
}
