#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    so there is some stack they fight better one

    wins and moves above ..

    farmer gives potion to some cow

    and its power becomes ci..

    so its like segment tree

    where nodes among the nodes whichever node

    has higher xor wins and then  we just

    combine xorr them with each other..

    at each level 2^curr_count gets added if the

    current node xorr < right xorr..

    that's it..

*/

struct SegmentTree
{
    int n;
    vector<int> tree;

    SegmentTree(const vector<int> &arr)
    {
        n = arr.size();
        tree.resize(4 * n);
        build(arr, 1, 0, n - 1);
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
            build(arr, 2 * node, l, mid);
            build(arr, 2 * node + 1, mid + 1, r);
            tree[node] = tree[2 * node] ^ tree[2 * node + 1];
        }
    }

    int query(int node, int l, int r, int ql, int qr)
    {
        if (qr < l || ql > r)
            return 0;
        if (ql <= l && r <= qr)
            return tree[node];
        int mid = (l + r) / 2;
        return query(2 * node, l, mid, ql, qr) ^
               query(2 * node + 1, mid + 1, r, ql, qr);
    }

    void update(int node, int l, int r, int idx, int val)
    {
        if (l == r)
        {
            tree[node] = val;
        }
        else
        {
            int mid = (l + r) / 2;
            if (idx <= mid)
                update(2 * node, l, mid, idx, val);
            else
                update(2 * node + 1, mid + 1, r, idx, val);
            tree[node] = tree[2 * node] ^ tree[2 * node + 1];
        }
    }
    int find_node(int node, int l, int r, int index)
    {
        if (l == r)
        {
            return node;
        }
        else
        {
            int mid = (l + r) / 2;
            if (index <= mid)
            {
                return find_node(2 * node, l, mid, index);
            }
            else
            {
                return find_node(2 * node + 1, mid + 1, r, index);
            }
        }
    }
    int sibling(int node)
    {
        if (node % 2 == 0)
            return node + 1;
        else
            return node - 1;
    }
    int parent(int node)
    {
        if (node == 1)
            return -1;
        return node / 2;
    }
    bool isLeftChild(int node)
    {
        if (node == 1)
            return false;
        return (node % 2 == 0);
    }

    int query(int l, int r) { return query(1, 0, n - 1, l, r); }
    int find(int index, int new_val)
    {
        // first i need to find the index where it is stored..
        int node = find_node(1, 0, n - 1, index);

        //  now we have the node..
        // now we need to update and check  if the xorr of the right child is > or not..
        // first we update here..

        tree[node] = new_val;
        int compi = 1;
        int res = 0;
        while (node != -1)
        {
            // there is a sibling..
            if (node == 1)
                break; // no sibling..
            int sibling_node = sibling(node);

            if (tree[sibling_node] > tree[node])
            {

                // then sibling won..

                res += compi;
            }
            else if (tree[sibling_node] == tree[node])
            {
                // if this is left node then only it wins..
                if (isLeftChild(node) == false)
                {
                    // it lost..
                    res += compi;
                }
            }

            compi <<= 1;
            int parent_node = parent(node);
            // now xorr of parent node  = left and right xorr.
            tree[parent_node] = tree[node] ^ tree[sibling_node];
            node = parent_node;
        }
        return res;
    }
    void update(int idx, int val) { update(1, 0, n - 1, idx, val); }
};

long long binpow(long long base, long long exp)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result *= base;
        base *= base;
        exp >>= 1;
    }
    return result;
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        n = binpow(2, n);
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        SegmentTree seg_tree(arr);
        while (q--)
        {
            int b, c;
            cin >> b >> c;
            b--;
            int count = seg_tree.find(b, c);
            cout << count << endl;
            // after we are done we reset the value to earlier val..
            seg_tree.update(b, arr[b]);
        }
    }
    return 0;
}
