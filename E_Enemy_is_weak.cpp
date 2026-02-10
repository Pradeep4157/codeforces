#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
        OBSERVATIONS:

    this can be solved using dp + fenwick tree with coordinate compression..

    so we will first solve the problem using ft + coordinate compression..

    then we will understand how does fw + cc work..


*/

// struct Fenwick
// {
//     int n;
//     vector<int> bit;

//     Fenwick(int n) : n(n), bit(n + 1, 0) {}

//     void update(int i, int v)
//     {
//         for (; i <= n; i += i & -i)
//             bit[i] += v;
//     }

//     int query(int i)
//     { // sum [1..i]
//         int s = 0;
//         for (; i > 0; i -= i & -i)
//             s += bit[i];
//         return s;
//     }

//     int rangeQuery(int l, int r)
//     {
//         if (l > r)
//             return 0;
//         return query(r) - query(l - 1);
//     }
// };
// struct Fenwick
// {
//     int n;
//     vector<int> bit;
//     Fenwick(int n) : n(n), bit(n + 1, 0) {}
//     void update(int i, int v)
//     {
//         for (; i <= n; i += (i & -i))
//         {
//             bit[i] += v;
//         }
//     }
//     int query(int i)
//     {
//         int res = 0;
//         for (; i > 0; i -= (i & -i))
//         {
//             res += bit[i];
//         }
//         return res;
//     }
//     int rangeQuery(int l, int r)
//     {
//         if (l > r)
//             return 0;
//         return query(r) - query(l - 1);
//     }
// };
// struct Fenwick
// {
//     int n;
//     vector<int> bit;
//     Fenwick(int n) : n(n), bit(n + 1, 0) {}
//     void update(int i, int v)
//     {
//         for (; i <= n; i += (i & -i))
//         {
//             bit[i] += v;
//         }
//     }
//     int query(int i)
//     {
//         int res = 0;
//         for (; i > 0; i -= (i & -i))
//         {
//             res += bit[i];
//         }
//         return res;
//     }
//     int rangeQuery(int l, int r)
//     {
//         if (l > r)
//             return 0;
//         return query(r) - query(l - 1);
//     }
// };
// struct Fenwick
// {
//     int n;
//     vector<int> bit;
//     Fenwick(int n) : n(n), bit(n + 1, 0) {}
//     void update(int i, int v)
//     {
//         for (; i <= n; i += (i & -i))
//         {
//             bit[i] += v;
//         }
//     }
//     int query(int i)
//     {
//         int res = 0;
//         for (; i > 0; i -= (i & -i))
//         {
//             res += bit[i];
//         }
//         return res;
//     }
//     int rangeQuery(int l, int r)
//     {
//         if (l > r)
//             return 0;
//         return query(r) - query(l - 1);
//     }
// };

// struct Fenwick
// {
//     int n;
//     vector<int> bit;
//     Fenwick(int n) : n(n), bit(n + 1, 0) {}
//     void update(int i, int v)
//     {
//         for (; i <= n; i += (i & -i))
//         {
//             bit[i] += v;
//         }
//     }
//     int query(int i)
//     {
//         int res = 0;
//         for (; i > 0; i -= (i & -i))
//         {
//             res += bit[i];
//         }
//         return res;
//     }
//     int rangeQuery(int l, int r)
//     {
//         if (l > r)
//             return 0;
//         return query(r) - query(l - 1);
//     }
// };

struct Fenwick
{
    int n;
    vector<int> bit;
    Fenwick(int n) : n(n), bit(n + 1, 0) {}
    void update(int i, int v)
    {
        for (; i <= n; i += (i & -i))
        {
            bit[i] += v;
        }
    }
    int query(int i)
    {
        int res = 0;
        for (; i > 0; i -= (i & -i))
        {
            res += bit[i];
        }
        return res;
    }
    int rangeQuery(int l, int r)
    {
        if (l > r)
            return 0;
        return query(r) - query(l - 1);
    }
};

// vector<int> compress(vector<int> &a)
// {
//     vector<int> v = a;
//     sort(v.begin(), v.end());
//     v.erase(unique(v.begin(), v.end()), v.end());

//     vector<int> comp(a.size());
//     for (int i = 0; i < (int)a.size(); i++)
//     {
//         comp[i] = lower_bound(v.begin(), v.end(), a[i]) - v.begin() + 1;
//     }
//     return comp;
// }

// vector<int> compress(vector<int> &arr)
// {
//     vector<int> v = arr;
//     int n = arr.size();
//     sort(v.begin(), v.end());
//     v.erase(unique(v.begin(), v.end()), v.end());
//     vector<int> compress(n);
//     for (int i = 0; i < n; i++)
//     {
//         compress[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin() + 1;
//     }
//     return compress;
// }

// vector<int> compress(vector<int> &arr)
// {
//     vector<int> v = arr;
//     int n = arr.size();
//     sort(v.begin(), v.end());
//     v.erase(unique(v.begin(), v.end()), v.end());
//     vector<int> compress(n);
//     for (int i = 0; i < n; i++)
//     {
//         compress[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin() + 1;
//     }
//     return compress;
// }
// vector<int> compress(vector<int> &arr)
// {
//     int n = arr.size();
//     vector<int> v = arr;
//     sort(v.begin(), v.end());
//     v.erase(unique(v.begin(), v.end()), v.end());
//     vector<int> compress(n);
//     for (int i = 0; i < n; i++)
//     {
//         compress[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin() + 1;
//     }
//     return compress;
// }
// vector<int> compress(vector<int> &arr)
// {
//     int n = arr.size();
//     vector<int> v = arr;
//     sort(v.begin(), v.end());
//     v.erase(unique(v.begin(), v.end()), v.end());
//     vector<int> compress(n);
//     for (int i = 0; i < n; i++)
//     {
//         compress[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin() + 1;
//     }
//     return compress;
// }

vector<int> compress(vector<int> &arr)
{
    int n = arr.size();
    vector<int> v = arr;
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    vector<int> compress(n);
    for (int i = 0; i < n; i++)
    {
        compress[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin() + 1;
    }
    return compress;
}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        vector<int> comp = compress(arr);
        vector<int> left_greater(n), right_smaller(n);
        int maxi = *max_element(comp.begin(), comp.end());
        Fenwick for_left(maxi);
        for (int i = 0; i < n; i++)
        {
            left_greater[i] = for_left.rangeQuery(comp[i] + 1, maxi);
            for_left.update(comp[i], 1);
        }
        Fenwick for_right(maxi);
        for (int i = n - 1; i >= 0; i--)
        {
            right_smaller[i] = for_right.rangeQuery(1, comp[i] - 1);
            for_right.update(comp[i], 1);
        }
        int res = 0;
        for (int i = 0; i < n; i++)
        {
            res += (left_greater[i] * right_smaller[i]);
        }
        cout << res << endl;
    }
    return 0;
}
