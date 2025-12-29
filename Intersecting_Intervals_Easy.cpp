#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:


    2 arrays are given..

    f(a,b) :

        choose 2 segments from a,b..

        the 2 segments shoudl intersect..

        score is sum of two segments..

    so i fix the left end and find the best right

    for both a & b ..

    and then brute force for every a what is the best right

    and what is the best sum in then range from l...a[i]..

    same for b..


*/
vector<int> arr, b;
class SegmentTree
{
public:
    struct Node
    {
        long long sum;
        long long bestPref;
        int bestPrefEnd;

        Node()
        {
            sum = 0;
            bestPref = LLONG_MIN;
            bestPrefEnd = -1;
        }
    };

    int n;
    vector<long long> arr;
    vector<Node> seg;

    SegmentTree(int n)
    {
        this->n = n;
        arr.assign(n + 1, 0);
        seg.assign(4 * n, Node());
    }

    Node mergeNode(const Node &L, const Node &R)
    {
        if (L.bestPrefEnd == -1)
            return R;
        if (R.bestPrefEnd == -1)
            return L;

        Node res;
        res.sum = L.sum + R.sum;

        // Change >= to >
        if (L.bestPref > L.sum + R.bestPref)
        {
            res.bestPref = L.bestPref;
            res.bestPrefEnd = L.bestPrefEnd; // closer right
        }
        else
        {
            res.bestPref = L.sum + R.bestPref;
            res.bestPrefEnd = R.bestPrefEnd; // farther right
        }

        return res;
    }

    void build(int idx, int l, int r)
    {
        if (l == r)
        {
            seg[idx].sum = arr[l];
            seg[idx].bestPref = arr[l];
            seg[idx].bestPrefEnd = l;
            return;
        }
        int mid = (l + r) / 2;
        build(idx * 2, l, mid);
        build(idx * 2 + 1, mid + 1, r);
        seg[idx] = mergeNode(seg[idx * 2], seg[idx * 2 + 1]);
    }

    void build()
    {
        build(1, 1, n);
    }

    Node queryUtil(int idx, int l, int r, int L)
    {
        if (r < L)
            return Node(); // empty
        if (l >= L)
            return seg[idx]; // fully inside

        int mid = (l + r) / 2;

        Node leftRes = queryUtil(idx * 2, l, mid, L);
        Node rightRes = queryUtil(idx * 2 + 1, mid + 1, r, L);

        return mergeNode(leftRes, rightRes);
    }

    pair<long long, int> query(int L)
    {
        Node ans = queryUtil(1, 1, n, L);
        return {ans.bestPref, ans.bestPrefEnd};
    }
};
class SegTreeMax
{
public:
    int n;
    vector<long long> seg;

    SegTreeMax(int n)
    {
        this->n = n;
        seg.assign(4 * n, LLONG_MIN);
    }

    void build(vector<long long> &arr, int idx, int l, int r)
    {
        if (l == r)
        {
            seg[idx] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, idx * 2, l, mid);
        build(arr, idx * 2 + 1, mid + 1, r);
        seg[idx] = max(seg[idx * 2], seg[idx * 2 + 1]);
    }

    void build(vector<long long> &arr)
    {
        build(arr, 1, 1, n);
    }

    long long query(int idx, int l, int r, int ql, int qr)
    {
        if (qr < l || r < ql)
            return LLONG_MIN; // no overlap
        if (ql <= l && r <= qr)
            return seg[idx]; // full overlap

        int mid = (l + r) / 2;
        return max(
            query(idx * 2, l, mid, ql, qr),
            query(idx * 2 + 1, mid + 1, r, ql, qr));
    }

    long long query(int l, int r)
    {
        return query(1, 1, n, l, r);
    }

    void update(int idx, int l, int r, int pos, long long val)
    {
        if (l == r)
        {
            seg[idx] = val;
            return;
        }
        int mid = (l + r) / 2;

        if (pos <= mid)
            update(idx * 2, l, mid, pos, val);
        else
            update(idx * 2 + 1, mid + 1, r, pos, val);

        seg[idx] = max(seg[idx * 2], seg[idx * 2 + 1]);
    }

    void update(int pos, long long val)
    {
        update(1, 1, n, pos, val);
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
        int n;
        cin >> n;

        SegmentTree st1(n), st2(n);
        arr.resize(n + 1), b.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> st1.arr[i];
            arr[i] = st1.arr[i];
        }

        for (int i = 1; i <= n; i++)
        {
            cin >> st2.arr[i];
            b[i] = st2.arr[i];
        }

        st1.build();
        st2.build();

        // now we find l for both arr and b..
        SegTreeMax ST1(n), ST2(n);
        vector<pair<int, int>> dp1(n + 1), dp2(n + 1);
        for (int i = 1; i <= n; i++)
        {
            dp1[i] = st1.query(i);
            dp2[i] = st2.query(i);
        }

        vector<int> DP1(n + 1), DP2(n + 1);
        for (int i = 1; i <= n; i++)
        {
            DP1[i] = dp1[i].first;
            DP2[i] = dp2[i].first;
        }

        ST1.build(DP1);

        ST2.build(DP2);

        int res = LLONG_MIN;

        // now it is just BF.
        // first we will check for every left of first array what is the array that
        for (int i = 1; i <= n; i++)
        {
            int left = i;
            int right = dp1[i].second;

            int currsum = dp1[i].first;
            // now we will find best in second array..

            int rem = ST2.query(left, right);

            currsum += rem;
            res = max(res, currsum);
        }
        for (int i = 1; i <= n; i++)
        {
            int left = i;
            int right = dp2[i].second;
            int currsum = dp2[i].first;

            currsum += ST1.query(left, right);
            res = max(res, currsum);
        }
        cout << res << endl;
    }

    return 0;
}
