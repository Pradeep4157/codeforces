#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    i is connected to arr[i]..

    so we use indexes to connected diff groups..

    when is it imposs..

    i dont think so that it is ever impossible..

    in this mostly we can start from the max sized group

    and keep merging next max size group

    so that we have enough elements to merge new groups

    into this group..



*/
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        priority_queue<pair<int, int>> pq;
        map<int, int> mp;
        for (auto a : arr)
        {
            mp[a]++;
        }
        vector<int> res(n, -1);
        for (int i = 1; i <= n; i++)
        {
            pq.push({mp[i], i});
        }
        queue<int> q;
        int top_freq = pq.top().first;
        int ELE = pq.top().second;
        pq.pop();
        while (top_freq--)
        {
            q.push(ELE);
        }

        for (int i = 0; i <= n; i++)
        {
            if (pq.empty())
                break;
            pair<int, int> curr = pq.top();
            pq.pop();
            int curr_freq = curr.first;
            int curr_ele = curr.second;
            int curr_have = q.front();
            q.pop();
            // now add this ele to curr_ele index..
            res[curr_ele - 1] = curr_have;
            // and add this ele to the group..
            while (curr_freq--)
            {
                q.push(curr_ele);
            }
        }
        // now the max group that we got first that index is still empty
        int first = q.front();
        q.pop();
        res[ELE - 1] = first;
        for (auto a : res)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
