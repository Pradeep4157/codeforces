#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
int binpow(int a, int b, int mod)
{
    if (b == 0)
        return 1;
    int temp = binpow(a, b / 2, mod);
    temp = (temp * temp);
    if (b & 1)
        return (a * temp);
    return temp;
}
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
        int first = binpow(2, n, (int)(1e9 + 7));
        int y = first * 2 - x;

        vector<int> res;
        while (true)
        {
            if (x == first && y == first)
                break;
            if (x < y)
            {
                y -= x;
                x *= 2;
                res.push_back(1);
            }
            else
            {
                x -= y;
                y *= 2;
                res.push_back(2);
            }
        }
        int size = res.size();
        cout << size << endl;
        for (int i = size - 1; i >= 0; i--)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
