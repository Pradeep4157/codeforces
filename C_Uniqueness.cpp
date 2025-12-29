#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    unordered_map<int, vector<int>> mp;
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]].push_back(i);
    }
    int res = -1;
    int maxint = -1;
    for (auto a : mp)
    {
        if (a.second.size() > 1)
            continue;
        else
        {

            if (a.first > maxint)
            {
                maxint = a.first;
                res = a.second[0] + 1;
            }
        }
    }
    cout << res << endl;
    return 0;
}
