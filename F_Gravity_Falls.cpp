#include <bits/stdc++.h>
#define int long long
using namespace std;
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
        vector<vector<int>> arr(n);
        int maxsize = 0;
        for (int i = 0; i < n; i++)
        {
            int m;
            cin >> m;
            maxsize = max(maxsize, m);
            for (int j = 0; j < m; j++)
            {
                int ele;
                cin >> ele;
                arr[i].push_back(ele);
            }
        }

        vector<int> best(maxsize, INT_MAX);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < arr[i].size(); j++)
            {
                best[j] = min(best[j], arr[i][j]);
            }
        }
        int start = 0;
        vector<int> res(maxsize);
        while (start < maxsize)
        {
            vector<vector<int>> temp;
            for (int i = 0; i < n; i++)
            {
                if (arr[i].size() <= start)
                    continue;
                if (arr[i][start] == best[start])
                {
                    temp.push_back(vector<int>(arr[i].begin() + start, arr[i].end()));
                }
            }
            sort(temp.begin(), temp.end());

            vector<int> first = temp[0];
            int i = 0;
            while (i < first.size())
            {
                res[start] = first[i];
                i++;
                start++;
            }
        }

        for (auto a : res)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
