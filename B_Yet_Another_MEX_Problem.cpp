#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    the goal is to save 0..k-2..

    the max mex that i can save is k-1..

    every time i select a window of size k..

    so the error was that we can increase the mex value ..



*/

vector<int> find(vector<int> &a, int k)
{
    int n = a.size();
    vector<int> freq(k + 1, 0);
    set<int> missing;
    vector<int> ans;

    for (int i = 0; i <= k; i++)
        missing.insert(i);

    for (int i = 0; i < k; i++)
    {
        if (a[i] <= k)
        {
            freq[a[i]]++;
            if (freq[a[i]] == 1)
                missing.erase(a[i]);
        }
    }

    ans.push_back(*missing.begin());

    for (int i = k; i < n; i++)
    {

        int out = a[i - k];
        if (out <= k)
        {
            freq[out]--;
            if (freq[out] == 0)
                missing.insert(out);
        }

        int in = a[i];
        if (in <= k)
        {
            freq[in]++;
            if (freq[in] == 1)
                missing.erase(in);
        }

        ans.push_back(*missing.begin());
    }

    return ans;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> all_mexes = find(arr, k);
        sort(all_mexes.begin(), all_mexes.end());
        int maxi = all_mexes[all_mexes.size() - 1];
        maxi = min(maxi, k - 1);
        cout << maxi << endl;
    }
    return 0;
}
