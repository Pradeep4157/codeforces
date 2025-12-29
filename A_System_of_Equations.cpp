#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:







*/
int n;
int m;
int recursion(int a)
{
    int first = a * a;
    if (first > n)
        return 0;
    else
    {
        int b = n - first;
        if (((b * b) + a) == m)
        {
            return 1 + recursion(a + 1);
        }
        else
            return recursion(a + 1);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    cout << recursion(0) << endl;
    return 0;
}
