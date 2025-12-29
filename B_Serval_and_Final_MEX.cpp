#include <bits/stdc++.h>
#define ll int64_t
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp[arr[i]].push_back(i);
        }
        if (mp.find(0) == mp.end())
        {
            cout << 1 << endl;
            cout << 1 << " " << n << endl;
            continue;
        }

        vector<int> &indexes = mp[0];
        int size = indexes.size();
        int left = 0;
        int right = size - 1;
        bool leftchance = 1;
        int distance = 0;
        int groups = 0;
        vector<pair<int, int>> res;
        while (right >= 1)
        {
            int index = indexes[right];
            int prev = index - 1;
            res.push_back({index - 1, index});
            if (index - 1 == indexes[right - 1])
            {
                right -= 2;
            }
            else
            {
                right--;
            }
            groups++;
        }

        if (right == -1)
        {
            // first zero is already merged
            int rem = n - 2 * groups;
            int total = rem + groups;
            res.push_back({0, total - 1});
            cout << res.size() << endl;
            for (auto a : res)
            {
                cout << a.first + 1 << " " << a.second + 1 << endl;
            }
            continue;
        }
        else
        {

            groups++;
            int index = indexes[right];
            if (index == n - 1)
            {
                res.push_back({index - 1, index});
            }
            else
                res.push_back({index, index + 1});
            int rem = n - 2 * groups;
            int total = rem + groups;
            res.push_back({0, total - 1});
            cout << res.size() << endl;
            for (auto a : res)
            {
                cout << a.first + 1 << " " << a.second + 1 << endl;
            }
            continue;
            // merge the first 0 will the 1st cell
        }
    }
    return 0;
}
