#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    SO THE ANSWER=2^N
    BUT IF WE USE THE STL FUNCTION IT GIVES WRONG ANSWER:
    WE WILL HAVE TO IMPLEMENT POWER

*/
const int mod = (int)(1e9 + 7);
int power(int a, int b)
{
    int res = 1;
    int ans = a;
    while (b)
    {
        if (b & 1)
        {
            res = (res * ans) % mod;
        }
        b /= 2;
        ans = (ans * ans) % mod;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    cout << power(2LL, n) << endl;
    return 0;
}
