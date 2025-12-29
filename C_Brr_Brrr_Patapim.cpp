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
        vector<vector<int>> arr(n, vector<int>(n));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                cin >> arr[i][j];
        }
        vector<int> res(2 * n);
        unordered_set<int> st;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int index = i + j + 1;
                res[index] = arr[i][j];
                st.insert(arr[i][j]);
            }
        }
        for (int i = 1; i <= 2 * n; i++)
        {
            if (!st.count(i))
            {
                res[0] = i;
                break;
            }
        }
        for (auto a : res)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
