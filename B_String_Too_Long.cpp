#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<char, int>> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    int limit = 100;
    int size = 0;
    bool ok = 1;
    string res;
    for (int i = 0; i < n; i++)
    {
        int currsize = arr[i].second;
        if (currsize + size > limit)
        {
            ok = false;
            break;
        }
        size += currsize;
        while (currsize)
        {
            currsize--;
            res += (arr[i].first);
        }
    }
    if (ok)
        cout << res << endl;
    else
        cout << "Too Long" << endl;
    return 0;
}
