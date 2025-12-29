#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
int rev(int a)
{
    int res = 0;
    while (a)
    {
        int last = a % 10;
        res = (res * 10) + last;
        a /= 10;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y;
    cin >> x >> y;
    vector<int> arr(10);
    arr[0] = x;
    arr[1] = y;

    for (int i = 2; i < 10; i++)
    {

        arr[i] = arr[i - 1] + arr[i - 2];
        arr[i] = rev(arr[i]);
    }

    cout << arr[9] << endl;
    return 0;
}
