#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> res(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        res[arr[i] - 1] = i + 1;
    }
    for (auto a : res)
        cout << a << " ";
    cout << endl;
    return 0;
}
