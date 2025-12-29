#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    so invalid case ans is 0..

    this is if the node is not yet  visited in the bfs level ..

    so all the nodes we can store in q and set and check for each node whether

    we have got this node till now or not ..

    if not then ok is false and exit else put all the nei of this node in the set..

    and continue..

    after this ..


    now we need to find the no of pos.s.

    for each node it is only supposed to connect to one of its par.. or maybe that's not

    true..


    now for the no of edges that i can remove.. 

    it is maybe for every node how many edges i can remove and return the multiplication

    of all these things..

    what is def : 

    1) for every node no matter how many i del atleast 1 edge should be connected 

    to a node with val < curr_node_val .. 

    now can i just let only 1 remain and remove all sort of thing .. NO mostly .. 


    what is BF .. 

    i form all the ways of making a valid graph and from each valid one .. 

    add to res total_edges - edges used here.. 

    maybe the concept is that every graph is going to be MST .. 

    so we count the no of MST's poss and then return count*(total_edges) - count*(n-1)


    what is the structure .. 

    its either straight graph.. 

    or if there is a partition.. 


    then the smaller one covers only all the edges before the other partition.. 

    and then we go to the bigger one.. 

    

    






*/
int n, m;
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < m; i++)
        {
            int first, second;
            cin >> first >> second;
            adj[first].push_back(second);
            adj[second].push_back(first);
        }
        // now imp check..
        bool ok = 1;
        set<int> till_now;
        till_now.insert(1);
        for (int node = 1; node <= n; node++)
        {
            if (!till_now.count(node))
            {
                ok = false;
                break;
            }
            else
            {
                for (auto nei : adj[node])
                {
                    till_now.insert(nei);
                }
            }
        }
        if (ok == false)
        {
            cout << 0 << endl;

            continue;
        }
        
    }
    return 0;
}
