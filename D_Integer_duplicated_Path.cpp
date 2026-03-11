#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    for a node i need to find from parent

    does it have same number..

    so dfs while doing store the val

    give it to the child ..

    they add their's and then

    after dfs remove their value

    and continue..


*/
vector<vector<int>> adj;
vector<int> arr;
multiset<int> st;
vector<int> dp;
void dfs(int node, int par)
{
    // checking if this value is there or not..
    auto it = st.lower_bound(arr[node - 1]);
    if (it != st.end())
    {
        int val = *it;
        if (val == arr[node - 1])
        {
            dp[node - 1] = 1;
        }
    }
    if (dp[par - 1] == 1)
        dp[node - 1] = 1;
    // adding its value..
    st.insert(arr[node - 1]);
    // now going to children..
    for (auto child : adj[node])
    {
        if (child != par)
        {
            dfs(child, node);
        }
    }
    it = st.lower_bound(arr[node - 1]);
    if (it != st.end())
    {
        st.erase(it);
    }
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    st.clear();
    arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    adj.resize(n + 1);
    dp.assign(n, 0);
    for (int i = 0; i < n - 1; i++)
    {
        int first, second;
        cin >> first >> second;
        adj[first].push_back(second);
        adj[second].push_back(first);
    }
    dfs(1, 0);
    for (auto a : dp)
    {

        if (a == 0)
            cout << "No" << endl;
        else
            cout << "Yes" << endl;
    }
    return 0;
}
