#include <bits/stdc++.h>
#define ll int64_t
using namespace std;
void dfs(int curr, vector<int> &arr, vector<int> &temp, int index, vector<int> &papa, vector<bool> &vis)
{
    if (vis[curr] == 1)
        return;
    vis[curr] = 1;
    temp.push_back(curr);
    papa[curr] = index;
    dfs(arr[curr], arr, temp, index, papa, vis);
    return;
}
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
            arr[i]--;
        }
        vector<int> queries(n);
        for (int i = 0; i < n; i++)
        {
            cin >> queries[i];
            queries[i]--;
        }
        vector<vector<int>> cycles;
        vector<bool> vis(n, false);
        vector<int> papa(n, 0);
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            if (vis[i] == 1)
                continue;
            vector<int> temp;
            dfs(i, arr, temp, index, papa, vis);
            index++;
            cycles.push_back(temp);
        }
        int size = cycles.size();
        int prev = 0;
        vector<bool> cyclevis(size, false);
        vector<int> res;
        for (auto &index : queries)
        {
            int cb = papa[index];

            int curr = prev;
            if (!cyclevis[cb])
            {
                cyclevis[cb] = 1;
                curr += cycles[cb].size();
            }
            res.push_back(curr);
            prev = curr;
        }
        for (auto a : res)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
