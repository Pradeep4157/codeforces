#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> a;
int ans = 0;

int LIS(vector<int> &arr)
{
    int n = arr.size();
    vector<int> dp;
    for (int i = 0; i < n; ++i)
    {
        auto it = lower_bound(dp.begin(), dp.end(), arr[i]);
        if (it == dp.end())
            dp.push_back(arr[i]);
        else
            *it = arr[i];
    }
    return dp.size();
}

void dfs(int idx, vector<int> &temp, vector<int> &indices)
{
    if (idx == n)
    {
        // make a copy of array
        vector<int> b = a;

        // reverse the temp array
        vector<int> rev_temp = temp;
        reverse(rev_temp.begin(), rev_temp.end());

        // put back reversed values into their original positions
        for (int i = 0; i < indices.size(); ++i)
        {
            b[indices[i]] = rev_temp[i];
        }

        // compute LIS
        ans = max(ans, LIS(b));
        return;
    }

    // Option 1: Don't take current element
    dfs(idx + 1, temp, indices);

    // Option 2: Take current element if valid
    if (temp.empty() || a[idx] <= temp.back())
    {
        temp.push_back(a[idx]);
        indices.push_back(idx);

        dfs(idx + 1, temp, indices);

        // Backtrack
        temp.pop_back();
        indices.pop_back();
    }
}

int main()
{
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    ans = LIS(a); // no reverse case

    vector<int> temp, indices;
    dfs(0, temp, indices);

    cout << ans << endl;
    return 0;
}
