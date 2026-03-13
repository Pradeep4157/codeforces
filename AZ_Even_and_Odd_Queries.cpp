#include <bits/stdc++.h>
#define int long long
using namespace std;
/*
            OBSERVATIONS

*/
struct Segtree
{
    int n;
    vector<pair<int, int>> dp;
    Segtree(int size)
    {
        n = size;
        dp.resize(4 * n + 10);
    }
    void update(int tree_index, int start, int end, int index, int val)
    {
        if (start == end)
        {
            // this is the index..
            if (val & 1)
            {
                dp[tree_index].second = 1;
                dp[tree_index].first = 0;
            }
            else
            {

                dp[tree_index].first = 1;
                dp[tree_index].second = 0;
            }
            return;
            // process right and left..
        }
        int mid = (start + end) / 2;

        if (index <= mid)
            update(tree_index * 2 + 1, start, mid, index, val);
        else
            update(tree_index * 2 + 2, mid + 1, end, index, val);
        dp[tree_index].first = (dp[tree_index * 2 + 1].first + dp[tree_index * 2 + 2].first);
        dp[tree_index].second = (dp[tree_index * 2 + 1].second + dp[tree_index * 2 + 2].second);
        return;
    }
    pair<int, int> get_sum(int index, int start, int end, int left, int right)
    {
        if (end < left || start > right)
            return {0, 0};
        if (start >= left && end <= right)
        {
            return {dp[index].first, dp[index].second};
        }
        if (start >= end)
            return {0, 0};

        // now we need to find left and right..
        int mid = (start + end) / 2;
        pair<int, int> res = get_sum(2 * index + 1, start, mid, left, right);
        pair<int, int> second = get_sum(2 * index + 2, mid + 1, end, left, right);
        res.first += second.first;
        res.second += second.second;
        return res;
    }
    int get_even_sum(int left, int right)
    {

        pair<int, int> curr = get_sum(0, 0, n - 1, left, right);

        return curr.first;
    }
    int get_odd_sum(int left, int right)
    {
        pair<int, int> curr = get_sum(0, 0, n - 1, left, right);
        return curr.second;
    }
    void update(int index, int val)
    {
        update(0, 0, n - 1, index, val);
    }
};
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n;
    vector<int> arr(n);
    Segtree sg(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < n; i++)
    {
        sg.update(i, arr[i]);
    }
    cin >> q;
    while (q--)
    {
        int type;
        cin >> type;
        if (type == 0)
        {
            int index, val;
            cin >> index >> val;
            index--;
            sg.update(index, val);
        }
        else if (type == 1)
        {
            int left, right;
            cin >> left >> right;
            left--;
            right--;

            // here we even sum..

            int res = sg.get_even_sum(left, right);

            cout << res << endl;
        }
        else
        {
            int left, right;
            cin >> left >> right;
            left--;
            right--;
            int res = sg.get_odd_sum(left, right);
            cout << res << endl;
        }
    }
    return 0;
}
