#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
    0 0 0 0
    1 1
    2


*/
int getmax(int n)
{
    vector<int> arr(n);
    if (n == 0)
    {
        return 0;
    }
    n -= 2;
    int res = 0;
    int curr = 1;
    while (n)
    {
        res += curr;
        curr++;
        n--;
    }
    return res;
}
int getmin(int n)
{
    return n - 2;
}
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
        int maxi = getmax(n);
        int mini = getmin(n);
        cout << mini << " " << maxi << endl;
    }
    return 0;
}
