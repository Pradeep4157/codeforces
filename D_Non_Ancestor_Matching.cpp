#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:
         KEEP POPING FROM THE QUEUE UNTIL THERE IS ONLY ONE NODE
         LEFT AND THEN WE CANT COMBINE THAT WITH ANYTHING

         IF THERE IS ONLY ONE NODE THEN PUSH ALL ITS CHILDREN
         IF IT HAS ANY


         AT THE END, ANS=NODES REMOVED AS PAIRS/2

        THIS BA METHOD AINT WORKING




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
        vector<vector<int>> adj(n);
        for (int i = 0; i < n - 1; i++)
        {
            int par;
            cin >> par;
            int child = i + 2;
            adj[par].push_back(child);
        }

        queue<int> q;
        q.push(1);
        int res = 0;
        while (!q.empty())
        {
            int size = q.size();
            if (size == 1)
            {
                int node = q.front();
                cout << node << endl;
                q.pop();
                for (auto child : adj[node])
                {
                    q.push(child);
                }
            }
            else
            {
                int first = q.front();
                q.pop();
                int second = q.front();
                q.pop();
                res++;
                cout << first << ":" << second << endl;
                for (auto child : adj[first])
                {
                    q.push(child);
                }
                for (auto child : adj[second])
                {
                    q.push(child);
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
