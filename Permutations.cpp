#include <bits/stdc++.h>
#define ll int64_t
using namespace std;
struct segmenttree
{
    int n;
    vector<int> st;
    void init(int _n)
    {
        this->n = _n;
        st.resize(4 * n, 0);
    }

    int comb(int a, int b)
    {
        return a + b;
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
    int query(int start, int end, int l, int r, int node)
    {
        if (start > r || end < l)
            return 0;
        if (start >= l && end <= r)
            return st[node];
        int mid = (start + end) / 2;
        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, end, l, r, 2 * node + 2);
        return comb(q1, q2);
    }
    void build(vector<int> &v)
    {
        build(0, n - 1, 0, v);
    }
    int query(int l, int r)
    {
        return query(0, n - 1, l, r, 0);
    }
    void update(int start, int end, int node, int index, int value)
    {
        if (start == end)
        {
            st[node] = value;
        }
        int mid = (start + end) / 2;
        if (index <= mid)
            update(start, mid, 2 * node + 1, index, value);
        else
            update(mid + 1, end, 2 * node + 2, index, value);
        st[node] = comb(st[2 * node + 1], st[2 * node + 2]);
        return;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // segmenttree tree;
    // tree.init(10);
    // tree.build(arr);
    // cout << tree.query(0, 5) << endl;
}
