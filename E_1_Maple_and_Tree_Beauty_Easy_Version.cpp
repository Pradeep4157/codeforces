#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


        THE MAIN GOAL OF THIS PROBLEM IS TO FILL SOME LEVELS OF TREE WITH ZEROES
        AND MINIMIZE THE WASTAGE OF ZEROES AND ONES

        TRY TO FIT THESE ZEROES IN THE BEST WAY POSSIBLE AT ANY LEVELS




        HERE IF THE NUMBER OF NODES TILL THE SMALLEST LEVEL  OF TREE IS SMALLER EITHER K OR  N-K  THEN ANS=SMALLEST
        LEVEL OF TREE

        SMALLEST LEVEL OF THE TREE:
            QUEUE:
                KEEP PUSHING UNTIL SOME NODE HAS NO CHILDREN THAT'S WHERE
                YOU BREAK
                THAT IS THE SMALLEST LEVEL

        FIRST I WILL GET THE NUMBER OF NODES AT EACH LEVEL
            STORE IT IN AN ARRAY:
                AND WITH THE HELP OF RECURSION FIND WHETHER SUM OF ANY OF THOSE NODES
                IS DIVISIBLE BY EITHER K OR (N-K)

            IF YES:
                RETURN SMALLEST LEVEL OF THE TREE

            ELSE:
                ANS= FIRST WE SELECT




*/
int n, k;
int best;
int maxi;
vector<vector<int>> dp;
void recursion(int start, vector<int> &nodesateachlevel, int sum)
{
    int size = nodesateachlevel.size();
    if (start == size)
    {
        int rem = 1e9;
        // cout << sum << ":" << k << "::" << n - k << endl;
        if (sum <= k)
        {
            rem = min(rem, k - sum);
        }
        if (sum <= (n - k))
        {
            rem = min(rem, n - k - sum);
        }
        best = min(best, rem);
        return;
    }
    if (sum > maxi)
        return;
    if (dp[start][sum] != -1)
        return;
    dp[start][sum] = 1;
    recursion(start + 1, nodesateachlevel, sum);
    recursion(start + 1, nodesateachlevel, sum + nodesateachlevel[start]);
    return;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; i++)
        {
            int child = i + 2;
            int par;
            cin >> par;
            adj[par].push_back(child);
        }

        int smallestlevel = 1;
        vector<int> nodesateachlevel;
        queue<int> q;
        q.push(1);
        bool found = false;
        while (!q.empty())
        {
            int size = q.size();
            nodesateachlevel.push_back(size);
            for (int i = 0; i < size; i++)
            {
                int curr = q.front();
                q.pop();
                if (adj[curr].empty() && found == false)
                {
                    found = true;
                }
                for (auto nei : adj[curr])
                {
                    q.push(nei);
                }
            }
            if (found == false)
                smallestlevel++;
        }
        int ntsl = 0;
        for (int i = 0; i < smallestlevel; i++)
        {
            ntsl += nodesateachlevel[i];
        }
        if (ntsl <= k || ntsl <= (n - k) || k == 0 || k == n)
        {
            cout << smallestlevel << endl;
            continue;
        }
        best = 1e9;
        maxi = max(n - k, k);
        dp.assign(nodesateachlevel.size(), vector<int>(maxi + 1, -1));
        recursion(0, nodesateachlevel, 0);
        if (best == 0)
        {
            cout << smallestlevel << endl;
            continue;
        }

        int ans = 0;
        int mini = min(n - k, k);
        int index = nodesateachlevel.size();
        for (int i = 0; i < nodesateachlevel.size(); i++)
        {
            if (i == smallestlevel)
                break;
            if (nodesateachlevel[i] > maxi)
            {
                index = i + 1;
                break;
            }

            maxi -= nodesateachlevel[i];
            ans++;
        }
        for (int i = index; i < nodesateachlevel.size(); i++)
        {
            if (i == smallestlevel)
                break;
            if (nodesateachlevel[i] > mini)
            {
                break;
            }
            mini -= nodesateachlevel[i];
            ans++;
        }

        cout << ans << endl;
    }
    return 0;
}
