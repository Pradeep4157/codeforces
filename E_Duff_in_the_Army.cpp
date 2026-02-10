#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so a tree is given..

    we are given v and u and a ..

    from the path from v..u

    we need to return max of a or whatever people i find..

    these people should be in increasing order..

    if not then return 0 ig..

    the basic bf is traverse from v..u

    and find till u either reach u or u find a people in increasing order...

    but this will take q*n algo..

    what we can do is that which parent has some people in it..

    but the thing is that u and v can be in diff branches..

    so we need lca from v to lca and then lca to u...

    is storing the parent of the node that has some person enough ?

    maybe not because like every par  node can have some people

    but it might not be > then child node..

    and becuause of this we might have to traverse 1e5..



*/
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
    }
    return 0;
}
