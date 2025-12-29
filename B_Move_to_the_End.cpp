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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> res(n);
        vector<pair<int, int>> greatest;
        for (int i = 0; i < n; i++)
            greatest.push_back({arr[i], i});
        sort(greatest.rbegin(), greatest.rend());
        vector<int> suffix(n);
        for (int i = n - 1; i >= 0; i--)
        {
            suffix[i] = arr[i];
            if (i < n - 1)
                suffix[i] += suffix[i + 1];
        }

        int curr = 0;
        res[n - 1] = *max_element(arr.begin(), arr.end());
        int minele = arr[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            int currres = suffix[i];

            // cout << minele << ":" << greatest[curr].first << endl;
            if (arr[i] >= greatest[curr].first)
            {
                res[i] = currres;
                continue;
            }
            // try to find out of curr window
            while (curr < n && greatest[curr].second >= i)
            {
                curr++;
            }
            if (curr < n && greatest[curr].first > arr[i])
            {

                currres -= arr[i];
                currres += greatest[curr].first;
                res[i] = currres;
                continue;
            }
            else
                res[i] = currres;
        }
        reverse(res.begin(), res.end());
        for (auto a : res)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
