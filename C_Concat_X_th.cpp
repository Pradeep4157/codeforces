#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<string> res;
void recursion(vector<string> &arr, int k, string temp, int depth)
{
    if (depth == k)
    {
        res.push_back(temp);
        return;
    }
    for (int i = 0; i < arr.size(); i++)
    {
        recursion(arr, k, temp + arr[i], depth + 1);
    }
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, x;
    cin >> n >> k >> x;
    vector<string> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    recursion(arr, k, "", 0);
    sort(res.begin(), res.end());
    cout << res[x - 1] << endl;
    return 0;
}
