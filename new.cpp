#include <bits/stdc++.h>
#define int long long
using namespace std;

struct segmenttree
{
    int n;
    vector<int> st, lazy;

    void init(int _n)
    {
        n = _n;
        st.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
    }

    int comb(int a, int b)
    {
        return max(a, b);
    }

    void build(int start, int end, int node, vector<int> &v)
    {
        if (start == end)
        {
            st[node] = v[start];
            return;
        }
        int mid = (start + end) / 2;
        build(start, mid, 2 * node + 1, v);
        build(mid + 1, end, 2 * node + 2, v);
        st[node] = comb(st[2 * node + 1], st[2 * node + 2]);
    }

    void build(vector<int> &v)
    {
        build(0, n - 1, 0, v);
    }

    void push(int start, int end, int node)
    {
        if (lazy[node] != 0)
        {
            st[node] += lazy[node];

            if (start != end)
            { // not a leaf
                lazy[2 * node + 1] += lazy[node];
                lazy[2 * node + 2] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void update(int start, int end, int l, int r, int node, int value)
    {
        push(start, end, node);

        if (start > r || end < l)
            return; // no overlap

        if (start >= l && end <= r)
        {
            lazy[node] += value;
            push(start, end, node);
            return;
        }

        int mid = (start + end) / 2;
        update(start, mid, l, r, 2 * node + 1, value);
        update(mid + 1, end, l, r, 2 * node + 2, value);
        st[node] = comb(st[2 * node + 1], st[2 * node + 2]);
    }

    int query(int start, int end, int l, int r, int node)
    {
        push(start, end, node);

        if (start > r || end < l)
            return LLONG_MIN;

        if (start >= l && end <= r)
            return st[node];

        int mid = (start + end) / 2;
        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, end, l, r, 2 * node + 2);
        return comb(q1, q2);
    }

    // wrappers
    void update(int l, int r, int value)
    {
        update(0, n - 1, l, r, 0, value);
    }

    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
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
        int n, q;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        segmenttree tree;
        tree.init(n);
        tree.build(arr);

        cin >> q;
        while (q--)
        {
            int type;
            cin >> type;
            if (type == 1)
            {
                int l, r, x;
                cin >> l >> r >> x;
                l--, r--;
                tree.update(l, r, x);
            }
            else
            {
                int l, r;
                cin >> l >> r;
                l--, r--;
                cout << tree.query(l, r) << "\n";
            }
        }
    }
    return 0;
}
