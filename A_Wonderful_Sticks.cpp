#include <bits/stdc++.h>
#define int long long
using namespace std;

int_fast32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<char> arr(n - 1);
        for (int i = 0; i < n - 1; i++)
            cin >> arr[i];
        vector<int> res(n, 1);
        unordered_set<int> used;
        used.insert(1);
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] == '<')
            {
                for (int j = 0; j <= i; j++)
                {
                    used.erase(res[j]);
                    res[j]++;
                }
                for (int j = 0; j <= i; j++)
                    used.insert(res[j]);
            }
            for (int k = 1; k <= n; k++)
            {
                if (!used.count(k))
                {
                    res[i + 1] = k;
                    used.insert(k);
                    break;
                }
            }
        }
        for (auto a : res)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
