#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    we consider every node as root and find ans for each one of them..

    sum ( au * d(r,u)) : ig we need to find for all r's the u's are all the nodes that are in the subtree of r ..

    and for each subtree we can remove a node in that subtree and connect that edge to any other edge in the subtree..

    if i can do this for every subtree then i will try to join one subtree with the longest subtree..

    something of joining either second longest to longest or longest to second longest..

    so i select some subtree, then i will connect that to some leaf node..

    so the dist of all these nodes in the subtree inc by leaf dist from r..

    if a node r has only 1 child..

    then the ans for dp[r] = dp[u] + 1 because there is no other child or r that i can put under u and make better dp[r]

    and incase there is some node v in the subtree of u which i attach to some leaf of u to make better dp[r]

    that must  have already been done by some node in the subtree of u including u..

    now if node r has more than 1 child...

    lets say them u1,u2,u3,...un..

    now for  every child we will have subtree dist( this is sum of all dist of all nodes in subtree of u from u ),dp[ui] and

    i might also keep all leaf dist of node u in the subtree of node u..

    now for r we will bf every child ui and try to connect this ui to some leaf of uj that would obv be the max leaf of uj

    so instead of storing all the leafs only max leaf is fine..

    so for every node r first we will find best two childs ui and uj such that there dist is maximum..

    so iterate on all the childs and then ..

    do dp[r] = no of childs of r + sum of all subtrees of all childs + max_leaf_not_in_this_subtree*(no_of_nodes_in_this_subtree)..

    and for no swap case also we will do dp[r] = max(dp[r], no of childs of r + sum of all childs )

    also maybe it is better if we swap in some subtree of node r ..

    then we can handle that also with dp[r] = no of childs of r + sum of all subtree of all childs - sum of this subtree child + dp[this child]..

    this wont work because we also need to multiply with au..

    if we forget about the swap thing..

    how will we find sum of a subtree if ai values is assigned to it..

    when we go from a child to a parent..

    instead of dist increasing by the no of nodes in the subtree the distance increases by the sum of all ai in the subtree of that child..

    because distance of all these nodes increases by their node value..

    so now we need to keep max leaf in all the subtrees, sum of all node values in a subtree & dp of all the nodes...

    what happens when we are at a level and move to the above  level..

    currently the sum is like this : 0*ai + 1*(i + 1 level_nodes) + 2*(i + 2 level_nodes )

    when we go above we need to do :

    1*ai + 2(i + 1 level_nodes) + 3*(i + 2 level_nodes) + ...

    so for every node we keep the sum of all ai's in that subtree and subtree_sizee of that sub_tree

    and for a node what we do is sizee[node] = sum of all childs( subtree_ai + subtree_sizee)..

    now we have the subtree sum now for every node it is sum of subtree sum of all childs + sizee of all childs..

    now we have all the sizees of all the trees we also need max leaf of the node..

    we can store them in sizees array..

    after this ..

    for every node either we make a swap or no swap..

    so if we dont swap then dp[node] = sizee[node]

    else if we make a swap then it is either we make swap in our current childs or swaps that were made by those childs..

    so if we break 1 of our childs and join it to the leaf of some other branch then..

    then first we remove the contribution of that child..

    and we also need to find the new contribution of that child and add it to the current node..

    removal of contri is simple we just do : sizee[node] -= (sum_array[child] + sizee[child])

    maybe it is (dist + 1)*(sum_array[child]) + sizee[child]..

    if we think of taking some swap that has been made by some child of child of u .. then

    the change will be sizee[node] - (contri of that node) + (new contri of that node)

    how do we find new contri of this node..

    it is mostly dp[child] + sum till there..



*/

vector<int> sum_array;
vector<int> dp;
// sizee.first is the sizee we got with no swap and sizee.second is the  max leaf in that path..
vector<pair<int, int>> sizee;
void dfs(int node, int parent, vector<vector<int>> &adj, vector<int> &arr)
{

    sum_array[node] = arr[node - 1];
    for (auto child : adj[node])
    {
        if (child != parent)
        {
            dfs(child, node, adj, arr);
            sum_array[node] += sum_array[child];
            sizee[node].first += (sum_array[child] + sizee[child].first);
            sizee[node].second = max(sizee[node].second, sizee[child].second + 1);
        }
    }
    return;
}
void dfs2(int node, int par, vector<vector<int>> &adj, vector<int> &arr)
{
    // if its a leaf can we do something ? no
    // do we need to check if it's a leaf no i dont think so..
    // base case is that we dont do any swap and we are happy with what we have got..
    // so dp is simply the sizee we have found so far..
    dp[node] = sizee[node].first;
    // now we think how about we take adv of swap that our child has made..
    int maxi = 0, second_maxi = 0;
    for (auto child : adj[node])
    {
        if (child != par)
        {
            // if we want to take adv of its swap  then first remove its contri..
            dfs2(child, node, adj, arr);
            int curr = sizee[node].first;
            // we remove initial contri of this child..
            curr -= (sum_array[child] + sizee[child].first);

            // now we use
            curr += (dp[child] + sum_array[child]);
            // checking if that is better than current dp..
            dp[node] = max(dp[node], curr);
            if (sizee[child].second > maxi)
            {
                second_maxi = maxi;
                maxi = sizee[child].second;
            }
            else if (sizee[child].second > second_maxi)
            {
                second_maxi = sizee[child].second;
            }
        }
    }
    // now if we want to make swap of this child with some other child then we need 2 maxi leaves..
    // we have found that now we will use it..
    maxi++;
    second_maxi++;

    if (adj[node].size() >= 3 || (node == 1 && (adj[node].size() > 1)))
    {
        for (auto child : adj[node])
        {
            if (child != par)
            {
                int curr = sizee[node].first;
                // remove the contri of this child..
                curr -= (sum_array[child] + sizee[child].first);

                // now attach this branch to the max leaf found
                if (sizee[child].second == (maxi - 1))
                {

                    // then we cant use the best leaf because that is in this tree only..
                    curr += (((second_maxi + 1) * sum_array[child]) + sizee[child].first);
                }
                else
                {
                    curr += (((maxi + 1) * sum_array[child]) + sizee[child].first);
                }
                dp[node] = max(dp[node], curr);
            }
        }
    }
}
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
        vector<vector<int>> adj(n + 1);
        sum_array.assign(n + 1, 0);
        sizee.assign(n + 1, {0, 0});
        dp.assign(n + 1, 0);
        for (int i = 0; i < n - 1; i++)
        {
            int first, second;
            cin >> first >> second;
            adj[first].push_back(second);
            adj[second].push_back(first);
        }
        // now we first create the sum array and then with it we will create the sizees array..
        dfs(1, -1, adj, arr);
        // for (auto a : sizee)
        // {
        //     cout << a.first << ":" << a.second << endl;
        // }
        // cout << endl;
        // now we have everything that we need to fill the dp table..
        dfs2(1, -1, adj, arr);
        for (int i = 1; i <= n; i++)
            cout << dp[i] << " ";
        cout << endl;
    }
    return 0;
}
