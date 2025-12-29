#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    what we will do is that for update we will do the normal updations of segment tree

    but after that every node will have gcd of its left and right subtree that is

    first half of the the current array and second half of the current subarray

    and the leaf nodes will simply have arr[i] as their values

    and for every query we will will do sort of a dfs call on the subarray with which if

    the current subarray is totally outside the intended subarray we will return 0

    else if the subarray is within the the required array and if the gcd of this

    subarray is > 1 return 1 + dfs( leftsubtree ) + dfs( right subtree )



    now the problem with this approach is that the segment tree equally divides the current segement and gives the result  for the 2 segments formed

    that is from  left to  mid , mid + 1 to right

    but the problem is that there are a lot of subarrays from left -> mid + 1, mid + 2 , ... right - 1

    these are the segments that are getting missed by the segment tree  .

    now how do you find these ?

    these can also  be found using BS + segment tree

    where we binary search on mid + 1 to right - 1

        for every mid we check gcd from left to mid using segment tree and if the gcd > 1 :
            we move start = mid + 1
            else end = mid - 1

        that should do the job



*/

struct segmenttree
{
    int n;
    vector<int> st;
    void init(int _n)
    {
        this->n = _n;
        st.resize(4 * n + 10, 1);
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
        st[node] = __gcd(st[2 * node + 1], st[2 * node + 2]);
    }
    int findgcd(int start, int end, int l, int r, int node)
    {
        if (start > r || end < l)
        {
            return 0;
        }
        if (start >= l && end <= r)
        {
            // this is the gcd of the current subarray
            return st[node];
        }
        // there is partial intersection

        int mid = (start + end) / 2;
        int q1 = findgcd(start, mid, l, r, 2 * node + 1);
        int q2 = findgcd(mid + 1, end, l, r, 2 * node + 2);
        return __gcd(q1, q2);
    }
    int query(int start, int end, int l, int r, int node)
    {
        if (start > r || end < l)
            return 0;

        // here the segment is within the limit
        int res = 0;
        if (st[node] > 1)
        {
            res++;
        }
        if (start == end)
        {
            // this is the leaf node and we dont need to  go anywhere else
            return res;
        }
        int mid = (start + end) / 2;
        int q1 = query(start, mid, l, r, 2 * node + 1);
        int q2 = query(mid + 1, end, l, r, 2 * node + 2);

        // now we have left and right subarray now we need from left to  mid + 1, mid + 2 ,.... right - 1  result
        int left = mid + 1, right = r - 1;
        int lastindex = left;
        while (left <= right)
        {
            int midd = (left + right) / 2;
            int currgcd = findgcd(0, n - 1, l, midd, 0);
            if (currgcd > 1)
            {
                // till this mid from left we have gcd > 1
                lastindex = midd;
                left = midd + 1;
            }
            else
                right = midd - 1;
        }
        return res + q1 + q2 + (lastindex - (mid + 1));
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
            return;
        }
        int mid = (start + end) / 2;
        if (index <= mid)
            update(start, mid, 2 * node + 1, index, value);
        else
            update(mid + 1, end, 2 * node + 2, index, value);
        st[node] = __gcd(st[2 * node + 1], st[2 * node + 2]);
        return;
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    segmenttree tree;
    tree.init(n);
    tree.build(arr);
    // tree.update(0, n - 1, 0, 2, 4);
    // cout << "Update done " << endl;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            // cout << "ahahha" << endl;
            int index, value;
            cin >> index >> value;
            index--;
            // cout << index << ":" << value << endl;
            tree.update(0, n - 1, 0, index, value);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            l--, r--;
            // cout << l << "::" << r << endl;
            //  cout << "ahahha" << endl;
            cout << tree.query(l, r) << endl;
        }
    }
    // cout << tree.query(0, 5) << endl;
}
