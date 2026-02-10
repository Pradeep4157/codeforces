#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


        in n queries i can find out what is the node from which max path comes from..

        then i have n queries left..

        and n - 1 nodes left ..

        now i start from last node..

        and some node will have len - 1 dist if that node is connected to this one and has len

        of len - 1

        then that is a valid path..

        so we need array that stores nodes of a particular length  and then we start from any of the last node..

        and keep iterating till we len  == 0..

        so some nodes are stored in bigger distances..

        we might not get them in smaller distances..

        first trying to find them in the dist array

        if we get them then good

        else we need to find




*/
vector<vector<int>> dist;
int n;
int query_all(int x)
{
    // this will query all the nodes for this node..
    cout << "? " << x << " " << n << " ";
    for (int i = 1; i <= n; i++)
    {

        cout << i << " ";
    }
    cout << endl;
    cout.flush();
    int curr_dist;
    cin >> curr_dist;
    return curr_dist;
}
bool check_is_it(int a, int b)
{
    cout << "? " << a << " " << 2 << " " << a << " " << b << endl;
    cout.flush();
    int curr_dist;
    cin >> curr_dist;
    if (curr_dist > 1)
        return 1;
    else
        return 0;
}
signed main()
{

    int t;
    cin >> t;
    while (t--)
    {

        cin >> n;
        dist.assign(n + 1, {});
        // now store dist of all the nodes..
        int dist_left = 1;
        for (int i = 1; i <= n; i++)
        {
            int curr_dist = query_all(i);
            dist_left = max(dist_left, curr_dist);
            dist[curr_dist].push_back(i);
        }
        vector<int> res;
        // some node i select of this dist..
        res.push_back(dist[dist_left][0]);
        dist_left--;
        while (dist_left)
        {
            // now in this array i find some  node that connects to back of the array..
            int par = res.back();
            for (auto a : dist[dist_left])
            {
                if (check_is_it(par, a))
                {
                    dist_left--;
                    res.push_back(a);
                    break;
                }
            }
        }
        cout << "! " << res.size() << " ";
        for (auto a : res)
            cout << a << " ";
        cout << endl;
    }
    return 0;
}
