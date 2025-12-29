#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    we want to make d == a

    so one thing can be noticed that

    i will try to make a[i] equal to some d[index]

    and the cost for that will be

    cyclic shifts that i need to do to reach there

    that is ( index )*c ;

    this is the only rotational cost

    and after this:

    and for every i its' index = (i + rotations)%n

    and now the cost for this i is d[i]*b[index] ?


    the shifts that  i am making are from i to

    some index j and to  minimize the cost

    i could have made a[i] == d[j] using any b[k]

    that is between i and j

*/
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class SegmentTree
{
    vector<int> tree;
    int n;

public:
    SegmentTree(const vector<int> &arr)
    {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 0, 0, n - 1);
    }

    void build(const vector<int> &arr, int node, int l, int r)
    {
        if (l == r)
        {
            tree[node] = arr[l];
        }
        else
        {
            int mid = (l + r) / 2;
            build(arr, 2 * node + 1, l, mid);
            build(arr, 2 * node + 2, mid + 1, r);
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int query(int ql, int qr)
    {
        return queryUtil(0, 0, n - 1, ql, qr);
    }

private:
    int queryUtil(int node, int l, int r, int ql, int qr)
    {
        if (qr < l || ql > r)
            return INT_MAX; // No overlap
        if (ql <= l && r <= qr)
            return tree[node]; // Total overlap
        int mid = (l + r) / 2;
        return min(queryUtil(2 * node + 1, l, mid, ql, qr),
                   queryUtil(2 * node + 2, mid + 1, r, ql, qr));
    }
};

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> b(n), d(n);
        for (int i = 0; i < n; i++)
            cin >> b[i];
        for (int i = 0; i < n; i++)
            cin >> d[i];
        SegmentTree st(b);

        int res = LLONG_MAX;
        for (int shifts = 0; shifts < n; shifts++)
        {
            int curr = shifts * c;
            // cout << curr << ":";
            for (int i = 0; i < n; i++)
            {
                int index = (i + shifts) % n;
                // cout << "->" << index << "||";
                if (index == i)
                {
                    curr += (b[i] * d[index]);
                }
                else if (index > i)
                {
                    int currb = st.query(i, index);
                    curr += (d[index] * currb);
                }
                else
                {
                    int currb = st.query(i, n - 1);
                    currb = min(currb, st.query(0, index));
                    curr += (d[index] * currb);
                }
                // cout << curr << ":";
            }
            // cout << curr << endl;
            res = min(res, curr);
        }
        cout << res << endl;
    }
    return 0;
}
