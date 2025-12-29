#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
int find(int n)
{
    int res = 0;
    while (n)
    {
        int last = n % 10;
        n /= 10;
        res += last;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    arr[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        int sum = 0;
        for (int j = 0; j < i; j++)
            sum += find(arr[j]);
        arr[i] = sum;
    }
    cout << arr[n] << endl;
    return 0;
}
