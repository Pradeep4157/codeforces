#include <bits/stdc++.h>
#define int long long
#define endline "\n"
using namespace std;
/*
        OBSERVATIONS:


        OVERVIEW:
        HERE WE NEED TO FIND DIAMETER OF THE TREE.
        FIRST WE FIND ONE END OF THE TREE (NODE J).
        FROM THERE WE FIND ANOTHER END OF TREE(NODE K).
        AND FROM NODE K WE KEEP GOING PARENT UNTIL DEGREE OF CURRENT NODE>2
            ONCE WE REACH THIS NODE:
                THIS IS NODE B, CHILD IS NODE A AND ANY NODE OTHER THAN A AND PARENT OF B IS C.

        AND IF WE DONT FIND ANY SUCH NODE B THEN THE TREE IS ALREADY AN PATH GRAPH.


        HOW DO WE FIND THIS ONE END OF THE GRAPH?
            WE FIRST FIND DIAMETER OF THE GRAPH:
                DFS(1,-1)
                FOR EACH NODE FIND DIAMETER, WHILE DOING THAT STORE MAX DEPTH OF EACH NODE IN A VECTOR, USING THIS DEPTH WE DO DFS TO FIND
                THE NODE J.
        IT IS NOT NECESSARY FOR THE DIAMETER TO PASS THROUGH THE ROOT NODE(1)
        AFTER THIS DFS WE WILL TRAVERSE THROUGH THE DEPTH ARRAY TO SEE WHICH NODE HAS THE MAX DIAMETER AND TRY TO FIND J IN THAT SUBTREE

        NOW WE HAVE NODE J


        AND NOW WE NEED TO FIND NODE K(OTHER END OF THE DIAMETER):
            WE RUN THE DFS FUNCTION AGAIN FROM THIS NODE? OR CAN WE JUST FIND THE K NODE BY FOLLOWING THE MAX DEPTH AMONG THE NEIGHBORS?
                WE WILL RUN DFS AGAIN FOR SAFETY, BUT LATER TRY WITHOUT DFS AS WELL.


        3RD DFS(CAN BE DONE USING FIRST DFS):
            STARTING FROM NODE J, WE FIND DIAMETER OF EACH NODE. AND THEN AFTER THAT DFS3 WHICH WILL HAVE SAME IMPLEMENTATION AS DFS2 JUST
            AT THE END WE WILL STORE NODE IN K INSTEAD OF J AND AT EVERY STEP WE WILL STORE THE PARENT OF NEI AS THIS NODE


        NOW WE HAVE NODE K AND NODE J

        PARENT ARRAY IS ALSO CREATED PROPERLY, NOW WE START FROM NODE K AND KEEP MOVING TO THE PARENT OF THE CURRENT NODE, AT ANY POINT WHEN
        THE PARENT OF THE NODE HAS MORE THAN 2 NEIGHBORS THEN THAT IS OUR B, THIS NODE IS OUR A ANY NODE OTHER THAN PARENT[B] WILL BECOME OUR
        C

        IF THIS THING NEVER HAPPENS THEN THE GRAPH IS ALREADY PATH GRAPH AND WE RETURN -1


        RESULT: TLE
        METHOD 2:
            WE JUST FIND NODE J AND FROM THAT NODE J FIND THE FIRST NODE WITH DEGREE>=3:
                RESULT:  WRONG ANSWER ON SOME TEST CASE 2

        METHOD 3:
            WE DONT NEED TO FIND DIAMETER TO KNOW THE TWO ENDS OF THE GRAPH:

                MAKE A DFS FROM NODE 1 AND KEEP TRACK OF THE LEVELS:
                    ANY NODE AT THE MAX LEVEL CAN BE TAKEN AS J

                FROM THAT J AGAIN MAKE THIS DFS AND KEEP TRACK OF LEVELS AND PARENT:
                    HERE ALSO ANY NODE AT THE MAX LEVEL FROM NODE J CAN BE CONSIDERED AS NODE K

                NOW WE HAVE NODE K AND NODE J

                WE DO A WHILE LOOP STARTING FROM NODE K:
                    WHEN THE PARENT OF NODE K HAS DEGREE>=3:
                        PARENT NODE[K]=B:
                        K=A:
                        ANY NODE APART FROM PARENT[PARENT[NODE K]]=C:
                        BREAK:
                IF WE DONT FIND ANY SUCH NODE THAN THE GRAPH IS ALREADY A PATH GRAPH AND RETURN -1:
                ELSE RETURN A,B,C



*/
vector<int> depth;
vector<vector<int>> adj;
vector<int> parent;
void dfs(int curr, int par)
{
    for (auto nei : adj[curr])
    {
        if (nei != par)
        {
            parent[nei] = curr;
            depth[nei] = depth[curr] + 1;
            dfs(nei, curr);
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

        adj.assign(n + 1, {});
        depth.assign(n + 1, 0);
        parent.assign(n + 1, 0);
        for (int i = 0; i < n - 1; i++)
        {
            int first, second;
            cin >> first >> second;
            adj[first].push_back(second);
            adj[second].push_back(first);
        }
        if (n <= 2)
        {
            cout << -1 << endline;
            continue;
        }
        dfs(1, -1);
        int j = max_element(depth.begin(), depth.end()) - depth.begin();
        // NOW WE NEED TO FIND K
        depth.assign(n + 1, 0);
        parent.assign(n + 1, 0);
        dfs(j, -1);

        int k = max_element(depth.begin(), depth.end()) - depth.begin();

        bool found = false;
        int b = -1, a = -1, c = -1;
        while (true)
        {
            // IF PARENT OF NODE HAS MORE THAN 2 EDGES THEN, ONE IS CURRENT NODE, ONE IS PARENT OF PARENT AND OTHER IS C
            if (adj[parent[k]].size() > 2)
            {
                found = true;
                b = parent[k];
                a = k;
                for (auto nei : adj[parent[k]])
                {
                    if (nei != parent[b] && nei != a)
                    {
                        c = nei;
                        break;
                    }
                }
                break;
            }
            if (parent[k] == k)
                break;
            k = parent[k];
        }
        if (found == 0)
            cout << -1 << endl;
        else
            cout << a << " " << b << " " << c << endl;
    }

    return 0;
}